//
// Created by JoachimWagner on 12.04.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "Mockpersonen_repository.h"
#include "MockBlacklistService.h"
#include "../source/services/personen_service_impl.h"
#include "../source/services/personen_service_exception.h"

using namespace testing;

class personen_service_impl_test : public Test{

protected:
    NiceMock<MockBlacklistService> blacklistServiceMock;
    Mockpersonen_repository repoMock;
    personen_service_impl object_under_test{repoMock, blacklistServiceMock};

    void SetUp() override;
};
