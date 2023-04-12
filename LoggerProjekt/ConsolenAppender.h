//
// Created by JoachimWagner on 12.04.2023.
//

#pragma once


#include <iostream>
#include "Appender.h"

class ConsolenAppender : public Appender{
public:
    void write(std::string message) const noexcept override {
        std::cout << message << std::endl;  // Kein Test noetig
    }
};
