#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <string>

class Game {
	std::string title;
	sf::RenderWindow window;
public:
	void CreateWindow(const std::string& title);

	void RunLoop();

};

#endif // !GAME_H