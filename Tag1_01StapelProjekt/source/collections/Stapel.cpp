//
// Created by JoachimWagner on 11.04.2023.
//

#include "Stapel.h"

Stapel::Stapel():index{0} {

}

Stapel::~Stapel() {

}

bool Stapel::is_empty() {
    return index == 0;
}

bool Stapel::is_full() {
    return index == 10;
}

void Stapel::push(int value) {
    if(is_full())
        throw StapelException("Overflow");
    data[index ++] = value;
}

int Stapel::pop() {
    if(is_empty())
        throw StapelException("Underflow");
    return data[--index];
}

