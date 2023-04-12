//
// Created by JoachimWagner on 12.04.2023.
//

#pragma once

#include "gmock/gmock.h"
#include "../source/services/BlacklistService.h"

class MockBlacklistService : public BlacklistService {
public:
    MOCK_METHOD(bool, is_blacklisted, (const person possibleBlacklistedPerson), ( override));

};