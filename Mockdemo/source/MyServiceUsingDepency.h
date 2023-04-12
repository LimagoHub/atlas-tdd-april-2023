//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once
#include "Dependency.h"
#include <memory>
class MyServiceUsingDepency {

    std::unique_ptr<Dependency> dependency;

public:
    explicit MyServiceUsingDepency(std::unique_ptr<Dependency> dependency) : dependency(std::move(dependency)) {}

public:

    int square() {

        return dependency->bar();
    }

    void doIt() {
        // Do something
        dependency->foo("Hallo Welt");
        // Other things
        // save order
    }

    int doOtherThing() {
        // Do something

        return dependency->foobar("Hallo Welt") + 5;
        // Other things
        // save order
    }
};
