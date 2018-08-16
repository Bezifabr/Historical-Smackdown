#ifndef PUNCH_FIGHTING_H
#define PUNCH_FIGHTING_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "FightingController.h"

class PunchFighting : public FightingController {
	sf::RectangleShape hitBox;
	sf::Vector2f hitBoxPosition;
	float damage;

public:
	void SetDamage(float damage);
	void SetHitBox(sf::FloatRect rect);

	virtual void PerformAttack(Character* attacker, Character* target);
};

#endif // !PUNCH_FIGHTING_H
