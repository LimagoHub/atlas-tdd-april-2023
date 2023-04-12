//
// Created by JoachimWagner on 11.04.2023.
//

#include "Stapel.h"

Stapel::Stapel(){

}

Stapel::~Stapel() {

}

bool Stapel::is_empty() {
    return data.empty();
}

bool Stapel::is_full() {
    return data.size() >= 10;
}

void Stapel::push(int value) {
    if(is_full())
        throw StapelException("Overflow");
    data.push_back(value);
}

int Stapel::pop() {
    if(is_empty())
        throw StapelException("Underflow");
    auto result = data.back();
    data.pop_back();
    return result;
}

