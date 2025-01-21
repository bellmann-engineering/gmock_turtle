#include "mock_turtle.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;

TEST(TurtleTest, MovesCorrectly) {
    MockTurtle mockTurtle;

    // Set up expectations
    EXPECT_CALL(mockTurtle, PenDown())
        .Times(1);
    EXPECT_CALL(mockTurtle, Forward(10))
        .Times(1);
    EXPECT_CALL(mockTurtle, Turn(90))
        .Times(1);
    EXPECT_CALL(mockTurtle, GetPosition())
        .WillOnce(Return(std::make_pair(10, 0)));

    // Simulate the turtle actions
    mockTurtle.PenDown();
    mockTurtle.Forward(10);
    mockTurtle.Turn(90);
    auto position = mockTurtle.GetPosition();

    // Verify position
    EXPECT_EQ(position, std::make_pair(10, 0));
}

TEST(TurtleTest, MovesBackwardCorrectly) {
    MockTurtle mockTurtle;

    // Set up expectations
    EXPECT_CALL(mockTurtle, PenUp())
        .Times(1);
    EXPECT_CALL(mockTurtle, Backward(5))
        .Times(1);
    EXPECT_CALL(mockTurtle, Turn(45))
        .Times(1);
    EXPECT_CALL(mockTurtle, GetPosition())
        .WillOnce(Return(std::make_pair(-5, 0)));

    // Simulate the turtle actions
    mockTurtle.PenUp();
    mockTurtle.Backward(5);
    mockTurtle.Turn(45);
    auto position = mockTurtle.GetPosition();

    // Verify position
    EXPECT_EQ(position, std::make_pair(-5, 0));
}

TEST(TurtleTest, HandlesGenericArguments) {
    MockTurtle mockTurtle;

    // Set up expectations with generic arguments
    EXPECT_CALL(mockTurtle, Forward(_))
        .Times(1);
    EXPECT_CALL(mockTurtle, Turn(_))
        .Times(1);
    EXPECT_CALL(mockTurtle, GetPosition())
        .WillOnce(Return(std::make_pair(0, 10)));

    // Simulate the turtle actions
    mockTurtle.Forward(15); // Argument doesn't have to match a specific value
    mockTurtle.Turn(60);    // Argument doesn't have to match a specific value
    auto position = mockTurtle.GetPosition();

    // Verify position
    EXPECT_EQ(position, std::make_pair(0, 10));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
