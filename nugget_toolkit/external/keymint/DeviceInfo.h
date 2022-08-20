#ifndef AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_DEVICE_INFO_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_DEVICE_INFO_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class DeviceInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo)!=std::tie(rhs.deviceInfo);
  }
  inline bool operator<(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo)<std::tie(rhs.deviceInfo);
  }
  inline bool operator<=(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo)<=std::tie(rhs.deviceInfo);
  }
  inline bool operator==(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo)==std::tie(rhs.deviceInfo);
  }
  inline bool operator>(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo)>std::tie(rhs.deviceInfo);
  }
  inline bool operator>=(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo)>=std::tie(rhs.deviceInfo);
  }
  ::std::vector<uint8_t> deviceInfo;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class DeviceInfo

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_SECURITY_KEYMINT_DEVICE_INFO_H_
