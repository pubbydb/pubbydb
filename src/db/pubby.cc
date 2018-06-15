// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <pubbydb>
#include <utility>
using namespace pubbydb;
using namespace pubbydb_proto;

pubbydb::Pubby::Pubby(pubbydb::Configuration configuration) {
    this->configuration = std::move(configuration);
}

void pubbydb::Pubby::enqueueRequest(pubbydb_proto::PubbyRequest request, pubbydb::ResponseCallback callback) {
    PubbyResponse response;
    response.set_request_id(request.id());
    response.set_error_message("Unrecognized request type.");
    response.set_type(PubbyResponse_PubbyResponseType_ERROR);
    callback(response);
}
