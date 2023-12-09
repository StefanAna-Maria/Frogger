#pragma once
#include <exception>

class GameException : public std::exception
{
private:
    const char* message;

public:
    GameException(const char* msg);
    const char* what() const noexcept override;
};

