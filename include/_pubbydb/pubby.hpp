// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PUBBYDB_MONO_REPO_PUBBY_HPP
#define PUBBYDB_MONO_REPO_PUBBY_HPP

#include <request.pb.h>
#include <response.pb.h>
#include "configuration.hpp"
#include "net.hpp"

namespace pubbydb
{
    typedef void (*ResponseCallback)(pubbydb_proto::PubbyResponse &response);

    class Pubby
    {
    public:
        explicit Pubby(pubbydb::Configuration configuration);
        pubbydb::Configuration configuration;
        void enqueueRequest(pubbydb_proto::PubbyRequest request, ResponseCallback callback);
    };
}


#endif //PUBBYDB_MONO_REPO_PUBBY_HPP
