#ifndef _KEYBLOB_UTILS_H
#define _KEYBLOB_UTILS_H

#include <Algorithm.h>
#include <BlockMode.h>
#include <Digest.h>
#include <EcCurve.h>
#include <KeyPurpose.h>
#include <PaddingMode.h>
#include <Tag.h>
#include <app_nugget.h>
#include <nugget/app/keymaster/keymaster.pb.h>
#include <sqlite3.h>

#define KEYSTOREDB_PATH "/data/misc/keystore/persistent.sqlite"

using namespace ::nugget::app;

class KeyblobUtils {
 private:
  sqlite3* db;
  void addParam(keymaster::KeyParameters* params, ::keymaster::Tag tag,
                int64_t data);

 public:
  KeyblobUtils();
  KeyblobUtils(char const* db_name);
  ~KeyblobUtils();
  void fillKeymasterParam(::keymaster::KeyParameters* params,
                          int64_t keymintTag, int64_t data);
  int getKeyParametersFromDB(int64_t keyid, ::keymaster::KeyParameters* params);
  ::keymaster::KeyBlob* getKeyblobFromDB(int64_t keyid);
  int64_t getKeySizeFromDB(int64_t keyid);
  int listStrongboxKeys();
  int leakStrongboxKey(std::string name);
};

inline const std::map<int64_t, int64_t> padding_map = {
    {static_cast<int64_t>(::keymint::PaddingMode::NONE),
     static_cast<int64_t>(::keymaster::PaddingMode::PADDING_NONE)},
    {static_cast<int64_t>(::keymint::PaddingMode::RSA_OAEP),
     static_cast<int64_t>(::keymaster::PaddingMode::PADDING_RSA_OAEP)},
    {static_cast<int64_t>(::keymint::PaddingMode::RSA_PSS),
     static_cast<int64_t>(::keymaster::PaddingMode::PADDING_RSA_PSS)},
    {static_cast<int64_t>(::keymint::PaddingMode::RSA_PKCS1_1_5_ENCRYPT),
     static_cast<int64_t>(
         ::keymaster::PaddingMode::PADDING_RSA_PKCS1_1_5_ENCRYPT)},
    {static_cast<int64_t>(::keymint::PaddingMode::RSA_PKCS1_1_5_SIGN),
     static_cast<int64_t>(
         ::keymaster::PaddingMode::PADDING_RSA_PKCS1_1_5_SIGN)},
    {static_cast<int64_t>(::keymint::PaddingMode::PKCS7),
     static_cast<int64_t>(::keymaster::PaddingMode::PADDING_PKCS7)},
};

inline const std::map<int64_t, int64_t> algorithm_map = {
    {static_cast<int64_t>(::keymint::Algorithm::RSA),
     static_cast<int64_t>(::keymaster::Algorithm::RSA)},
    {static_cast<int64_t>(::keymint::Algorithm::EC),
     static_cast<int64_t>(::keymaster::Algorithm::EC)},
    {static_cast<int64_t>(::keymint::Algorithm::AES),
     static_cast<int64_t>(::keymaster::Algorithm::AES)},
    {static_cast<int64_t>(::keymint::Algorithm::TRIPLE_DES),
     static_cast<int64_t>(::keymaster::Algorithm::DES)},
    {static_cast<int64_t>(::keymint::Algorithm::HMAC),
     static_cast<int64_t>(::keymaster::Algorithm::HMAC)},
};

inline const std::map<int64_t, int64_t> block_mode_map = {
    {static_cast<int64_t>(::keymint::BlockMode::ECB),
     static_cast<int64_t>(::keymaster::BlockMode::ECB)},
    {static_cast<int64_t>(::keymint::BlockMode::CBC),
     static_cast<int64_t>(::keymaster::BlockMode::CBC)},
    {static_cast<int64_t>(::keymint::BlockMode::CTR),
     static_cast<int64_t>(::keymaster::BlockMode::CTR)},
    {static_cast<int64_t>(::keymint::BlockMode::GCM),
     static_cast<int64_t>(::keymaster::BlockMode::GCM)},
};

