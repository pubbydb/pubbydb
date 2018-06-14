// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <pubbydb>

#ifdef WIN32
std::string GetDefaultConfigurationDirectory() {
    return std::string("C:\\pubbydb");
}

std::string pubbydb::GetPathSeparator() {
    return std::string("\\");
}
#else
std::string pubbydb::GetDefaultConfigurationDirectory() {
    return std::string("/etc/pubbydb");
}

std::string pubbydb::GetPathSeparator() {
    return std::string("/");
}
#endif

std::string pubbydb::GetDefaultConfigurationFile() {
    return pubbydb::GetDefaultConfigurationDirectory() + pubbydb::GetPathSeparator() + ".pubbydb";
}

pubbydb::Configuration pubbydb::GetDefaultConfiguration() {
    pubbydb::Configuration configuration;
    configuration.server_file = pubbydb::GetDefaultConfigurationFile();
    configuration.tcp_port = 9045;
    configuration.http_port = 9046;
    configuration.verbose = false;
    return configuration;
}
