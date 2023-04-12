//
// Created by JoachimWagner on 12.04.2023.
//

#pragma once


#include <string>

class Appender {

public:
    virtual void write(std::string message)  const  noexcept = 0;
};