inline const std::map<int64_t, int64_t> key_purpose_map = {
    {static_cast<int64_t>(::keymint::KeyPurpose::ENCRYPT),
     static_cast<int64_t>(::keymaster::KeyPurpose::ENCRYPT)},
    {static_cast<int64_t>(::keymint::KeyPurpose::DECRYPT),
     static_cast<int64_t>(::keymaster::KeyPurpose::DECRYPT)},
    {static_cast<int64_t>(::keymint::KeyPurpose::SIGN),
     static_cast<int64_t>(::keymaster::KeyPurpose::SIGN)},
    {static_cast<int64_t>(::keymint::KeyPurpose::VERIFY),
     static_cast<int64_t>(::keymaster::KeyPurpose::VERIFY)},
    {static_cast<int64_t>(::keymint::KeyPurpose::WRAP_KEY),
     static_cast<int64_t>(::keymaster::KeyPurpose::WRAP_KEY)},
};

inline const std::map<int64_t, int64_t> digest_map = {
    {static_cast<int64_t>(::keymint::Digest::NONE),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_NONE)},
    {static_cast<int64_t>(::keymint::Digest::MD5),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_MD5)},
    {static_cast<int64_t>(::keymint::Digest::SHA1),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_SHA1)},
    {static_cast<int64_t>(::keymint::Digest::SHA_2_224),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_SHA_2_224)},
    {static_cast<int64_t>(::keymint::Digest::SHA_2_256),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_SHA_2_256)},
    {static_cast<int64_t>(::keymint::Digest::SHA_2_384),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_SHA_2_384)},
    {static_cast<int64_t>(::keymint::Digest::SHA_2_512),
     static_cast<int64_t>(::keymaster::Digest::DIGEST_SHA_2_512)},
};

inline const std::map<int64_t, int64_t> ec_curve_map = {
    {static_cast<int64_t>(::keymint::EcCurve::P_224),
     static_cast<int64_t>(::keymaster::EcCurve::P_224)},
    {static_cast<int64_t>(::keymint::EcCurve::P_256),
     static_cast<int64_t>(::keymaster::EcCurve::P_256)},
    {static_cast<int64_t>(::keymint::EcCurve::P_384),
     static_cast<int64_t>(::keymaster::EcCurve::P_384)},
    {static_cast<int64_t>(::keymint::EcCurve::P_521),
     static_cast<int64_t>(::keymaster::EcCurve::P_521)},
};

inline const std::map<int64_t,
                      std::pair<::keymaster::Tag, std::map<int64_t, int64_t>>>
    keyparameters_map = {
        {static_cast<int64_t>(::keymint::Tag::PADDING),
         std::make_pair(::keymaster::Tag::PADDING, padding_map)},
        {static_cast<int64_t>(::keymint::Tag::ALGORITHM),
         std::make_pair(::keymaster::Tag::ALGORITHM, algorithm_map)},
        {static_cast<int64_t>(::keymint::Tag::KEY_SIZE),
         std::make_pair(::keymaster::Tag::KEY_SIZE,
                        std::map<int64_t, int64_t>())},
        {static_cast<int64_t>(::keymint::Tag::BLOCK_MODE),
         std::make_pair(::keymaster::Tag::BLOCK_MODE, block_mode_map)},
        {static_cast<int64_t>(::keymint::Tag::DIGEST),
         std::make_pair(::keymaster::Tag::DIGEST, digest_map)},
        {static_cast<int64_t>(::keymint::Tag::PURPOSE),
         std::make_pair(::keymaster::Tag::PURPOSE, key_purpose_map)},
        {static_cast<int64_t>(::keymint::Tag::EC_CURVE),
         std::make_pair(::keymaster::Tag::EC_CURVE, ec_curve_map)},
};

#endif  // _KEYBLOB_UTILS_H
