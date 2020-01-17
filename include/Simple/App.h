//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_APP_H
#define SIMPLE_APP_H

namespace Simple {
    class App {
    public:
        App();
        virtual ~App();
        void launch();
        void close();
    };
    App* CreateNewApp();
}

#endif //SIMPLE_APP_H
