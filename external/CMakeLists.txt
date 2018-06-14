set(PUBBYDB_EXTERNAL_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE STRING "path to external/ for PubbyDB.")
set(PUBBY_INIH_LIBRARY inih CACHE STRING "The inih library for PubbyDB.")
add_library(inih STATIC
        inih/ini.h inih/ini.c
        inih/cpp/INIReader.h inih/cpp/INIReader.cpp)