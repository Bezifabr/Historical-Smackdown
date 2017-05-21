#ifndef FIGHTING_CONTROLLER_H
#define FIGHTING_CONTROLLER_H

#include <SFML/Window/Keyboard.hpp>

class Character;

class FightingController {
	sf::Keyboard::Key key;
public:
	void SetKey(sf::Keyboard::Key key);
	sf::Keyboard::Key GetPunchKey();

	virtual void PerformAttack(Character* attacker, Character* target) = 0;
};

#endif // !FIGHTING_CONTROLLER_H
