add_subdirectory(proto)
add_library(PUBBYDB_LIBRARY STATIC
        ${PUBBYDB_INCLUDE_HEADERS}
        main.cc)