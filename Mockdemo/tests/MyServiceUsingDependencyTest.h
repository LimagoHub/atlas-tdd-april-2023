//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../source/MyServiceUsingDepency.h"
#include "DependencyMock.h"
using namespace testing;
class MyServiceUsingDependencyTest: public Test {

protected:
    //std::unique_ptr<DependencyMock>  dependencyMock= std::make_unique<DependencyMock>();
    //MyServiceUsingDepency object_under_test{std::move(dependencyMock)};
};
