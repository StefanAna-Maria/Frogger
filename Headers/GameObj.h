#pragma once
#include <memory>

class GameObj
{
public:
    virtual void Move() = 0;
    virtual bool CheckPos(int pos) const = 0;
    virtual std::unique_ptr<GameObj> Clone() const = 0; // smart pointers
    virtual ~GameObj();
};

