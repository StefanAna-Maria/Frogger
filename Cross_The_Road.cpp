#include <iostream>
#include <vector>
#include <deque> 
#include <conio.h>
#include<time.h>

using namespace std;

class Player // Clasa 1
{
private:
	int x, y;
public:
	Player(int width) : x(width / 2), y(0) {} 
	///Player(int width) { x = width / 2; y = 0; } //Constructor initializare
	Player(const Player& other) : x(other.x), y(other.y) {} //Constructor copiere

	int getX() const { return x; }
	int getY() const { return y; }

	void moveLeft() { x--; }
	void moveRight() { x++; }
	void moveUp() { y--; }
	void moveDown() { y++; }
};

class Lane // Clasa 2
{
private:
	deque<bool> cars;
public:
	Lane(int width) //Constructor initializare
	{
		for (int i = 0; i < width; i++)
			cars.push_front(false);

	}
	Lane(const Lane& other) : cars(other.cars) {} // Constructor copiere
	void Move()
	{
		if (rand() % 10 == 1)
			cars.push_front(true);
		else
			cars.push_front(false);
		cars.pop_back();
	}
	bool CheckPos(int pos) 
	{
		return cars[pos]; 
	}
};

class Game // Clasa 3
{
private:
	bool quit;
	int numberOfLanes;
	int width;
	int score;
	Player * player;
	vector <Lane *> map;
public:
	/*Game(int w = 20, int h = 10) //Constructor
	{
		numberOfLanes = h;
		width = w;
		quit = false;
		for (int i = 0; i < numberOfLanes; i++)
			map.push_back(new Lane(width));
		player = new Player(width);
	}*/
	Game(int w = 20, int h = 10) : numberOfLanes(h), width(w), quit(false), player(nullptr) // Constructor initializare
	{
		srand(time(0));
		for (int i = 0; i < numberOfLanes; i++)
			map.push_back(new Lane(width));
		player = new Player(width);
	}

	Game(const Game& other) : numberOfLanes(other.numberOfLanes), width(other.width), quit(other.quit), score(other.score) // Constr copiere
	{
		player = new Player(*(other.player));
		for (Lane* lane : other.map)
			map.push_back(new Lane(*lane));
	}

	~Game() //Destructor
	{
		delete player;
		for (Lane* lane : map)
			delete lane;
	}

	void Draw()
	{
		system("cls");
		for (int i = 0; i < numberOfLanes; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 && (j == 0 || j == width - 1)) cout << "S";
				if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) cout << "F";
				if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1)
					cout << "#"; // # = simbol car
				else if (player->getX() == j && player->getY() == i)
					cout << "V"; // V = simbol player
				else
					cout << " ";
			}
			cout << endl;
		}
		cout << "Score:"<< score << endl;
	}

	void Input()
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

	void Logic()
	{
		for(int i = 0; i < numberOfLanes - 1; i++)
		{
			if (rand() % 10 == 1)
			{
				map[i]->Move();
			}
			/*if (map[i]->CheckPos(player->getX()) && player->getY() == i)
			{
				quit = true;
			}*/ //PROBLEMA!!!
			if (player->getY() == numberOfLanes -1)
			{
				score++;
			//PROBLEMA//	player->getY() = 0;
			}
		}
	}

	void Run()
	{
		while(!quit)
		{
			Input();
			Draw();
			Logic();
		}
	}
};

int main()
{
	/*Lane lane1(20);
	for (int i = 0; i < 20; i++)
	{
		if (lane1.CheckPos(i))
			cout << "1";
		else
			cout << "0";
	}
	lane1.Move();
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		if (lane1.CheckPos(i))
			cout << "1";
		else
			cout << "0";
	}
	lane1.Move();
	lane1.Move();
	lane1.Move();
	lane1.Move();
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		if (lane1.CheckPos(i))
			cout << "1";
		else
			cout << "0";
	}*/
	srand(time(NULL));
	Game game(30, 5);
	game.Run();
	cout << "Game over!" << endl;
	getchar();//
	return 0;
}