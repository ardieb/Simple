//
// Created by Arthur Burke on 2020-01-12.
//

#include <Simple/App.hpp>
#include <iostream>

Simple::App::App() {
    // TODO
    // Fill in constructor
    std::cout << "New application instance created\n";
}

Simple::App::~App() {
    // TODO
    // Fill in destructor
    std::cout << "Application destroyed\n";
}

void Simple::App::close() {
    // TODOw
    // Fill in close code
    std::cout << "Closing application...\n";
    delete this;
}

void Simple::App::launch() {
    // TODO
    // Fill in launch code
    std::cout << "Launching application...\n";
    std::cin.get();
}

