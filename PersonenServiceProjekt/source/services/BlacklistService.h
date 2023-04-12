//
// Created by JoachimWagner on 12.04.2023.
//

#pragma once


#include "../persistence/person.h"

class BlacklistService {
public:
    virtual bool is_blacklisted(const person possibleBlacklistedPerson)=0;
};
