//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_APP_HPP
#define SIMPLE_APP_HPP
#include <Simple/SimpleCore.h>

namespace Simple {
    class App {
    public:
        App();
        virtual ~App();
        void launch();
        void close();
    };
    App* create_app();
}

#endif //SIMPLE_APP_HPP
