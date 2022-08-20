cmake_minimum_required(VERSION 3.10)

project(protobuf)

# Build protobuf

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(protodir protobuf)

set(libprotobuf_src 
    ${protodir}/src/google/protobuf/any_lite.cc
    ${protodir}/src/google/protobuf/arena.cc
    ${protodir}/src/google/protobuf/arenastring.cc
    ${protodir}/src/google/protobuf/extension_set.cc
    ${protodir}/src/google/protobuf/generated_enum_util.cc
    ${protodir}/src/google/protobuf/generated_message_table_driven_lite.cc
    ${protodir}/src/google/protobuf/generated_message_util.cc
    ${protodir}/src/google/protobuf/implicit_weak_message.cc
    ${protodir}/src/google/protobuf/io/coded_stream.cc
    ${protodir}/src/google/protobuf/io/io_win32.cc
    ${protodir}/src/google/protobuf/io/strtod.cc
    ${protodir}/src/google/protobuf/io/zero_copy_stream.cc
    ${protodir}/src/google/protobuf/io/zero_copy_stream_impl.cc
    ${protodir}/src/google/protobuf/io/zero_copy_stream_impl_lite.cc
    ${protodir}/src/google/protobuf/map.cc
    ${protodir}/src/google/protobuf/message_lite.cc
    ${protodir}/src/google/protobuf/parse_context.cc
    ${protodir}/src/google/protobuf/repeated_field.cc
    ${protodir}/src/google/protobuf/stubs/bytestream.cc
    ${protodir}/src/google/protobuf/stubs/common.cc
    ${protodir}/src/google/protobuf/stubs/int128.cc
    ${protodir}/src/google/protobuf/stubs/status.cc
    ${protodir}/src/google/protobuf/stubs/statusor.cc
    ${protodir}/src/google/protobuf/stubs/stringpiece.cc
    ${protodir}/src/google/protobuf/stubs/stringprintf.cc
    ${protodir}/src/google/protobuf/stubs/structurally_valid.cc
    ${protodir}/src/google/protobuf/stubs/strutil.cc
    ${protodir}/src/google/protobuf/stubs/time.cc
    ${protodir}/src/google/protobuf/wire_format_lite.cc
    ${protodir}/src/google/protobuf/any.cc
    ${protodir}/src/google/protobuf/any.pb.cc
    ${protodir}/src/google/protobuf/api.pb.cc
    ${protodir}/src/google/protobuf/compiler/importer.cc
    ${protodir}/src/google/protobuf/compiler/parser.cc
    ${protodir}/src/google/protobuf/descriptor.cc
    ${protodir}/src/google/protobuf/descriptor.pb.cc
    ${protodir}/src/google/protobuf/descriptor_database.cc
    ${protodir}/src/google/protobuf/duration.pb.cc
    ${protodir}/src/google/protobuf/dynamic_message.cc
    ${protodir}/src/google/protobuf/empty.pb.cc
    ${protodir}/src/google/protobuf/extension_set_heavy.cc
    ${protodir}/src/google/protobuf/field_mask.pb.cc
    ${protodir}/src/google/protobuf/generated_message_reflection.cc
    ${protodir}/src/google/protobuf/generated_message_table_driven.cc
    ${protodir}/src/google/protobuf/generated_message_util.cc
    ${protodir}/src/google/protobuf/io/gzip_stream.cc
    ${protodir}/src/google/protobuf/io/printer.cc
    ${protodir}/src/google/protobuf/io/tokenizer.cc
    ${protodir}/src/google/protobuf/map_field.cc
    ${protodir}/src/google/protobuf/message.cc
    ${protodir}/src/google/protobuf/reflection_ops.cc
    ${protodir}/src/google/protobuf/service.cc
    ${protodir}/src/google/protobuf/source_context.pb.cc
    ${protodir}/src/google/protobuf/struct.pb.cc
    ${protodir}/src/google/protobuf/stubs/substitute.cc
    ${protodir}/src/google/protobuf/text_format.cc
    ${protodir}/src/google/protobuf/timestamp.pb.cc
    ${protodir}/src/google/protobuf/type.pb.cc
    ${protodir}/src/google/protobuf/parse_context.cc
    ${protodir}/src/google/protobuf/unknown_field_set.cc
    ${protodir}/src/google/protobuf/util/delimited_message_util.cc
    ${protodir}/src/google/protobuf/util/field_comparator.cc
    ${protodir}/src/google/protobuf/util/field_mask_util.cc
    ${protodir}/src/google/protobuf/util/internal/datapiece.cc
    ${protodir}/src/google/protobuf/util/internal/default_value_objectwriter.cc
    ${protodir}/src/google/protobuf/util/internal/error_listener.cc
    ${protodir}/src/google/protobuf/util/internal/field_mask_utility.cc
    ${protodir}/src/google/protobuf/util/internal/json_escaping.cc
    ${protodir}/src/google/protobuf/util/internal/json_objectwriter.cc
    ${protodir}/src/google/protobuf/util/internal/json_stream_parser.cc
    ${protodir}/src/google/protobuf/util/internal/object_writer.cc
    ${protodir}/src/google/protobuf/util/internal/proto_writer.cc
    ${protodir}/src/google/protobuf/util/internal/protostream_objectsource.cc
    ${protodir}/src/google/protobuf/util/internal/protostream_objectwriter.cc
    ${protodir}/src/google/protobuf/util/internal/type_info.cc
    ${protodir}/src/google/protobuf/util/internal/type_info_test_helper.cc
    ${protodir}/src/google/protobuf/util/internal/utility.cc
    ${protodir}/src/google/protobuf/util/json_util.cc
    ${protodir}/src/google/protobuf/util/message_differencer.cc
    ${protodir}/src/google/protobuf/util/time_util.cc
    ${protodir}/src/google/protobuf/util/type_resolver_util.cc
    ${protodir}/src/google/protobuf/wire_format.cc
    ${protodir}/src/google/protobuf/wrappers.pb.cc)

