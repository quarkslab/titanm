// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nugget/app/keymaster/keymaster_defs.proto

#include "nugget/app/keymaster/keymaster_defs.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace nugget {
namespace app {
namespace keymaster {
}  // namespace keymaster
}  // namespace app
}  // namespace nugget
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[19];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n)nugget/app/keymaster/keymaster_defs.pr"
  "oto\022\024nugget.app.keymaster*\251\001\n\007TagType\022\024\n"
  "\020TAG_TYPE_INVALID\020\000\022\n\n\004ENUM\020\200\200\004\022\016\n\010ENUM_"
  "REP\020\200\200\010\022\n\n\004UINT\020\200\200\014\022\016\n\010UINT_REP\020\200\200\020\022\013\n\005U"
  "LONG\020\200\200\024\022\n\n\004DATE\020\200\200\030\022\n\n\004BOOL\020\200\200\034\022\r\n\007BIGN"
  "UM_\020\200\200 \022\013\n\005BYTES\020\200\200$\022\017\n\tULONG_REP\020\200\200(*\201\014"
  "\n\003Tag\022\017\n\013TAG_INVALID\020\000\022\r\n\007PURPOSE\020\201\200\010\022\017\n"
  "\tALGORITHM\020\202\200\004\022\016\n\010KEY_SIZE\020\203\200\014\022\020\n\nBLOCK_"
  "MODE\020\204\200\010\022\014\n\006DIGEST\020\205\200\010\022\r\n\007PADDING\020\206\200\010\022\022\n"
  "\014CALLER_NONCE\020\207\200\034\022\024\n\016MIN_MAC_LENGTH\020\210\200\014\022"
  "\016\n\010EC_CURVE\020\212\200\004\022\031\n\023RSA_PUBLIC_EXPONENT\020\310"
  "\201\024\022\027\n\021INCLUDE_UNIQUE_ID\020\312\201\034\022\031\n\023RSA_OAEP_"
  "MGF_DIGEST\020\313\201\010\022\035\n\027BLOB_USAGE_REQUIREMENT"
  "S\020\255\202\004\022\025\n\017BOOTLOADER_ONLY\020\256\202\034\022\031\n\023ROLLBACK"
  "_RESISTANCE\020\257\202\034\022\023\n\rHARDWARE_TYPE\020\260\202\004\022\025\n\017"
  "EARLY_BOOT_ONLY\020\261\202\034\022\025\n\017ACTIVE_DATETIME\020\220"
  "\203\030\022!\n\033ORIGINATION_EXPIRE_DATETIME\020\221\203\030\022\033\n"
  "\025USAGE_EXPIRE_DATETIME\020\222\203\030\022\035\n\027MIN_SECOND"
  "S_BETWEEN_OPS\020\223\203\014\022\027\n\021MAX_USES_PER_BOOT\020\224"
  "\203\014\022\027\n\021USAGE_COUNT_LIMIT\020\225\203\014\022\r\n\007USER_ID\020\365"
  "\203\014\022\024\n\016USER_SECURE_ID\020\366\203(\022\026\n\020NO_AUTH_REQU"
  "IRED\020\367\203\034\022\024\n\016USER_AUTH_TYPE\020\370\203\004\022\022\n\014AUTH_T"
  "IMEOUT\020\371\203\014\022\031\n\023ALLOW_WHILE_ON_BODY\020\372\203\034\022$\n"
  "\036TRUSTED_USER_PRESENCE_REQUIRED\020\373\203\034\022#\n\035T"
  "RUSTED_CONFIRMATION_REQUIRED\020\374\203\034\022\036\n\030UNLO"
  "CKED_DEVICE_REQUIRED\020\375\203\034\022\024\n\016APPLICATION_"
  "ID\020\331\204$\022\026\n\020APPLICATION_DATA\020\274\205$\022\027\n\021CREATI"
  "ON_DATETIME\020\275\205\030\022\014\n\006ORIGIN\020\276\205\004\022\023\n\rROOT_OF"
  "_TRUST\020\300\205$\022\020\n\nOS_VERSION\020\301\205\014\022\023\n\rOS_PATCH"
  "LEVEL\020\302\205\014\022\017\n\tUNIQUE_ID\020\303\205$\022\033\n\025ATTESTATIO"
  "N_CHALLENGE\020\304\205$\022 \n\032ATTESTATION_APPLICATI"
  "ON_ID\020\305\205$\022\032\n\024ATTESTATION_ID_BRAND\020\306\205$\022\033\n"
  "\025ATTESTATION_ID_DEVICE\020\307\205$\022\034\n\026ATTESTATIO"
  "N_ID_PRODUCT\020\310\205$\022\033\n\025ATTESTATION_ID_SERIA"
  "L\020\311\205$\022\031\n\023ATTESTATION_ID_IMEI\020\312\205$\022\031\n\023ATTE"
  "STATION_ID_MEID\020\313\205$\022!\n\033ATTESTATION_ID_MA"
  "NUFACTURER\020\314\205$\022\032\n\024ATTESTATION_ID_MODEL\020\315"
  "\205$\022\027\n\021VENDOR_PATCHLEVEL\020\316\205\014\022\025\n\017BOOT_PATC"
  "HLEVEL\020\317\205\014\022\037\n\031DEVICE_UNIQUE_ATTESTATION\020"
  "\320\205\034\022\035\n\027IDENTITY_CREDENTIAL_KEY\020\321\205\034\022\021\n\013ST"
  "ORAGE_KEY\020\322\205\034\022\025\n\017ASSOCIATED_DATA\020\350\207$\022\013\n\005"
  "NONCE\020\351\207$\022\020\n\nMAC_LENGTH\020\353\207\014\022\035\n\027RESET_SIN"
  "CE_ID_ROTATION\020\354\207\034\022\030\n\022CONFIRMATION_TOKEN"
  "\020\355\207$\022\030\n\022CERTIFICATE_SERIAL\020\356\207 \022\031\n\023CERTIF"
  "ICATE_SUBJECT\020\357\207$*K\n\tAlgorithm\022\007\n\003RSA\020\000\022"
  "\006\n\002EC\020\001\022\007\n\003AES\020\002\022\007\n\003DES\020\003\022\010\n\004HMAC\020\004\022\021\n\rA"
  "LGORITHM_MAX\020\005*C\n\tBlockMode\022\007\n\003ECB\020\000\022\007\n\003"
  "CBC\020\001\022\007\n\003CTR\020\002\022\007\n\003GCM\020\003\022\022\n\016BLOCK_MODE_MA"
  "X\020\004*\266\001\n\013PaddingMode\022\020\n\014PADDING_NONE\020\000\022\024\n"
  "\020PADDING_RSA_OAEP\020\001\022\023\n\017PADDING_RSA_PSS\020\002"
  "\022!\n\035PADDING_RSA_PKCS1_1_5_ENCRYPT\020\003\022\036\n\032P"
  "ADDING_RSA_PKCS1_1_5_SIGN\020\004\022\021\n\rPADDING_P"
  "KCS7\020\005\022\024\n\020PADDING_MODE_MAX\020\006*\242\001\n\006Digest\022"
  "\017\n\013DIGEST_NONE\020\000\022\016\n\nDIGEST_MD5\020\001\022\017\n\013DIGE"
  "ST_SHA1\020\002\022\024\n\020DIGEST_SHA_2_224\020\003\022\024\n\020DIGES"
  "T_SHA_2_256\020\004\022\024\n\020DIGEST_SHA_2_384\020\005\022\024\n\020D"
  "IGEST_SHA_2_512\020\006\022\016\n\nDIGEST_MAX\020\007*G\n\007EcC"
  "urve\022\t\n\005P_224\020\000\022\t\n\005P_256\020\001\022\t\n\005P_384\020\002\022\t\n"
  "\005P_521\020\003\022\020\n\014EC_CURVE_MAX\020\004*m\n\tKeyOrigin\022"
  "\r\n\tGENERATED\020\000\022\013\n\007DERIVED\020\001\022\014\n\010IMPORTED\020"
  "\002\022\013\n\007UNKNOWN\020\003\022\025\n\021SECURELY_IMPORTED\020\004\022\022\n"
  "\016KEY_ORIGIN_MAX\020\005*W\n\030KeyBlobUsageRequire"
  "ments\022\016\n\nSTANDALONE\020\000\022\030\n\024REQUIRES_FILE_S"
  "YSTEM\020\001\022\021\n\rKEY_USAGE_MAX\020\002*z\n\nKeyPurpose"
  "\022\013\n\007ENCRYPT\020\000\022\013\n\007DECRYPT\020\001\022\010\n\004SIGN\020\002\022\n\n\006"
  "VERIFY\020\003\022\014\n\010WRAP_KEY\020\005\022\r\n\tAGREE_KEY\020\006\022\016\n"
  "\nATTEST_KEY\020\007\022\017\n\013PURPOSE_MAX\020\010*\256\022\n\tError"
  "Code\022\006\n\002OK\020\000\022\035\n\031ROOT_OF_TRUST_ALREADY_SE"
  "T\020\001\022\027\n\023UNSUPPORTED_PURPOSE\020\002\022\030\n\024INCOMPAT"
  "IBLE_PURPOSE\020\003\022\031\n\025UNSUPPORTED_ALGORITHM\020"
  "\004\022\032\n\026INCOMPATIBLE_ALGORITHM\020\005\022\030\n\024UNSUPPO"
  "RTED_KEY_SIZE\020\006\022\032\n\026UNSUPPORTED_BLOCK_MOD"
  "E\020\007\022\033\n\027INCOMPATIBLE_BLOCK_MODE\020\010\022\032\n\026UNSU"
  "PPORTED_MAC_LENGTH\020\t\022\034\n\030UNSUPPORTED_PADD"
  "ING_MODE\020\n\022\035\n\031INCOMPATIBLE_PADDING_MODE\020"
  "\013\022\026\n\022UNSUPPORTED_DIGEST\020\014\022\027\n\023INCOMPATIBL"
  "E_DIGEST\020\r\022\033\n\027INVALID_EXPIRATION_TIME\020\016\022"
  "\023\n\017INVALID_USER_ID\020\017\022!\n\035INVALID_AUTHORIZ"
  "ATION_TIMEOUT\020\020\022\032\n\026UNSUPPORTED_KEY_FORMA"
  "T\020\021\022\033\n\027INCOMPATIBLE_KEY_FORMAT\020\022\022(\n$UNSU"
  "PPORTED_KEY_ENCRYPTION_ALGORITHM\020\023\022*\n&UN"
  "SUPPORTED_KEY_VERIFICATION_ALGORITHM\020\024\022\030"
  "\n\024INVALID_INPUT_LENGTH\020\025\022\036\n\032KEY_EXPORT_O"
  "PTIONS_INVALID\020\026\022\032\n\026DELEGATION_NOT_ALLOW"
  "ED\020\027\022\025\n\021KEY_NOT_YET_VALID\020\030\022\017\n\013KEY_EXPIR"
  "ED\020\031\022\036\n\032KEY_USER_NOT_AUTHENTICATED\020\032\022\031\n\025"
  "OUTPUT_PARAMETER_NULL\020\033\022\034\n\030INVALID_OPERA"
  "TION_HANDLE\020\034\022\035\n\031INSUFFICIENT_BUFFER_SPA"
  "CE\020\035\022\027\n\023VERIFICATION_FAILED\020\036\022\027\n\023TOO_MAN"
  "Y_OPERATIONS\020\037\022\033\n\027UNEXPECTED_NULL_POINTE"
  "R\020 \022\024\n\020INVALID_KEY_BLOB\020!\022\036\n\032IMPORTED_KE"
  "Y_NOT_ENCRYPTED\020\"\022\"\n\036IMPORTED_KEY_DECRYP"
  "TION_FAILED\020#\022\033\n\027IMPORTED_KEY_NOT_SIGNED"
  "\020$\022$\n IMPORTED_KEY_VERIFICATION_FAILED\020%"
  "\022\024\n\020INVALID_ARGUMENT\020&\022\023\n\017UNSUPPORTED_TA"
  "G\020\'\022\017\n\013INVALID_TAG\020(\022\034\n\030MEMORY_ALLOCATIO"
  "N_FAILED\020)\022\035\n\031IMPORT_PARAMETER_MISMATCH\020"
  "*\022\033\n\027SECURE_HW_ACCESS_DENIED\020+\022\027\n\023OPERAT"
  "ION_CANCELLED\020,\022\036\n\032CONCURRENT_ACCESS_CON"
  "FLICT\020-\022\022\n\016SECURE_HW_BUSY\020.\022\"\n\036SECURE_HW"
  "_COMMUNICATION_FAILED\020/\022\030\n\024UNSUPPORTED_E"
  "C_FIELD\0200\022\021\n\rMISSING_NONCE\0201\022\021\n\rINVALID_"
  "NONCE\0202\022\026\n\022MISSING_MAC_LENGTH\0203\022\033\n\027KEY_R"
  "ATE_LIMIT_EXCEEDED\0204\022\033\n\027CALLER_NONCE_PRO"
  "HIBITED\0205\022\030\n\024KEY_MAX_OPS_EXCEEDED\0206\022\026\n\022I"
  "NVALID_MAC_LENGTH\0207\022\032\n\026MISSING_MIN_MAC_L"
  "ENGTH\0208\022\036\n\032UNSUPPORTED_MIN_MAC_LENGTH\0209\022"
  "\023\n\017UNSUPPORTED_KDF\020:\022\030\n\024UNSUPPORTED_EC_C"
  "URVE\020;\022\030\n\024KEY_REQUIRES_UPGRADE\020<\022!\n\035ATTE"
  "STATION_CHALLENGE_MISSING\020=\022\034\n\030KEYMASTER"
  "_NOT_CONFIGURED\020>\022&\n\"ATTESTATION_APPLICA"
  "TION_ID_MISSING\020\?\022\025\n\021CANNOT_ATTEST_IDS\020@"
  "\022\021\n\rUNIMPLEMENTED\020A\022\024\n\020VERSION_MISMATCH\020"
  "B\022#\n\037ROLLBACK_RESISTANCE_UNAVAILABLE\020C\022\035"
  "\n\031HARDWARE_TYPE_UNAVAILABLE\020D\022\036\n\032PROOF_O"
  "F_PRESENCE_REQUIRED\020E\022*\n&CONCURRENT_PROO"
  "F_OF_PRESENCE_REQUESTED\020F\022\021\n\rUNKNOWN_ERR"
  "OR\020G\022\026\n\022INVALID_DEVICE_IDS\020H\022 \n\034PRODUCTI"
  "ON_MODE_PROVISIONING\020I\022\030\n\024NO_USER_CONFIR"
  "MATION\020J\022\034\n\030KEY_UPGRADE_NOT_REQUIRED\020K\022\021"
  "\n\rDEVICE_LOCKED\020L\022\024\n\020EARLY_BOOT_ENDED\020M\022"
  "$\n ATTESTATION_KEYS_NOT_PROVISIONED\020N\022#\n"
  "\037ATTESTATION_IDS_NOT_PROVISIONED\020O\022\025\n\021IN"
  "VALID_OPERATION\020P\022\033\n\027STORAGE_KEY_UNSUPPO"
  "RTED\020Q\022\033\n\027INCOMPATIBLE_MGF_DIGEST\020R\022\032\n\026U"
  "NSUPPORTED_MGF_DIGEST\020S*E\n\rSecurityLevel"
  "\022\014\n\010SOFTWARE\020\000\022\027\n\023TRUSTED_ENVIRONMENT\020\001\022"
  "\r\n\tSTRONGBOX\020\002*\\\n\031HardwareAuthenticatorT"
  "ype\022\020\n\014HW_AUTH_NONE\020\000\022\024\n\020HW_AUTH_PASSWOR"
  "D\020\001\022\027\n\023HW_AUTH_FINGERPRINT\020\002*)\n\tKeyForma"
  "t\022\010\n\004X509\020\000\022\t\n\005PKCS8\020\001\022\007\n\003RAW\020\003*+\n\tDTupE"
  "rror\022\013\n\007DTUP_OK\020\000\022\021\n\rDTUP_NO_EVENT\020\001*S\n\014"
  "DTupKeyEvent\022\021\n\rDTUP_RESERVED\020\000\022\021\n\rDTUP_"
  "VOL_DOWN\020r\022\017\n\013DTUP_VOL_UP\020s\022\014\n\010DTUP_PWR\020"
  "t*x\n\tBootColor\022\027\n\023BOOT_VERIFIED_GREEN\020\000\022"
  "\032\n\026BOOT_SELFSIGNED_YELLOW\020\001\022\032\n\026BOOT_UNVE"
  "RIFIED_ORANGE\020\002\022\032\n\026BOOT_VERIFY_FAILED_RE"
  "D\020\003*v\n\nChipFusing\022\020\n\014FUSING_PROTO\020\000\022\016\n\nF"
  "USING_DVT\020\001\022\016\n\nFUSING_PVT\020\002\022\020\n\014FUSING_PV"
  "T_1\020\003\022\020\n\014FUSING_D_PVT\020\004\022\022\n\016FUSING_D_PVT_"
  "1\020\005*\210\001\n\021CertificateStatus\022\037\n\033CERT_PREVIO"
  "USLY_PROVISIONED\020\000\022\020\n\014CERT_MISSING\020\001\022\021\n\r"
  "CERT_CHECKSUM\020\002\022\026\n\022CERT_UNKNOWN_ERROR\020\003\022"
  "\025\n\021CERT_WRONG_PACKET\020\004b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto = {
  false, false, 5750, descriptor_table_protodef_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto, "nugget/app/keymaster/keymaster_defs.proto", 
  &descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto_once, nullptr, 0, 0,
  schemas, file_default_instances, TableStruct_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto::offsets,
  file_level_metadata_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto, file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto, file_level_service_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
