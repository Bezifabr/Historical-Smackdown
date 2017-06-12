#include "Controllers\FightingController.h"

void FightingController::SetKey(sf::Keyboard::Key key)
{
	this->key = key;
}

sf::Keyboard::Key FightingController::GetPunchKey()
{
	return key;
}

void FightingController::SetAttackState(CharStateID attackState)
{
	this->fightingState = attackState;
}

CharStateID FightingController::GetAttackState()
{
	return fightingState;
}

sf::Time FightingController::GetAnimationTime()
{
	return animationTime.getElapsedTime();
}

void FightingController::ResetAnimationClock()
{
	animationTime.restart();
}

void FightingController::SetAttackTime(sf::Time time)
{
	this->attackTime = time;
}

sf::Time FightingController::GetAttackTime()
{
	return attackTime;
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
