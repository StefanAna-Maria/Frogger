#pragma once
#include "GameObj.h"

class Player : public GameObj
{
private:
    int x, y;

public:
    Player(int width);
    Player(const Player& other);

    int getX() const;
    int getY() const;

    void Move() override;
    bool CheckPos(int pos) const override;
    std::unique_ptr<GameObj> Clone() const override;

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

