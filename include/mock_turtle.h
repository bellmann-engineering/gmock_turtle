#ifndef MOCK_TURTLE_H
#define MOCK_TURTLE_H

#include "turtle.h"
#include <gmock/gmock.h>

class MockTurtle : public Turtle {
public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int distance), (override));
    MOCK_METHOD(void, Turn, (int degrees), (override));
    MOCK_METHOD(std::pair<int, int>, GetPosition, (), (const, override));
};

#endif // MOCK_TURTLE_H
