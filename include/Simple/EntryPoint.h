//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_ENTRYPOINT_H
#define SIMPLE_ENTRYPOINT_H

int main(int argc, char** argv) {
    auto app = Simple::CreateNewApp();
    app->launch();
    app->close();
}

#endif //SIMPLE_ENTRYPOINT_H
