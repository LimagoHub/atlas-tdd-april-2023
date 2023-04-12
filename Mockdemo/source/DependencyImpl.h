//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once
#include <string>
#include <iostream>
#include "Dependency.h"

class DependencyImpl : public Dependency {
public:
    void foo(std::string message) override {
        std::cout << "Foo" << message << std::endl;
    }

    int bar() override {
        return 42;
    }

    int foobar(std::string message) override {
        return message.length();
    }
};
