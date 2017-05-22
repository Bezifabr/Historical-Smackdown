#include "Controllers\FightingController.h"

void FightingController::SetKey(sf::Keyboard::Key key)
{
	this->key = key;
}

sf::Keyboard::Key FightingController::GetPunchKey()
{
	return key;
}

void FightingController::LoadSound(const std::string & soundBufferSource)
{
	soundBuffer.loadFromFile(soundBufferSource);
	sound.setBuffer(soundBuffer);
}

void FightingController::PlaySound()
{
	sound.play();
}
