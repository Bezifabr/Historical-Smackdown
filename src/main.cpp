#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"

int main() {

	Game game;
	game.SetTitle("Historical Smackdown");

	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), game.GetTitle());

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.display();

	}
    
	return 0;
}