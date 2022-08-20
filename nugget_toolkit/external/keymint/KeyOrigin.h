#ifndef AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_KEY_ORIGIN_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_KEY_ORIGIN_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class KeyOrigin : int32_t {
  GENERATED = 0,
  DERIVED = 1,
  IMPORTED = 2,
  RESERVED = 3,
  SECURELY_IMPORTED = 4,
};

static inline std::string toString(KeyOrigin val) {
  switch(val) {
  case KeyOrigin::GENERATED:
    return "GENERATED";
  case KeyOrigin::DERIVED:
    return "DERIVED";
  case KeyOrigin::IMPORTED:
    return "IMPORTED";
  case KeyOrigin::RESERVED:
    return "RESERVED";
  case KeyOrigin::SECURELY_IMPORTED:
    return "SECURELY_IMPORTED";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::security::keymint::KeyOrigin, 5> enum_values<::android::hardware::security::keymint::KeyOrigin> = {
  ::android::hardware::security::keymint::KeyOrigin::GENERATED,
  ::android::hardware::security::keymint::KeyOrigin::DERIVED,
  ::android::hardware::security::keymint::KeyOrigin::IMPORTED,
  ::android::hardware::security::keymint::KeyOrigin::RESERVED,
  ::android::hardware::security::keymint::KeyOrigin::SECURELY_IMPORTED,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_KEY_ORIGIN_H_