set(libprotobuf_includes ${protodir}/src)
if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DGOOGLE_PROTOBUF_NO_RTTI=1 -DHAVE_PTHREAD=1")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGOOGLE_PROTOBUF_NO_RTTI=1 -DHAVE_PTHREAD=1")

	set(libprotobuf_includes ${libprotobuf_includes}
		configs/android)
	#${ANDROID_NDK}/sources/cxx-stl/llvm-libc++/include/)
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_PTHREAD=1")	
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DHAVE_PTHREAD=1")	
	execute_process(COMMAND configs/config-protobuf.sh
	       WORKING_DIRECTORY ${protodir})

        #set(libprotobuf_src ${libprotobuf_src}  ${protodir}/config.h)
	set(libprotobuf_includes ${libprotobuf_includes} ${libprotobuf_includes} ${protodir})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(protobuf STATIC ${libprotobuf_src})
target_include_directories(protobuf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${libprotobuf_includes})

if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
	target_link_libraries(protobuf z log)
else()
	find_package(ZLIB REQUIRED)
	find_package(Threads REQUIRED)
	target_link_libraries (protobuf PRIVATE ZLIB::ZLIB Threads::Threads)
endif()

# Build libprotobuf-mutator
set(LPM_DIR libprotobuf-mutator)
file(GLOB_RECURSE lpm_src "${LPM_DIR}/src/binary_format.cc"
   "${LPM_DIR}/src/libfuzzer/libfuzzer_macro.cc"
   "${LPM_DIR}/src/libfuzzer/libfuzzer_mutator.cc"
   "${LPM_DIR}/src/mutator.cc"
   "${LPM_DIR}/src/text_format.cc"
   "${LPM_DIR}/src/utf8_fix.cc")
add_library(pm STATIC ${lpm_src})
target_link_libraries(protobuf)
target_include_directories(pm PUBLIC ${LPM_DIR}/ ${protodir}/src)

# Build client binary
if(${CMAKE_SYSTEM_NAME} STREQUAL "Android") # client is only built for Android (for now)

# include libnos build

