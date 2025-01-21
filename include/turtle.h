#ifndef TURTLE_H
#define TURTLE_H

#include <utility>

class Turtle {
public:
    virtual ~Turtle() = default;
    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Backward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual std::pair<int, int> GetPosition() const = 0;
};

#endif // TURTLE_H
