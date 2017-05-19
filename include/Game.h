#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <string>

class Game {
	std::string title;
	sf::RenderWindow window;
public:
	void SetTitle(const std::string& title);
	void CreateWindow();

	void RunLoop();

};

#endif // !GAME_H