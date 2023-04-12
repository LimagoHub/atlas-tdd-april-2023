//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once


#include <string>
#include <iostream>

class Dependency {

public:
    virtual void foo(std::string message) = 0;

    virtual int bar ()= 0;

    virtual int foobar(std::string message) = 0;
};
