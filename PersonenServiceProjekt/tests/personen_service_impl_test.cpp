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
