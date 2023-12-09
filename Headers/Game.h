#pragma once
#include <vector>
#include <memory>
#include "GameObj.h"
#include "Player.h"

class Game
{
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    //Player * player;
    //vector <Lane *> map;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<GameObj>> map;

public:
    Game(int w = 20, int h = 10);
    Game(const Game& other);
    ~Game();

    void Draw();
    void Input();
    void Logic();
    void Run();

    static int totalGames;
    static int highScore;

    static int GetHighScore();
    static int GetTotalGamesPlayed();
};
