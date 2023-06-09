//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "../../source/collections/stapel.h"
#include "../../source/collections/StapelException.h"

using namespace testing;

class StapelTest : public Test{

protected:
    Stapel object_under_test;

    void fill_up_to_limit()
    {
        for (int i = 0; i < 10; ++i)
        {
            EXPECT_NO_THROW(object_under_test.push(1));
        }

    }
};
