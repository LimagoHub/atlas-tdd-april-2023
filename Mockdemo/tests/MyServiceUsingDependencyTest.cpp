//
// Created by JoachimWagner on 11.04.2023.
//

#include "MyServiceUsingDependencyTest.h"

TEST_F(MyServiceUsingDependencyTest, test1) {
    // Arrange
    // Mock in den Recordmodus versetzen
    auto dependencyMock= std::make_unique<DependencyMock>();
    EXPECT_CALL(*dependencyMock, bar()).WillOnce(Return(5));
    // Danach ist der Mock im Replaymode
    MyServiceUsingDepency object_under_test{std::move(dependencyMock)};

    // Act
    auto result = object_under_test.square();

    // Assertion
    EXPECT_EQ(5, result);
}
TEST_F(MyServiceUsingDependencyTest, test2) {
    // Arrange
    // Mock in den Recordmodus versetzen
    auto dependencyMock= std::make_unique<DependencyMock>();
    EXPECT_CALL(*dependencyMock, foo("Hallo Welt"));
    // Danach ist der Mock im Replaymode

    MyServiceUsingDepency object_under_test{std::move(dependencyMock)};
    // Act
    object_under_test.doIt();

    // Assertion

}

TEST_F(MyServiceUsingDependencyTest, test3) {
    // Arrange
    // Mock in den Recordmodus versetzen
    auto dependencyMock= std::make_unique<DependencyMock>();
    EXPECT_CALL(*dependencyMock, foobar(_)).Times(1).WillRepeatedly(Return(4711));
    MyServiceUsingDepency object_under_test{std::move(dependencyMock)};
    // Danach ist der Mock im Replaymode

    // Act
    EXPECT_EQ(4716,object_under_test.doOtherThing());

    // Assertion

}
