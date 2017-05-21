#ifndef FIGHTING_CONTROLLER_H
#define FIGHTING_CONTROLLER_H

class Character;

class FightingController {
public:
	virtual void PerformAttack(Character* attacker, Character* target) = 0;
};

#endif // !FIGHTING_CONTROLLER_H
