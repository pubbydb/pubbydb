find_package(Protobuf REQUIRED)
set(Protobuf_IMPORT_DIRS ${PUBBYDB_PROTO_DIR})
PROTOBUF_GENERATE_CPP(PUBBYDB_INTERNAL_PROTO_SRC PUBBYDB_INTERNAL_PROTO_HEADER
        database.proto
        permission.proto
        user.proto)
set(PUBBYDB_INTERNAL_PROTO_LIBRARY pubbydb_internal_proto CACHE STRING "Internal Protobuf")
add_library(${PUBBYDB_INTERNAL_PROTO_LIBRARY} STATIC
        ${PUBBYDB_INTERNAL_PROTO_HEADER}
        ${PUBBYDB_INTERNAL_PROTO_SRC})
target_include_directories(${PUBBYDB_INTERNAL_PROTO_LIBRARY} PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_include_pubbydb_protobuf(pubbydb_internal_proto)