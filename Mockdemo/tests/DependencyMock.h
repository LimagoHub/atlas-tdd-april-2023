//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "../source/Dependency.h"

class DependencyMock : public Dependency{

public:
    MOCK_METHOD(void, foo, (std::string),());
    MOCK_METHOD(int, bar, (),());
    MOCK_METHOD(int, foobar,  (std::string),());
};
