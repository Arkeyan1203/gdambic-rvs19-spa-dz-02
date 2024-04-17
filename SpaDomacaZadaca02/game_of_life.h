#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;

class game_of_life {
public:
	int HEIGHT = 60;
	int WIDTH = 80;
	int get_neighbours(int i, int j);
	bool CURRENT_GEN[60][80];
	bool NEXT_GEN[60][80];
	game_of_life();
	void transition();
	int check_cell(int i, int j);
	void next_gen_init();
	void display(sf::RenderWindow* window);
};

#endif