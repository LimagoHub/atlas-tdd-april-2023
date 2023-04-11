//
// Created by JoachimWagner on 11.04.2023.
//

#pragma once

#include "StapelException.h"
class Stapel {

    int data[10];
    int index;

public:
    Stapel();
    ~Stapel();

    void push(int value);
    int pop();

    bool is_empty();
    bool is_full();

};
