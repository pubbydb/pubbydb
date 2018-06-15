add_subdirectory(proto)
add_library(${PUBBYDB_LIBRARY} STATIC
        ${PUBBYDB_INCLUDE_HEADERS}
        daemon/daemon.cc daemon/daemon.hpp
        pubbydb.cc db/pubby.cc)
add_executable(${PUBBYDB_DAEMON}
        main.cc)
target_include_directories(${PUBBYDB_DAEMON} PUBLIC ${PUBBYDB_EXTERNAL_INCLUDE_DIR})
target_include_directories(${PUBBYDB_DAEMON} PUBLIC ${PUBBYDB_INCLUDE_DIR})
target_include_directories(${PUBBYDB_LIBRARY} PUBLIC ${PUBBYDB_INCLUDE_DIR})
target_include_pubbydb_protobuf(${PUBBYDB_DAEMON})
target_include_pubbydb_protobuf(${PUBBYDB_LIBRARY})
target_link_libraries(${PUBBYDB_DAEMON} ${PUBBY_INIH_LIBRARY} ${PUBBYDB_LIBRARY})
install(TARGETS ${PUBBYDB_DAEMON} DESTINATION bin)
install(TARGETS ${PUBBYDB_LIBRARY} DESTINATION lib)