// Libriary here:

#include "pch.h"
#include <iostream>
#include <conio.h>

bool gameOver;

// Constunt here:

const int WIDTH = 20;
const int HEIGHT = 20;

// Cordinate snake here:

int x;
int y;
int fruitX;
int fruitY;
int score; // score game (счёт)

// Cordinate boll here:

int x_boll;
int y_boll;

// Where does the snake move here:

enum eDerection { STOP = 0, LEFT, RIGHT, UP, DOWN, JUMP };

eDerection dir; // Initialization dir

class My_Game
{
public:
	void Setup()
	{
		// Start settings here:

		gameOver = false;
		dir = STOP;

		x = WIDTH / 2 - 1; // 15
		y = HEIGHT / 2 - 1; // 10

		x_boll = WIDTH / 2 - 1;
		y_boll = 0;

		// x and y fruits here:

		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;

		// score = 0 here:

		score = 0;
	}

	void Main_While()
	{
		// Main While here:

		bool gameOver = false;

		while ( !gameOver )
		{
			Draw();
			Input();
			Logik_Game();
		}
	}

	void Draw()
	{
		system("cls"); // clear display evryday

	    // Draw WINDOW here:

		for (int width = 0; width < WIDTH; width++) // Draw Height Maps here:
		{
			std::cout << "#";
		}

		std::cout << "\n";

		// Darw Maps and Oll Draw here:

		for (int height = 0; height < HEIGHT; height++)
		{
			for (int width = 0; width < WIDTH; width++)
			{
				if (width == 0 || width == WIDTH - 1)
				{
					std::cout << "#";
				}

				// Draw snake here:

				if (height == y && width == x)
				{
					std::cout << "0";
				}

				// Draw fruits here:

				if (height == fruitY && width == fruitX)
				{
					std::cout << "f";
				}

				// Draw bool here:

				if (height == y_boll && width == x_boll)
				{
					std::cout << "%";
				}

				// If boll == wall:

				if (y_boll > 20 - 1)
				{
					y_boll = 0;
					
					// Create new Cordinate boll here:

					x_boll = rand() % WIDTH;
					y_boll = rand() % HEIGHT;
				}

				// If boll attack hero:

				if (x == x_boll && y == y_boll)
				{
					gameOver = true;
				}

				else
				{
					std::cout << ".";
				}
			}

			std::cout << "\n";
		}

		for (int height = 0; height < WIDTH; height++) // Draw Height Maps here:
		{
			std::cout << "#";
		}

		std::cout << "\n";
		std::cout << "Score: " << score << "\n";

		if (score == 10)
		{
			std::cout << "You wins!";
			gameOver = true;
		}
	}

	void Input()
	{
		// What click gamer here:

		if (_kbhit())
		{
			switch ( _getch() )
			{
			case 'a':

				dir = LEFT;
				break;

			case 'd':

				dir = RIGHT;
				break;

			case 'w':

				dir = UP;
				break;

			case 's':

				dir = DOWN;
				break;

			case 'f':

				dir = JUMP;
				break;

			case 'x':

				gameOver = true;
				break;

			}
		}
	}

	void Logik_Game()
	{
		// Logik game here:

		switch (dir)
		{
		case LEFT:
			// If left code here:

			x--; // x -= 1

			break;
		case RIGHT:
			// If right code here:

			x++; // x += 1

			break;
		case UP:
			// IF UP code here:

			y--; // y -= 1

			break;
		case DOWN:
			// If DOWN code here:

			y++; // y += 1

			break;
		case JUMP:

			for (int i = 0; i < 3; i++)
			{
				y--;
				x++;
				break;
			}

			break;
		}

		// Check gameOver snake here:

		if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		{
			std::cout << "You lose!";
			gameOver = true;
		}

		// If snake eat fruit here:

		if (x == fruitX && y == fruitY)
		{
			score += 1;

			// New cordinate fruits here:

			fruitX = rand() % WIDTH;
			fruitY = rand() % HEIGHT;
		}

		if (gameOver == false)
		{
			score = 0;
		}

		y_boll++;
	}
};

int main()
{
	// Main code here:
	// Create new Object here:

	My_Game game; // Created Object (Main) Game class.

	game.Main_While();

	return 0;
}