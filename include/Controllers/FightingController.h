#ifndef FIGHTING_CONTROLLER_H
#define FIGHTING_CONTROLLER_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "CharacterState.h"

class Character;

class FightingController {
	sf::Keyboard::Key key;
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
	CharStateID fightingState;
	sf::Clock animationTime;
	sf::Time attackTime;
public:
	void SetKey(sf::Keyboard::Key key);
	sf::Keyboard::Key GetPunchKey();

	void SetAttackState(CharStateID attackState);
	CharStateID GetAttackState();

	sf::Time GetAnimationTime();
	void ResetAnimationClock();

	void SetAttackTime(sf::Time time);
	sf::Time GetAttackTime();

	void LoadSound(const std::string& soundBufferSource);
	void PlaySound();

	virtual void PerformAttack(Character* attacker, Character* target) = 0;
};

#endif // !FIGHTING_CONTROLLER_H
