//
// Created by JoachimWagner on 12.04.2023.
//

#pragma once


#include <string>
#include <iostream>
#include "Appender.h"

class Logger {

public:
    explicit Logger(Appender &appender) : appender(appender) {}

    void log(std::string message) noexcept {
        const std::string prefix = "Prefix: ";// Hier steht komplizierter Code um den Caller zu ermitteln
        appender.write(prefix + message);
    }
private:
    Appender & appender;


};
