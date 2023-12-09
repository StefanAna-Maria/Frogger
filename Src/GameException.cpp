#include "GameException.h"

GameException::GameException(const char* msg) : message(msg) {}

const char* GameException::what() const noexcept
{
    return message;
}