// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nugget/app/keymaster/keymaster_defs.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015005 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto_metadata_getter(int index);
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace nugget {
namespace app {
namespace keymaster {

enum TagType : int {
  TAG_TYPE_INVALID = 0,
  ENUM = 65536,
  ENUM_REP = 131072,
  UINT = 196608,
  UINT_REP = 262144,
  ULONG = 327680,
  DATE = 393216,
  BOOL = 458752,
  BIGNUM_ = 524288,
  BYTES = 589824,
  ULONG_REP = 655360,
  TagType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  TagType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool TagType_IsValid(int value);
constexpr TagType TagType_MIN = TAG_TYPE_INVALID;
constexpr TagType TagType_MAX = ULONG_REP;
constexpr int TagType_ARRAYSIZE = TagType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* TagType_descriptor();
template<typename T>
inline const std::string& TagType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, TagType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function TagType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    TagType_descriptor(), enum_t_value);
}
inline bool TagType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, TagType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<TagType>(
    TagType_descriptor(), name, value);
}
enum Tag : int {
  TAG_INVALID = 0,
  PURPOSE = 131073,
  ALGORITHM = 65538,
  KEY_SIZE = 196611,
  BLOCK_MODE = 131076,
  DIGEST = 131077,
  PADDING = 131078,
  CALLER_NONCE = 458759,
  MIN_MAC_LENGTH = 196616,
  EC_CURVE = 65546,
  RSA_PUBLIC_EXPONENT = 327880,
  INCLUDE_UNIQUE_ID = 458954,
  RSA_OAEP_MGF_DIGEST = 131275,
  BLOB_USAGE_REQUIREMENTS = 65837,
  BOOTLOADER_ONLY = 459054,
  ROLLBACK_RESISTANCE = 459055,
  HARDWARE_TYPE = 65840,
  EARLY_BOOT_ONLY = 459057,
  ACTIVE_DATETIME = 393616,
  ORIGINATION_EXPIRE_DATETIME = 393617,
  USAGE_EXPIRE_DATETIME = 393618,
  MIN_SECONDS_BETWEEN_OPS = 197011,
  MAX_USES_PER_BOOT = 197012,
  USAGE_COUNT_LIMIT = 197013,
  USER_ID = 197109,
  USER_SECURE_ID = 655862,
  NO_AUTH_REQUIRED = 459255,
  USER_AUTH_TYPE = 66040,
  AUTH_TIMEOUT = 197113,
  ALLOW_WHILE_ON_BODY = 459258,
  TRUSTED_USER_PRESENCE_REQUIRED = 459259,
  TRUSTED_CONFIRMATION_REQUIRED = 459260,
  UNLOCKED_DEVICE_REQUIRED = 459261,
  APPLICATION_ID = 590425,
  APPLICATION_DATA = 590524,
  CREATION_DATETIME = 393917,
  ORIGIN = 66238,
  ROOT_OF_TRUST = 590528,
  OS_VERSION = 197313,
  OS_PATCHLEVEL = 197314,
  UNIQUE_ID = 590531,
  ATTESTATION_CHALLENGE = 590532,
  ATTESTATION_APPLICATION_ID = 590533,
  ATTESTATION_ID_BRAND = 590534,
  ATTESTATION_ID_DEVICE = 590535,
  ATTESTATION_ID_PRODUCT = 590536,
  ATTESTATION_ID_SERIAL = 590537,
  ATTESTATION_ID_IMEI = 590538,
  ATTESTATION_ID_MEID = 590539,
  ATTESTATION_ID_MANUFACTURER = 590540,
  ATTESTATION_ID_MODEL = 590541,
  VENDOR_PATCHLEVEL = 197326,
  BOOT_PATCHLEVEL = 197327,
  DEVICE_UNIQUE_ATTESTATION = 459472,
  IDENTITY_CREDENTIAL_KEY = 459473,
  STORAGE_KEY = 459474,
  ASSOCIATED_DATA = 590824,
  NONCE = 590825,
  MAC_LENGTH = 197611,
  RESET_SINCE_ID_ROTATION = 459756,
  CONFIRMATION_TOKEN = 590829,
  CERTIFICATE_SERIAL = 525294,
  CERTIFICATE_SUBJECT = 590831,
  Tag_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Tag_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Tag_IsValid(int value);
constexpr Tag Tag_MIN = TAG_INVALID;
constexpr Tag Tag_MAX = USER_SECURE_ID;
constexpr int Tag_ARRAYSIZE = Tag_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Tag_descriptor();
template<typename T>
inline const std::string& Tag_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Tag>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Tag_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Tag_descriptor(), enum_t_value);
}
inline bool Tag_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Tag* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Tag>(
    Tag_descriptor(), name, value);
}
enum Algorithm : int {
  RSA = 0,
  EC = 1,
  AES = 2,
  DES = 3,
  HMAC = 4,
  ALGORITHM_MAX = 5,
  Algorithm_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Algorithm_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Algorithm_IsValid(int value);
constexpr Algorithm Algorithm_MIN = RSA;
constexpr Algorithm Algorithm_MAX = ALGORITHM_MAX;
constexpr int Algorithm_ARRAYSIZE = Algorithm_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Algorithm_descriptor();
template<typename T>
inline const std::string& Algorithm_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Algorithm>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Algorithm_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Algorithm_descriptor(), enum_t_value);
}
inline bool Algorithm_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Algorithm* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Algorithm>(
    Algorithm_descriptor(), name, value);
}
enum BlockMode : int {
  ECB = 0,
  CBC = 1,
  CTR = 2,
  GCM = 3,
  BLOCK_MODE_MAX = 4,
  BlockMode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  BlockMode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool BlockMode_IsValid(int value);
constexpr BlockMode BlockMode_MIN = ECB;
constexpr BlockMode BlockMode_MAX = BLOCK_MODE_MAX;
constexpr int BlockMode_ARRAYSIZE = BlockMode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BlockMode_descriptor();
template<typename T>
inline const std::string& BlockMode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BlockMode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BlockMode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    BlockMode_descriptor(), enum_t_value);
}
inline bool BlockMode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BlockMode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<BlockMode>(
    BlockMode_descriptor(), name, value);
}
enum PaddingMode : int {
  PADDING_NONE = 0,
  PADDING_RSA_OAEP = 1,
  PADDING_RSA_PSS = 2,
  PADDING_RSA_PKCS1_1_5_ENCRYPT = 3,
  PADDING_RSA_PKCS1_1_5_SIGN = 4,
  PADDING_PKCS7 = 5,
  PADDING_MODE_MAX = 6,
  PaddingMode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  PaddingMode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool PaddingMode_IsValid(int value);
constexpr PaddingMode PaddingMode_MIN = PADDING_NONE;
constexpr PaddingMode PaddingMode_MAX = PADDING_MODE_MAX;
constexpr int PaddingMode_ARRAYSIZE = PaddingMode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PaddingMode_descriptor();
template<typename T>
inline const std::string& PaddingMode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PaddingMode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PaddingMode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PaddingMode_descriptor(), enum_t_value);
}
inline bool PaddingMode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PaddingMode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PaddingMode>(
    PaddingMode_descriptor(), name, value);
}
enum Digest : int {
  DIGEST_NONE = 0,
  DIGEST_MD5 = 1,
  DIGEST_SHA1 = 2,
  DIGEST_SHA_2_224 = 3,
  DIGEST_SHA_2_256 = 4,
  DIGEST_SHA_2_384 = 5,
  DIGEST_SHA_2_512 = 6,
  DIGEST_MAX = 7,
  Digest_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Digest_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Digest_IsValid(int value);
constexpr Digest Digest_MIN = DIGEST_NONE;
constexpr Digest Digest_MAX = DIGEST_MAX;
constexpr int Digest_ARRAYSIZE = Digest_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Digest_descriptor();
template<typename T>
inline const std::string& Digest_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Digest>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Digest_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Digest_descriptor(), enum_t_value);
}
inline bool Digest_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Digest* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Digest>(
    Digest_descriptor(), name, value);
}
enum EcCurve : int {
  P_224 = 0,
  P_256 = 1,
  P_384 = 2,
  P_521 = 3,
  EC_CURVE_MAX = 4,
  EcCurve_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  EcCurve_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool EcCurve_IsValid(int value);
constexpr EcCurve EcCurve_MIN = P_224;
constexpr EcCurve EcCurve_MAX = EC_CURVE_MAX;
constexpr int EcCurve_ARRAYSIZE = EcCurve_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EcCurve_descriptor();
template<typename T>
inline const std::string& EcCurve_Name(T enum_t_value) {
  static_assert(::std::is_same<T, EcCurve>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function EcCurve_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    EcCurve_descriptor(), enum_t_value);
}
inline bool EcCurve_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, EcCurve* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<EcCurve>(
    EcCurve_descriptor(), name, value);
}
enum KeyOrigin : int {
  GENERATED = 0,
  DERIVED = 1,
  IMPORTED = 2,
  UNKNOWN = 3,
  SECURELY_IMPORTED = 4,
  KEY_ORIGIN_MAX = 5,
  KeyOrigin_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  KeyOrigin_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool KeyOrigin_IsValid(int value);
constexpr KeyOrigin KeyOrigin_MIN = GENERATED;
constexpr KeyOrigin KeyOrigin_MAX = KEY_ORIGIN_MAX;
constexpr int KeyOrigin_ARRAYSIZE = KeyOrigin_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyOrigin_descriptor();
template<typename T>
inline const std::string& KeyOrigin_Name(T enum_t_value) {
  static_assert(::std::is_same<T, KeyOrigin>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function KeyOrigin_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    KeyOrigin_descriptor(), enum_t_value);
}
inline bool KeyOrigin_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, KeyOrigin* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<KeyOrigin>(
    KeyOrigin_descriptor(), name, value);
}
enum KeyBlobUsageRequirements : int {
  STANDALONE = 0,
  REQUIRES_FILE_SYSTEM = 1,
  KEY_USAGE_MAX = 2,
  KeyBlobUsageRequirements_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  KeyBlobUsageRequirements_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool KeyBlobUsageRequirements_IsValid(int value);
constexpr KeyBlobUsageRequirements KeyBlobUsageRequirements_MIN = STANDALONE;
constexpr KeyBlobUsageRequirements KeyBlobUsageRequirements_MAX = KEY_USAGE_MAX;
constexpr int KeyBlobUsageRequirements_ARRAYSIZE = KeyBlobUsageRequirements_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyBlobUsageRequirements_descriptor();
template<typename T>
inline const std::string& KeyBlobUsageRequirements_Name(T enum_t_value) {
  static_assert(::std::is_same<T, KeyBlobUsageRequirements>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function KeyBlobUsageRequirements_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    KeyBlobUsageRequirements_descriptor(), enum_t_value);
}
inline bool KeyBlobUsageRequirements_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, KeyBlobUsageRequirements* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<KeyBlobUsageRequirements>(
    KeyBlobUsageRequirements_descriptor(), name, value);
}
enum KeyPurpose : int {
  ENCRYPT = 0,
  DECRYPT = 1,
  SIGN = 2,
  VERIFY = 3,
  WRAP_KEY = 5,
  AGREE_KEY = 6,
  ATTEST_KEY = 7,
  PURPOSE_MAX = 8,
  KeyPurpose_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  KeyPurpose_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool KeyPurpose_IsValid(int value);
constexpr KeyPurpose KeyPurpose_MIN = ENCRYPT;
constexpr KeyPurpose KeyPurpose_MAX = PURPOSE_MAX;
constexpr int KeyPurpose_ARRAYSIZE = KeyPurpose_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyPurpose_descriptor();
template<typename T>
inline const std::string& KeyPurpose_Name(T enum_t_value) {
  static_assert(::std::is_same<T, KeyPurpose>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function KeyPurpose_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    KeyPurpose_descriptor(), enum_t_value);
}
inline bool KeyPurpose_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, KeyPurpose* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<KeyPurpose>(
    KeyPurpose_descriptor(), name, value);
}
enum ErrorCode : int {
  OK = 0,
  ROOT_OF_TRUST_ALREADY_SET = 1,
  UNSUPPORTED_PURPOSE = 2,
  INCOMPATIBLE_PURPOSE = 3,
  UNSUPPORTED_ALGORITHM = 4,
  INCOMPATIBLE_ALGORITHM = 5,
  UNSUPPORTED_KEY_SIZE = 6,
  UNSUPPORTED_BLOCK_MODE = 7,
  INCOMPATIBLE_BLOCK_MODE = 8,
  UNSUPPORTED_MAC_LENGTH = 9,
  UNSUPPORTED_PADDING_MODE = 10,
  INCOMPATIBLE_PADDING_MODE = 11,
  UNSUPPORTED_DIGEST = 12,
  INCOMPATIBLE_DIGEST = 13,
  INVALID_EXPIRATION_TIME = 14,
  INVALID_USER_ID = 15,
  INVALID_AUTHORIZATION_TIMEOUT = 16,
  UNSUPPORTED_KEY_FORMAT = 17,
  INCOMPATIBLE_KEY_FORMAT = 18,
  UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM = 19,
  UNSUPPORTED_KEY_VERIFICATION_ALGORITHM = 20,
  INVALID_INPUT_LENGTH = 21,
  KEY_EXPORT_OPTIONS_INVALID = 22,
  DELEGATION_NOT_ALLOWED = 23,
  KEY_NOT_YET_VALID = 24,
  KEY_EXPIRED = 25,
  KEY_USER_NOT_AUTHENTICATED = 26,
  OUTPUT_PARAMETER_NULL = 27,
  INVALID_OPERATION_HANDLE = 28,
  INSUFFICIENT_BUFFER_SPACE = 29,
  VERIFICATION_FAILED = 30,
  TOO_MANY_OPERATIONS = 31,
  UNEXPECTED_NULL_POINTER = 32,
  INVALID_KEY_BLOB = 33,
  IMPORTED_KEY_NOT_ENCRYPTED = 34,
  IMPORTED_KEY_DECRYPTION_FAILED = 35,
  IMPORTED_KEY_NOT_SIGNED = 36,
  IMPORTED_KEY_VERIFICATION_FAILED = 37,
  INVALID_ARGUMENT = 38,
  UNSUPPORTED_TAG = 39,
  INVALID_TAG = 40,
  MEMORY_ALLOCATION_FAILED = 41,
  IMPORT_PARAMETER_MISMATCH = 42,
  SECURE_HW_ACCESS_DENIED = 43,
  OPERATION_CANCELLED = 44,
  CONCURRENT_ACCESS_CONFLICT = 45,
  SECURE_HW_BUSY = 46,
  SECURE_HW_COMMUNICATION_FAILED = 47,
  UNSUPPORTED_EC_FIELD = 48,
  MISSING_NONCE = 49,
  INVALID_NONCE = 50,
  MISSING_MAC_LENGTH = 51,
  KEY_RATE_LIMIT_EXCEEDED = 52,
  CALLER_NONCE_PROHIBITED = 53,
  KEY_MAX_OPS_EXCEEDED = 54,
  INVALID_MAC_LENGTH = 55,
  MISSING_MIN_MAC_LENGTH = 56,
  UNSUPPORTED_MIN_MAC_LENGTH = 57,
  UNSUPPORTED_KDF = 58,
  UNSUPPORTED_EC_CURVE = 59,
  KEY_REQUIRES_UPGRADE = 60,
  ATTESTATION_CHALLENGE_MISSING = 61,
  KEYMASTER_NOT_CONFIGURED = 62,
  ATTESTATION_APPLICATION_ID_MISSING = 63,
  CANNOT_ATTEST_IDS = 64,
  UNIMPLEMENTED = 65,
  VERSION_MISMATCH = 66,
  ROLLBACK_RESISTANCE_UNAVAILABLE = 67,
  HARDWARE_TYPE_UNAVAILABLE = 68,
  PROOF_OF_PRESENCE_REQUIRED = 69,
  CONCURRENT_PROOF_OF_PRESENCE_REQUESTED = 70,
  UNKNOWN_ERROR = 71,
  INVALID_DEVICE_IDS = 72,
  PRODUCTION_MODE_PROVISIONING = 73,
  NO_USER_CONFIRMATION = 74,
  KEY_UPGRADE_NOT_REQUIRED = 75,
  DEVICE_LOCKED = 76,
  EARLY_BOOT_ENDED = 77,
  ATTESTATION_KEYS_NOT_PROVISIONED = 78,
  ATTESTATION_IDS_NOT_PROVISIONED = 79,
  INVALID_OPERATION = 80,
  STORAGE_KEY_UNSUPPORTED = 81,
  INCOMPATIBLE_MGF_DIGEST = 82,
  UNSUPPORTED_MGF_DIGEST = 83,
  ErrorCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ErrorCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ErrorCode_IsValid(int value);
constexpr ErrorCode ErrorCode_MIN = OK;
constexpr ErrorCode ErrorCode_MAX = UNSUPPORTED_MGF_DIGEST;
constexpr int ErrorCode_ARRAYSIZE = ErrorCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ErrorCode_descriptor();
template<typename T>
inline const std::string& ErrorCode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ErrorCode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ErrorCode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ErrorCode_descriptor(), enum_t_value);
}
inline bool ErrorCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ErrorCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ErrorCode>(
    ErrorCode_descriptor(), name, value);
}
enum SecurityLevel : int {
  SOFTWARE = 0,
  TRUSTED_ENVIRONMENT = 1,
  STRONGBOX = 2,
  SecurityLevel_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  SecurityLevel_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool SecurityLevel_IsValid(int value);
constexpr SecurityLevel SecurityLevel_MIN = SOFTWARE;
constexpr SecurityLevel SecurityLevel_MAX = STRONGBOX;
constexpr int SecurityLevel_ARRAYSIZE = SecurityLevel_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SecurityLevel_descriptor();
template<typename T>
inline const std::string& SecurityLevel_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SecurityLevel>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SecurityLevel_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    SecurityLevel_descriptor(), enum_t_value);
}
inline bool SecurityLevel_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, SecurityLevel* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<SecurityLevel>(
    SecurityLevel_descriptor(), name, value);
}
enum HardwareAuthenticatorType : int {
  HW_AUTH_NONE = 0,
  HW_AUTH_PASSWORD = 1,
  HW_AUTH_FINGERPRINT = 2,
  HardwareAuthenticatorType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  HardwareAuthenticatorType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool HardwareAuthenticatorType_IsValid(int value);
constexpr HardwareAuthenticatorType HardwareAuthenticatorType_MIN = HW_AUTH_NONE;
constexpr HardwareAuthenticatorType HardwareAuthenticatorType_MAX = HW_AUTH_FINGERPRINT;
constexpr int HardwareAuthenticatorType_ARRAYSIZE = HardwareAuthenticatorType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* HardwareAuthenticatorType_descriptor();
template<typename T>
inline const std::string& HardwareAuthenticatorType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, HardwareAuthenticatorType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function HardwareAuthenticatorType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    HardwareAuthenticatorType_descriptor(), enum_t_value);
}
inline bool HardwareAuthenticatorType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, HardwareAuthenticatorType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<HardwareAuthenticatorType>(
    HardwareAuthenticatorType_descriptor(), name, value);
}
enum KeyFormat : int {
  X509 = 0,
  PKCS8 = 1,
  RAW = 3,
  KeyFormat_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  KeyFormat_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool KeyFormat_IsValid(int value);
constexpr KeyFormat KeyFormat_MIN = X509;
constexpr KeyFormat KeyFormat_MAX = RAW;
constexpr int KeyFormat_ARRAYSIZE = KeyFormat_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyFormat_descriptor();
template<typename T>
inline const std::string& KeyFormat_Name(T enum_t_value) {
  static_assert(::std::is_same<T, KeyFormat>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function KeyFormat_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    KeyFormat_descriptor(), enum_t_value);
}
inline bool KeyFormat_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, KeyFormat* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<KeyFormat>(
    KeyFormat_descriptor(), name, value);
}
enum DTupError : int {
  DTUP_OK = 0,
  DTUP_NO_EVENT = 1,
  DTupError_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  DTupError_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool DTupError_IsValid(int value);
constexpr DTupError DTupError_MIN = DTUP_OK;
constexpr DTupError DTupError_MAX = DTUP_NO_EVENT;
constexpr int DTupError_ARRAYSIZE = DTupError_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DTupError_descriptor();
template<typename T>
inline const std::string& DTupError_Name(T enum_t_value) {
  static_assert(::std::is_same<T, DTupError>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function DTupError_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    DTupError_descriptor(), enum_t_value);
}
inline bool DTupError_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, DTupError* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<DTupError>(
    DTupError_descriptor(), name, value);
}
enum DTupKeyEvent : int {
  DTUP_RESERVED = 0,
  DTUP_VOL_DOWN = 114,
  DTUP_VOL_UP = 115,
  DTUP_PWR = 116,
  DTupKeyEvent_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  DTupKeyEvent_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool DTupKeyEvent_IsValid(int value);
constexpr DTupKeyEvent DTupKeyEvent_MIN = DTUP_RESERVED;
constexpr DTupKeyEvent DTupKeyEvent_MAX = DTUP_PWR;
constexpr int DTupKeyEvent_ARRAYSIZE = DTupKeyEvent_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DTupKeyEvent_descriptor();
template<typename T>
inline const std::string& DTupKeyEvent_Name(T enum_t_value) {
  static_assert(::std::is_same<T, DTupKeyEvent>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function DTupKeyEvent_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    DTupKeyEvent_descriptor(), enum_t_value);
}
inline bool DTupKeyEvent_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, DTupKeyEvent* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<DTupKeyEvent>(
    DTupKeyEvent_descriptor(), name, value);
}
enum BootColor : int {
  BOOT_VERIFIED_GREEN = 0,
  BOOT_SELFSIGNED_YELLOW = 1,
  BOOT_UNVERIFIED_ORANGE = 2,
  BOOT_VERIFY_FAILED_RED = 3,
  BootColor_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  BootColor_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool BootColor_IsValid(int value);
constexpr BootColor BootColor_MIN = BOOT_VERIFIED_GREEN;
constexpr BootColor BootColor_MAX = BOOT_VERIFY_FAILED_RED;
constexpr int BootColor_ARRAYSIZE = BootColor_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BootColor_descriptor();
template<typename T>
inline const std::string& BootColor_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BootColor>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BootColor_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    BootColor_descriptor(), enum_t_value);
}
inline bool BootColor_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BootColor* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<BootColor>(
    BootColor_descriptor(), name, value);
}
enum ChipFusing : int {
  FUSING_PROTO = 0,
  FUSING_DVT = 1,
  FUSING_PVT = 2,
  FUSING_PVT_1 = 3,
  FUSING_D_PVT = 4,
  FUSING_D_PVT_1 = 5,
  ChipFusing_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ChipFusing_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ChipFusing_IsValid(int value);
constexpr ChipFusing ChipFusing_MIN = FUSING_PROTO;
constexpr ChipFusing ChipFusing_MAX = FUSING_D_PVT_1;
constexpr int ChipFusing_ARRAYSIZE = ChipFusing_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ChipFusing_descriptor();
template<typename T>
inline const std::string& ChipFusing_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ChipFusing>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ChipFusing_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ChipFusing_descriptor(), enum_t_value);
}
inline bool ChipFusing_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ChipFusing* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ChipFusing>(
    ChipFusing_descriptor(), name, value);
}
enum CertificateStatus : int {
  CERT_PREVIOUSLY_PROVISIONED = 0,
  CERT_MISSING = 1,
  CERT_CHECKSUM = 2,
  CERT_UNKNOWN_ERROR = 3,
  CERT_WRONG_PACKET = 4,
  CertificateStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  CertificateStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool CertificateStatus_IsValid(int value);
constexpr CertificateStatus CertificateStatus_MIN = CERT_PREVIOUSLY_PROVISIONED;
constexpr CertificateStatus CertificateStatus_MAX = CERT_WRONG_PACKET;
constexpr int CertificateStatus_ARRAYSIZE = CertificateStatus_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CertificateStatus_descriptor();
template<typename T>
inline const std::string& CertificateStatus_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CertificateStatus>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CertificateStatus_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    CertificateStatus_descriptor(), enum_t_value);
}
inline bool CertificateStatus_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CertificateStatus* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CertificateStatus>(
    CertificateStatus_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace keymaster
}  // namespace app
}  // namespace nugget

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::nugget::app::keymaster::TagType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::TagType>() {
  return ::nugget::app::keymaster::TagType_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::Tag> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::Tag>() {
  return ::nugget::app::keymaster::Tag_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::Algorithm> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::Algorithm>() {
  return ::nugget::app::keymaster::Algorithm_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::BlockMode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::BlockMode>() {
  return ::nugget::app::keymaster::BlockMode_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::PaddingMode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::PaddingMode>() {
  return ::nugget::app::keymaster::PaddingMode_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::Digest> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::Digest>() {
  return ::nugget::app::keymaster::Digest_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::EcCurve> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::EcCurve>() {
  return ::nugget::app::keymaster::EcCurve_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::KeyOrigin> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::KeyOrigin>() {
  return ::nugget::app::keymaster::KeyOrigin_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::KeyBlobUsageRequirements> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::KeyBlobUsageRequirements>() {
  return ::nugget::app::keymaster::KeyBlobUsageRequirements_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::KeyPurpose> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::KeyPurpose>() {
  return ::nugget::app::keymaster::KeyPurpose_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::ErrorCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::ErrorCode>() {
  return ::nugget::app::keymaster::ErrorCode_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::SecurityLevel> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::SecurityLevel>() {
  return ::nugget::app::keymaster::SecurityLevel_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::HardwareAuthenticatorType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::HardwareAuthenticatorType>() {
  return ::nugget::app::keymaster::HardwareAuthenticatorType_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::KeyFormat> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::KeyFormat>() {
  return ::nugget::app::keymaster::KeyFormat_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::DTupError> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::DTupError>() {
  return ::nugget::app::keymaster::DTupError_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::DTupKeyEvent> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::DTupKeyEvent>() {
  return ::nugget::app::keymaster::DTupKeyEvent_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::BootColor> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::BootColor>() {
  return ::nugget::app::keymaster::BootColor_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::ChipFusing> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::ChipFusing>() {
  return ::nugget::app::keymaster::ChipFusing_descriptor();
}
template <> struct is_proto_enum< ::nugget::app::keymaster::CertificateStatus> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nugget::app::keymaster::CertificateStatus>() {
  return ::nugget::app::keymaster::CertificateStatus_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto
