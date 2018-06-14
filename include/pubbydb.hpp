// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PUBBYDB_MONO_REPO_PUBBYDB_HPP
#define PUBBYDB_MONO_REPO_PUBBYDB_HPP

#include <cstdint>
#include <string>

namespace pubbydb
{
    typedef struct
    {
        std::string server_file;
        int32_t tcp_port;
        int32_t http_port;
    } Configuration;
}

#endif //PUBBYDB_MONO_REPO_PUBBYDB_HPP
