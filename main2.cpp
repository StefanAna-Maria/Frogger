#include <iostream>
#include <vector>
#include <deque>
#include <conio.h>
#include <time.h>
#include <memory>
#include <stdexcept>
#include <windows.h>
#include "GameException.h"
#include "GameObj.h"
#include "Player.h"
#include "Lane.h"
#include "Obstacle.h"
#include "Game.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Game::highScore = 0;
	Game::totalGames = 0;
	try
	{
		Game game(30, 5);
		game.Run();
		cout << "Game over!" << endl;
		std::cout << "HighScore: " << Game::GetHighScore() << std::endl;
		std::cout << "Games Played: " << Game::GetTotalGamesPlayed() << std::endl;
	}
	catch (const std::exception& ex)
	{
		cerr << "Exception:" << ex.what() << endl;
	}
	return 0;
}
