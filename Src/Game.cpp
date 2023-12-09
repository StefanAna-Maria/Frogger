#include "Game.h"
#include "Player.h"
#include "Lane.h"
#include "Obstacle.h"
#include "GameObj.h"
#include "GameException.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

int Game::highScore = 0;
int Game::totalGames = 0;
/*Game::Game(int w = 20, int h = 10) //Constructor
    {
        numberOfLanes = h;
        width = w;
        quit = false;
        for (int i = 0; i < numberOfLanes; i++)
            map.push_back(new Lane(width));
        player = new Player(width);
    }*/
Game::Game(int w, int h) : numberOfLanes(h), width(w), quit(false), player(nullptr), score(0)
{
    srand(time(0));
    for (int i = 0; i < numberOfLanes; i++)
    {
        if (i % 2 == 0)
            //map.push_back(new Lane(width));
            map.push_back(std::make_unique<Lane>(width));
        else
            //map.push_back(new Obstacle(width));
            map.push_back(std::make_unique<Obstacle>(width));
    }
    //player = new Player(width);
    player = std::make_unique<Player>(width);
}

Game::Game(const Game& other) : numberOfLanes(other.numberOfLanes), width(other.width), quit(other.quit), score(other.score)
{
    /*player = new Player(*(other.player));
        for (Lane* lane : other.map)
            map.push_back(new Lane(*lane));
    */
    player = std::make_unique<Player>(*other.player);
    for (const auto& obj : other.map)
        map.push_back(obj->Clone());
}
/*Game::~Game() //Destructor
    {
        delete player;
        for (Lane* lane : map)
            delete lane;
    }
*/
Game::~Game() {}

void Game::Draw()
{
    system("cls");
    for (int i = 0; i < numberOfLanes; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && (j == 0 || j == width - 1))
                std::cout << "S";
            if (i == numberOfLanes - 1 && (j == 0 || j == width - 1))
                std::cout << "F";
            if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1)
                std::cout << "#";
            else if (player->getX() == j && player->getY() == i)
                std::cout << "V";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Score:" << score << std::endl;
}

void Game::Input()
{
    if (_kbhit())
    {
        char current = _getch();
        if (current == 'a')
            player->moveLeft();
        if (current == 'd')
            player->moveRight();
        if (current == 'w')
            player->moveUp();
        if (current == 's')
            player->moveDown();
        if (current == 'q')
            quit = true;
    }
}

void Game::Logic()
{
    for (int i = 0; i < numberOfLanes - 1; i++)
    {
        map[i]->Move();
        if (player->getY() == numberOfLanes - 1)
        {
            score++;
            totalGames = score + 1;
            player->moveUp();
        }
        if (map[i]->CheckPos(player->getX()) && player->getY() == i)
        {
            quit = true;
        }
    }
}

int Game::GetHighScore()
{
    return highScore;
}

int Game::GetTotalGamesPlayed()
{
    return totalGames;
}

void Game::Run()
{
    while (!quit)
    {
        Input();
        Draw();
        Logic();
        Sleep(100);
    }
}
