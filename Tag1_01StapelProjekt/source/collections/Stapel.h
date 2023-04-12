//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once

#include "StapelException.h"
#include <vector>
class Stapel {

    std::vector<int> data;


public:
    Stapel();
    ~Stapel();

    void push(int value);
    int pop();

    bool is_empty();
    bool is_full();

};
