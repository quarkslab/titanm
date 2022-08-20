#ifndef AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_DIGEST_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_DIGEST_H_

#include <array>
#include <cstdint>
#include <string>

namespace keymint {

enum class Digest : int32_t {
  NONE = 0,
  MD5 = 1,
  SHA1 = 2,
  SHA_2_224 = 3,
  SHA_2_256 = 4,
  SHA_2_384 = 5,
  SHA_2_512 = 6,
};

static inline std::string toString(Digest val) {
  switch(val) {
  case Digest::NONE:
    return "NONE";
  case Digest::MD5:
    return "MD5";
  case Digest::SHA1:
    return "SHA1";
  case Digest::SHA_2_224:
    return "SHA_2_224";
  case Digest::SHA_2_256:
    return "SHA_2_256";
  case Digest::SHA_2_384:
    return "SHA_2_384";
  case Digest::SHA_2_512:
    return "SHA_2_512";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymint

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_DIGEST_H_
