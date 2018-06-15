// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PUBBYDB_MONO_REPO_NET_H
#define PUBBYDB_MONO_REPO_NET_H

#include <string>
#include <request.pb.h>

namespace pubbydb
{
    class RequestAdapter;

    typedef void (*RequestHandler)(pubbydb_proto::PubbyRequest &request, RequestAdapter &adapter);

    void SocketStartup();

    void SocketShutdown();

    int SocketBind(std::string &host, int port, void *addr);

    class RequestAdapter
    {
    public:
        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void add_listener(RequestHandler handler) = 0;
    };
}

#endif //PUBBYDB_MONO_REPO_NET_H
