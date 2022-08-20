#ifndef AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_BLOCK_MODE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_BLOCK_MODE_H_

namespace keymint {

enum class BlockMode : int32_t {
  ECB = 1,
  CBC = 2,
  CTR = 3,
  GCM = 32,
};

static inline std::string toString(BlockMode val) {
  switch(val) {
  case BlockMode::ECB:
    return "ECB";
  case BlockMode::CBC:
    return "CBC";
  case BlockMode::CTR:
    return "CTR";
  case BlockMode::GCM:
    return "GCM";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymint

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_BLOCK_MODE_H_
