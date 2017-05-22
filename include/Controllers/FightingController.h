#ifndef FIGHTING_CONTROLLER_H
#define FIGHTING_CONTROLLER_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Character;

class FightingController {
	sf::Keyboard::Key key;
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
public:
	void SetKey(sf::Keyboard::Key key);
	sf::Keyboard::Key GetPunchKey();

	void LoadSound(const std::string& soundBufferSource);
	void PlaySound();

	virtual void PerformAttack(Character* attacker, Character* target) = 0;
};

#endif // !FIGHTING_CONTROLLER_H
