#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <map>
#include <SFML\Graphics.hpp>
#include "Controllers\MovementController.h"
#include "Controllers\AnimationController.h"

enum class CharStateID { IDLE, WALK };

class Character {
	std::string name;
	sf::Sprite sprite;
	sf::Texture texture;

	AnimationController animationController;
	std::vector<MovementController*> movementControllers;

	CharStateID charStateID;
	std::map<CharStateID, Animation> animations;
public:
	Character(const std::string& name = "") : name(name) {}

	CharStateID GetCharacterState();
	void SetCharacterState(CharStateID charState);

	void AddAnimation(CharStateID charStateID, const Animation& animation);

	void AddMovementController(MovementController* movementController);
	void ClearMovementControllers();

	void PerformMovement(sf::Time deltaTime);
	void PerformAnimation(sf::Time deltaTime);
	
	void LoadTexture(const std::string& filename);
	void Render(sf::RenderTarget& renderTarget);

	void SetName(const std::string& name);
	const std::string& GetName();

	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);

	void MakeFacing(const Character& target);


	const sf::Vector2f& GetPosition() const;
};

#endif // !CHARACTER_H