#pragma once
#include "GameObj.h"
#include <deque>

class Lane : public GameObj
{
private:
    std::deque<bool> cars;

public:
    Lane(int width);
    Lane(const Lane& other);

    void Move() override;
    bool CheckPos(int pos) const override;
    std::unique_ptr<GameObj> Clone() const override;
};

