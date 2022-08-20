cmake_minimum_required(VERSION 3.10)
project(nos_parser)


#if(EARLY_BUILD)
#    add_subdirectory(external/protobuf)
#
#    return()
#endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Protobuf build
add_subdirectory(external)

set(Protobuf_USE_STATIC_LIBS ON)

set(nos_proto_dir "external/libnos_protobuf_cpp")

file(GLOB_RECURSE nos_proto_SRC
     "${nos_proto_dir}/*.cc")

file(GLOB_RECURSE nos_proto_HDR
     "${nos_proto_dir}/*.h")

file(GLOB_RECURSE nos_type_src "nostypes/*.h" "nostypes/*.cpp")

set(libnos_include_dirs
	external/libnos/libnos/include
	external/libnos/libnos_datagram/include
	external/libnos/libnos_transport/include)

# Headers for keystore v2 usage
set(keymint_include_dir external/keymint/)

# Build NosTypes library
add_library (nostypes STATIC ${nos_type_src} ${nos_proto_SRC} ${nos_proto_HDR} jni/include ${libnos_include_dirs})

TARGET_LINK_LIBRARIES(nostypes protobuf)

target_include_directories (nostypes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${nos_proto_dir} jni/ nostypes/ ${libnos_include_dirs})

# Build parser library

add_library (parser SHARED parser/parser.cpp ${nos_type_src} ${nos_proto_SRC} ${nos_proto_HDR} jni/include)
TARGET_LINK_LIBRARIES(parser protobuf nostypes)
target_include_directories (parser PUBLIC ${PROTOBUF_ROOT}/include ${CMAKE_CURRENT_SOURCE_DIR} ${nos_proto_dir} jni/ nostypes/)

# Build client binary
if(${CMAKE_SYSTEM_NAME} STREQUAL "Android") # client is only built for Android (for now)

# Sqlite3
set(sqlite3_dir external/sqlite/dist/)

# Build nosclient

add_executable (nosclient client/nosclient.cpp ${nos_type_src} ${nos_proto_SRC} ${nos_proto_HDR} nostypes/nostypes.h ${libnos_include_dirs} exploits/rop.cpp client/utils.cpp client/keyblob_utils.cpp fuzzer/fuzz.cpp fuzzer/libradamsa.c)

target_include_directories (nosclient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${nos_proto_dir} jni/include nostypes/ external/libnos/nugget/include ${libnos_include_dirs} client fuzzer exploits external/libprotobuf-mutator ${keymint_include_dir} ${sqlite3_dir})
# target_compile_options(nosclient PUBLIC -fsanitize=address -fno-omit-frame-pointer)
# set_target_properties(nosclient PROPERTIES LINK_FLAGS -fsanitize=address)

TARGET_LINK_LIBRARIES(nosclient android log protobuf nostypes nos nos_datagram nos_transport pm sqlite)

endif()