namespace nugget {
namespace app {
namespace keymaster {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* TagType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[0];
}
bool TagType_IsValid(int value) {
  switch (value) {
    case 0:
    case 65536:
    case 131072:
    case 196608:
    case 262144:
    case 327680:
    case 393216:
    case 458752:
    case 524288:
    case 589824:
    case 655360:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Tag_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[1];
}
bool Tag_IsValid(int value) {
  switch (value) {
    case 0:
    case 65538:
    case 65546:
    case 65837:
    case 65840:
    case 66040:
    case 66238:
    case 131073:
    case 131076:
    case 131077:
    case 131078:
    case 131275:
    case 196611:
    case 196616:
    case 197011:
    case 197012:
    case 197013:
    case 197109:
    case 197113:
    case 197313:
    case 197314:
    case 197326:
    case 197327:
    case 197611:
    case 327880:
    case 393616:
    case 393617:
    case 393618:
    case 393917:
    case 458759:
    case 458954:
    case 459054:
    case 459055:
    case 459057:
    case 459255:
    case 459258:
    case 459259:
    case 459260:
    case 459261:
    case 459472:
    case 459473:
    case 459474:
    case 459756:
    case 525294:
    case 590425:
    case 590524:
    case 590528:
    case 590531:
    case 590532:
    case 590533:
    case 590534:
    case 590535:
    case 590536:
    case 590537:
    case 590538:
    case 590539:
    case 590540:
    case 590541:
    case 590824:
    case 590825:
    case 590829:
    case 590831:
    case 655862:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Algorithm_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[2];
}
bool Algorithm_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BlockMode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[3];
}
bool BlockMode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PaddingMode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[4];
}
bool PaddingMode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Digest_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[5];
}
bool Digest_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EcCurve_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[6];
}
bool EcCurve_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyOrigin_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[7];
}
bool KeyOrigin_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyBlobUsageRequirements_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[8];
}
bool KeyBlobUsageRequirements_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyPurpose_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[9];
}
bool KeyPurpose_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ErrorCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[10];
}
bool ErrorCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SecurityLevel_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[11];
}
bool SecurityLevel_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* HardwareAuthenticatorType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[12];
}
bool HardwareAuthenticatorType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KeyFormat_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[13];
}
bool KeyFormat_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DTupError_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[14];
}
bool DTupError_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DTupKeyEvent_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[15];
}
bool DTupKeyEvent_IsValid(int value) {
  switch (value) {
    case 0:
    case 114:
    case 115:
    case 116:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BootColor_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[16];
}
bool BootColor_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ChipFusing_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[17];
}
bool ChipFusing_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CertificateStatus_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto);
  return file_level_enum_descriptors_nugget_2fapp_2fkeymaster_2fkeymaster_5fdefs_2eproto[18];
}
bool CertificateStatus_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace keymaster
}  // namespace app
}  // namespace nugget
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
