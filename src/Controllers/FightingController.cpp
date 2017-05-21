#include "Controllers\FightingController.h"

void FightingController::SetKey(sf::Keyboard::Key key)
{
	this->key = key;
}

sf::Keyboard::Key FightingController::GetPunchKey()
{
	return key;
}
