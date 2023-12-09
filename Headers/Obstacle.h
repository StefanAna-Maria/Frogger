#pragma once
#include "Lane.h"

class Obstacle : public Lane
{
public:
    Obstacle(int width);
    void Move() override;
    std::unique_ptr<GameObj> Clone() const override;
};

