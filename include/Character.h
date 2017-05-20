#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML\Graphics.hpp>
#include "MovementController.h"

class Character {
	std::string name;
	sf::Sprite sprite;
	sf::Texture texture;

	MovementController* movementController;
public:
	Character(const std::string& name = "") : name(name) {}

	void SetMovementController(MovementController* movementController);

	void PerformMovement(sf::Time deltaTime);
	
	void LoadTexture(const std::string& filename);
	void Render(sf::RenderTarget& renderTarget);

	void SetName(const std::string& name);
	const std::string& GetName();

	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);

	sf::Vector2f GetPosition();
};

#endif // !CHARACTER_H