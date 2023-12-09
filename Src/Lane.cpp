#include "GameObj.h"
#include <deque>
#include "Lane.h"

Lane::Lane(int width)
{
    for (int i = 0; i < width; i++)
        cars.push_front(false);
}

Lane::Lane(const Lane& other) : cars(other.cars) {}

void Lane::Move()
{
    if (rand() % 10 == 1)
        cars.push_front(true);
    else
        cars.push_front(false);
    cars.pop_back();
}

bool Lane::CheckPos(int pos) const
{
    return cars[pos];
}

std::unique_ptr<GameObj> Lane::Clone() const
{
    return std::make_unique<Lane>(*this);
}
