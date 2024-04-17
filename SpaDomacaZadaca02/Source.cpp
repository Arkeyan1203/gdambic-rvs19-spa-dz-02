#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "game_of_life.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	game_of_life game;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		game.display(&window);
		window.display();
		game.next_gen_init();
		game.transition();
		sf::sleep(sf::milliseconds(2000));
	}

	return 0;
}