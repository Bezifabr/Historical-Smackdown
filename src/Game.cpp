#include "..\include\Game.h"

void Game::SetTitle(const std::string & title)
{
	this->title = title;
}

const std::string& Game::GetTitle()
{
	return title;
}
