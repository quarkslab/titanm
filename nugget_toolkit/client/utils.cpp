#include "utils.h"

#include <nos/NuggetClient.h>
#include <nos/device.h>
#include <nostypes.h>
#include <nugget/app/avb/avb.pb.h>
#include <stdio.h>

#include <fstream>
#include <vector>

using namespace nostypes;
using nos::NuggetClient;

void print_vector(const std::vector<uint8_t> v) {
  for (const auto x : v) printf("%02x ", x);
  printf("\n");
}

uint32_t reset() {
  NuggetClient client(CITADEL_DEV);
  client.Open();

  const nos_device& device = *client.Device();
  device.ops.reset(device.ctx);

  client.Close();
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

  nugget::app::keymaster::GenerateKeyRequest* request =
      new nugget::app::keymaster::GenerateKeyRequest();
  nugget::app::keymaster::KeyParameters* params =
      new nugget::app::keymaster::KeyParameters();

  nugget::app::keymaster::KeyParameter* keysize_param = params->add_params();
  keysize_param->set_tag(nugget::app::keymaster::KEY_SIZE);
  keysize_param->set_integer(128);

  nugget::app::keymaster::KeyParameter* algo_param = params->add_params();
  algo_param->set_tag(nugget::app::keymaster::ALGORITHM);
  algo_param->set_integer(2);

  nugget::app::keymaster::KeyParameter* mode_param = params->add_params();
  mode_param->set_tag(nugget::app::keymaster::BLOCK_MODE);
  mode_param->set_integer(1);

  nugget::app::keymaster::KeyParameter* keyuse_param = params->add_params();
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
  nugget::app::keymaster::GenerateKeyResponse* response =
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