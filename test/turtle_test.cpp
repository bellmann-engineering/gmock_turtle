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



int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
