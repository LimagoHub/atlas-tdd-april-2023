//
// Created by JoachimWagner on 31.05.2022.
//
#include <stdexcept>
#include "euro_to_dollar_presenter_impl_test.h"


void euro_to_dollar_presenter_impl_test::SetUp()  {
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
    object_under_test.set_view(&euro_to_dollar_viewMock);
}

TEST_F(euro_to_dollar_presenter_impl_test, beenden__close_window__application_terminated) {
    EXPECT_CALL(euro_to_dollar_viewMock, dispose);
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test,populate_items__init__fields_filled_with_values) {
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));

    object_under_test.populate_items();
}
TEST_F(euro_to_dollar_presenter_impl_test,rechnen__not_covertable_value_in_Eurofield__errormessage_in_dollar_field) {
    InSequence a;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));
    object_under_test.rechnen();
}




TEST_F(euro_to_dollar_presenter_impl_test,rechnen__valid_euro_value__result_in_dollar_field_and_eurovalue_passed_service) {

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro).WillOnce(Return("100"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(100.0)).WillOnce(Return(4711.11));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("4711.110000"));
    object_under_test.rechnen();
}



TEST_F(euro_to_dollar_presenter_impl_test,update_rechnen_action_state__not_covertable_value_in_Eurofield__rechnen_disabled) {

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro).WillOnce(Return("Karl Klammer"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test,update_rechnen_action_state__covertable_value_in_Eurofield__rechnen_enabled) {

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro).WillOnce(Return("100"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.update_rechnen_action_state();
}