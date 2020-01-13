//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_APP_HPP
#define SIMPLE_APP_HPP

namespace Simple {
    class App {
    public:
        App();
        virtual ~App();
        void launch();
        void close();
    };
    App* createApp();
}

#endif //SIMPLE_APP_HPP
