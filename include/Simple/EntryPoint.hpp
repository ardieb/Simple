//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_ENTRYPOINT_HPP
#define SIMPLE_ENTRYPOINT_HPP

#include <Simple/SimpleCore.h>

int main(int argc, char** argv) {
    auto app = Simple::create_app();
    app->launch();
    app->close();
}

#endif //SIMPLE_ENTRYPOINT_HPP
