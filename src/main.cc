// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <inih/cpp/INIReader.h>
#include <cstring>
#include <iostream>
#include <pubbydb>
#include <string>

#define MATCH_ARG(full, abbr) (strcmp(argv[i], full) == 0 || strcmp(argv[i], abbr) == 0)
#define ENSURE_NOT_LAST(name) \
    if (i >= argc - 1) { \
        std::cerr << "fatal error: missing argument for option " << (name) << std::endl; \
        return 1; \
    } \


int read_ini(INIReader &reader, pubbydb::Configuration &configuration);

int main(int argc, const char **argv) {
    auto configuration = pubbydb::GetDefaultConfiguration();
    std::string userConfigurationFile;

    for (int i = 1; i < argc; i++) {
        if (MATCH_ARG("verbose", "v")) {
            configuration.verbose = true;
        } else if (MATCH_ARG("--server-file", "-sf")) {
            ENSURE_NOT_LAST("--server-file");
            configuration.server_file.clear();
            configuration.server_file += argv[++i];
        } else if (userConfigurationFile.empty()) {
            userConfigurationFile += argv[i];
        }
    }

    if (!userConfigurationFile.empty()) {
        INIReader reader(userConfigurationFile);

        int error = reader.ParseError();

        if (error == -1) {
            std::cerr << "fatal error: could not open configuration file " << userConfigurationFile << std::endl;
            return 1;
        }

        if (error > 0) {
            std::cerr << "fatal error: syntax error at line " << error << " of " << userConfigurationFile << std::endl;
            return 1;
        }

        int result = read_ini(reader, configuration);

        if (result != 0)
            return result;
    }

    return 0;
}

int read_ini(INIReader &reader, pubbydb::Configuration &configuration) {
    // TODO: Actually read this
    return 0;
}