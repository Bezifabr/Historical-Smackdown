#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
	std::string title;
public:
	void SetTitle(const std::string& title);
	const std::string& GetTitle();
};

#endif // !GAME_H