#ifndef AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_KEY_PURPOSE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_KEY_PURPOSE_H_

#include <array>
#include <cstdint>
#include <string>

namespace keymint {

enum class KeyPurpose : int32_t {
  ENCRYPT = 0,
  DECRYPT = 1,
  SIGN = 2,
  VERIFY = 3,
  WRAP_KEY = 5,
  AGREE_KEY = 6,
  ATTEST_KEY = 7,
};

static inline std::string toString(KeyPurpose val) {
  switch(val) {
  case KeyPurpose::ENCRYPT:
    return "ENCRYPT";
  case KeyPurpose::DECRYPT:
    return "DECRYPT";
  case KeyPurpose::SIGN:
    return "SIGN";
  case KeyPurpose::VERIFY:
    return "VERIFY";
  case KeyPurpose::WRAP_KEY:
    return "WRAP_KEY";
  case KeyPurpose::AGREE_KEY:
    return "AGREE_KEY";
  case KeyPurpose::ATTEST_KEY:
    return "ATTEST_KEY";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymint

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_KEY_PURPOSE_H_
