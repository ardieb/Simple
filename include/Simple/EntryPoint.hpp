//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_ENTRYPOINT_HPP
#define SIMPLE_ENTRYPOINT_HPP

int main(int argc, char** argv) {
    auto app = Simple::createApp();
    app->launch();
    app->close();
}

#endif //SIMPLE_ENTRYPOINT_HPP
