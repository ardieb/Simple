//
// Created by Arthur Burke on 2020-01-12.
//

#include <Simple.h>
class SandboxApp : public Simple::App {
public:
    SandboxApp() = default;

    ~SandboxApp() override = default;
};

Simple::App* Simple::CreateNewApp() {
    return new SandboxApp();
}

