//
// Created by JoachimWagner on 30.05.2022.
//

#include "euro_to_dollar_calculator_impl_test.h"

TEST_F(euro_to_dollar_calculator_impl_test, simpletest) {
    EXPECT_CALL(exchange_rate_service_mock, get_rate_for("USD")).WillOnce(testing::Return(1.1));
    const auto result = object_under_test.convert(100);
    EXPECT_THAT(110.0, testing::DoubleNear(result, 0.000001));
}