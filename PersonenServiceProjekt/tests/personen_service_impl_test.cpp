//
// Created by JoachimWagner on 12.04.2023.
//

#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throwsPersonenServiceException) {
    try {
        person invalid_person{"J", "Doe"};
        object_under_test.speichern(invalid_person);
        FAIL()<< "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_STREQ("Vorname zu kurz", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throwsPersonenServiceException) {
    try {
        person invalid_person{"John", "D"};
        object_under_test.speichern(invalid_person);
        FAIL()<< "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_STREQ("Nachname zu kurz", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__unerwuenschte_person__throwsPersonenServiceException) {
    try {
        person invalid_person{"John", "Doe"};

        EXPECT_CALL(blacklistServiceMock,is_blacklisted(_)).WillOnce(Return(true));

        object_under_test.speichern(invalid_person);
        FAIL()<< "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_STREQ("Antipath", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__unexpectected_exception_in_underlying_service__throwsPersonenServiceException) {
    try {
        // Arrange
        person valid_person{"John", "Doe"};

        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::invalid_argument("upps")));
        // Action
        object_under_test.speichern(valid_person);

        // Assertion
        FAIL()<< "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_STREQ("Fehler beim Speichern", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo) {

        // Arrange
        person valid_person{"John", "Doe"};

        EXPECT_CALL(repoMock, save_or_update(valid_person));
        // Action
        object_under_test.speichern(valid_person);

}

TEST_F(personen_service_impl_test, speichern_overloaded__happy_day__captureDemo) {

    InSequence s; // Sorgt dafür, dass wir die Reihenfolge der Mockaufrufe messen koennen.
    // Arrange
    person captured_person;


    EXPECT_CALL(blacklistServiceMock,is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update).WillOnce(DoAll(SaveArg<0>(&captured_person)));



    // Action
    object_under_test.speichern("John","Doe");
    EXPECT_EQ("Doe", captured_person.getNachname());// Expectation von GTEST
    EXPECT_THAT(captured_person.getNachname(), Not(Eq("Musternamm")));// Pendant von GMOCK
    EXPECT_THAT(captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));
}

void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistServiceMock, is_blacklisted(_)).WillByDefault(Return(false));
}
