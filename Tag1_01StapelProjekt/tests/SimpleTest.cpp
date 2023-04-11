//
// Created by JoachimWagner on 11.04.2023.
//


#include "gtest/gtest.h"

TEST(MyTest, Demo) {
    // Arrange (Vorbereitung der zu testenden Komponente
    // Action (DIE Methode ausgeführt die zu testen ist
    // Assertion Erwartungswerte prüfen
    ASSERT_EQ(2,1);
    EXPECT_EQ(2,1);
    EXPECT_EQ(2,1);
}