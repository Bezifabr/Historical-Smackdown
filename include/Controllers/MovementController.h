#ifndef MOVEMENT_CONTROLLER_H
#define MOVEMENT_CONTROLLER_H

#include <SFML/Window/Event.hpp>

class Character;

class MovementController {
public:
	virtual void PerformMovement(Character* movingCharacter, sf::Time deltaTime) = 0;

};



#endif // !MOVEMENT_CONTROLLER_H