set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(external_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(libnos_root_dir ${CMAKE_CURRENT_SOURCE_DIR}/libnos)
set(libnos_datagram_dir ${libnos_root_dir}/libnos_datagram)
set(libnos_transport_dir ${libnos_root_dir}/libnos_transport)
set(libnos_dir ${libnos_root_dir}/libnos)

find_program(PATCH NAMES patch REQUIRED)
set(orig_file ${libnos_transport_dir}/transport.c) # patch Android includes
set(patch_file ${external_dir}/configs/libnos_transport.patch)
execute_process(COMMAND ${PATCH} ${orig_file} ${patch_file}
  TIMEOUT 10
)

add_library(nos_datagram STATIC ${libnos_datagram_dir}/citadel.c)
target_include_directories(nos_datagram PUBLIC ${libnos_datagram_dir}/include ${root_dir}/jni/include)
target_link_libraries(nos_datagram android log)

set(orig_file ${libnos_datagram_dir}/citadel.c) # patch Android includes
set(patch_file ${external_dir}/configs/libnos_datagram.patch)
execute_process(COMMAND ${PATCH} ${orig_file} ${patch_file}
  TIMEOUT 10
)
add_library(nos_transport STATIC ${libnos_transport_dir}/transport.c ${libnos_transport_dir}/crc16.c)
target_include_directories(nos_transport PUBLIC include ${libnos_datagram_dir}/include ${libnos_transport_dir}/include ${root_dir}/jni/include ${libnos_root_dir}/nugget/include/)
target_link_libraries(nos_transport android log)

add_library(nos STATIC  ${libnos_dir}/NuggetClient.cpp)
# add_definitions(-DAPP_ERROR_NOT_READY=-55)
target_include_directories(nos PUBLIC ${libnos_dir}/include ${libnos_transport_dir}/include ${libnos_datagram_dir}/include ${root_dir}/jni/include ${libnos_root_dir}/nugget/include/)
target_link_libraries(nos android log nos_datagram nos_transport)

# Sqlite3
set(sqlite_rootdir sqlite/dist)
set(sqlite3_cflags
	"-DNDEBUG=1"
        "-DHAVE_USLEEP=1"
        "-DSQLITE_HAVE_ISNAN"
        "-DSQLITE_DEFAULT_JOURNAL_SIZE_LIMIT=1048576"
        "-DSQLITE_THREADSAFE=2"
        "-DSQLITE_TEMP_STORE=3"
        "-DSQLITE_POWERSAFE_OVERWRITE=1"
        "-DSQLITE_DEFAULT_FILE_FORMAT=4"
        "-DSQLITE_DEFAULT_AUTOVACUUM=1"
        "-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1"
        "-DSQLITE_ENABLE_FTS3"
        "-DSQLITE_ENABLE_FTS3_BACKWARDS"
        "-DSQLITE_ENABLE_FTS4"
        "-DSQLITE_OMIT_BUILTIN_TEST"
        "-DSQLITE_OMIT_COMPILEOPTION_DIAGS"
        "-DSQLITE_OMIT_LOAD_EXTENSION"
        "-DSQLITE_DEFAULT_FILE_PERMISSIONS=0600"
        "-DSQLITE_SECURE_DELETE"
        "-DSQLITE_ENABLE_BATCH_ATOMIC_WRITE"
        "-DBIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD"
        "-DSQLITE_DEFAULT_LEGACY_ALTER_TABLE"
        "-Wno-unused-parameter"
        "-Werror"

        // Default value causes sqlite3_open_v2 to return error if DB is missing.
        "-ftrivial-auto-var-init=pattern"
	"-DUSE_PREAD64"
        "-Dfdatasync=fdatasync"
        "-DHAVE_MALLOC_H=1"
        "-DHAVE_MALLOC_USABLE_SIZE"
        "-DSQLITE_ENABLE_DBSTAT_VTAB"
	)

add_library(sqlite STATIC ${sqlite_rootdir}/sqlite3.c ${sqlite_rootdir}/sqlite3ext.h ${sqlite_rootdir}/sqlite3.h)
target_include_directories(sqlite PUBLIC ${root_dir}/jni/include)
target_link_libraries(sqlite android log)
 

endif()
