#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include"game_of_life.h"
using namespace std;

game_of_life::game_of_life()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < game_of_life::HEIGHT; ++i)
	{
		for (int j = 0; j < game_of_life::WIDTH; ++j)
		{
			int x = rand() % 4;
			CURRENT_GEN[i][j]=(x==3);
			NEXT_GEN[i][j] = false;
		}
	}
}

int game_of_life::check_cell(int i, int j)
{
	if (i<0 || i>game_of_life::HEIGHT || j<0 || j>game_of_life::WIDTH)
	{
		return 0;
	}
	else
	if(CURRENT_GEN[i][j])
	{
		return 1;
	}
}

int game_of_life::get_neighbours(int i, int j)
{
	int counter = 0;
	for (int x = i - 1; x <= i + 1; ++x)
	{
		for (int y = j - 1; y <= j + 1; ++y)
		{
			if (!(x == i && y == j))
			{
				counter += check_cell(x, y);
			}
		}
	}
	return counter;
}

void game_of_life::next_gen_init()
{
	for (int i = 0; i < game_of_life::HEIGHT; ++i)
	{
		for (int j = 0; j < game_of_life::WIDTH; ++j)
		{
			int neighbours = get_neighbours(i, j);
			if (game_of_life::CURRENT_GEN[i][j])
			{
					NEXT_GEN[i][j] = neighbours == 2 || neighbours == 3;
			}
			else
			{
					NEXT_GEN[i][j] = neighbours == 3;
			}

		}
	}
}

void game_of_life::transition()
{
	for (int i = 0; i < game_of_life::HEIGHT; ++i)
	{
		for (int j = 0; j < game_of_life::WIDTH; ++j)
		{
			CURRENT_GEN[i][j] = NEXT_GEN[i][j];
		}
	}
}

void game_of_life::display(sf::RenderWindow *window)
{

	for (int i = 0; i < game_of_life::HEIGHT; ++i)
	{
		for (int j = 0; j < game_of_life::WIDTH; ++j)
		{
			if (CURRENT_GEN[i][j])
			{
				sf::RectangleShape temp(sf::Vector2f(10.f, 10.f));
				float x = 10.f * j;
				float y = 10.f * i;
				temp.setPosition(x, y);
				window->draw(temp);

			}
		}
	}
}