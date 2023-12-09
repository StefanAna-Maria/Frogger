#include "Obstacle.h"

Obstacle::Obstacle(int width) : Lane(width) {}

void Obstacle::Move()
{
    // Miscare zigzag
    Lane::Move();
    if (rand() % 2 == 0)
        Lane::Move();
}

std::unique_ptr<GameObj> Obstacle::Clone() const
{
    return std::make_unique<Obstacle>(*this);
}
