#ifndef GAME_H
#define GAME_H

#include "StatesMachine.h"
#include <SFML/Graphics.hpp>
#include <string>


class Game {
	StatesMachine statesMachine;
	sf::RenderWindow window;
public:
	void CreateWindow(const std::string& title);
	void Initialize(State* initState);

	void RunLoop();

};

#endif // !GAME_H