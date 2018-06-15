// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PUBBYDB_MONO_REPO_CONFIGURATION_H
#define PUBBYDB_MONO_REPO_CONFIGURATION_H

namespace pubbydb
{
    typedef struct
    {
        std::string server_file;
        int32_t tcp_port;
        int32_t http_port;
        bool verbose;
    } Configuration;

    std::string GetDefaultConfigurationDirectory();

    std::string GetDefaultConfigurationFile();

    Configuration GetDefaultConfiguration();

    std::string GetPathSeparator();
}

#endif //PUBBYDB_MONO_REPO_CONFIGURATION_H
