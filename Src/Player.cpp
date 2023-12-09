#include "Player.h"

Player::Player(int width) : x(width / 2), y(0) {}
Player::Player(const Player& other) : x(other.x), y(other.y) {}

int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::Move(){}

bool Player::CheckPos(int pos) const
{
    return false;
}

std::unique_ptr<GameObj> Player::Clone() const
{
    return std::make_unique<Player>(*this);
}

void Player::moveLeft() { x--; }
void Player::moveRight() { x++; }
void Player::moveUp() { y--; }
void Player::moveDown() { y++; } 

