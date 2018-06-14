// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include <pubbydb>

int main(int argc, const char **argv) {
    std::cout << pubbydb::GetDefaultConfigurationFile() << std::endl;
    return 0;
}