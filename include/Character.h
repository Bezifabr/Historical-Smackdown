#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <map>
#include <SFML\Graphics.hpp>
#include "Controllers\MovementController.h"
#include "Controllers\AnimationController.h"
#include "Controllers\FightingController.h"

enum class CharStateID { IDLE, WALK, JUMP, DEAD, PUNCH };

class Character {
	std::string name;
	sf::Sprite sprite;
	sf::Texture texture;
	int health;

	AnimationController animationController;
	std::vector<MovementController*> movementControllers;
	std::vector<FightingController*> fightingControllers;

	CharStateID charStateID;
	std::map<CharStateID, Animation> animations;
public:
	Character(const std::string& name = "") : name(name) {}

	void SetCharacterState(CharStateID charState);
	CharStateID GetCurrentState();

	void AddAnimation(CharStateID charStateID, const Animation& animation);

	void AddMovementController(MovementController* movementController);
	void AddFightingController(FightingController* fightingController);

	void ClearMovementControllers();

	void PerformAttack(sf::Event event, Character* target);
	void PerformMovement(sf::Time deltaTime);
	void PerformAnimation(sf::Time deltaTime);
	
	void LoadTexture(const std::string& filename);
	void Render(sf::RenderTarget& renderTarget);

	void SetName(const std::string& name);
	const std::string& GetName();

	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);

	void MakeFacing(const Character& target);

	bool IsCollidingWith(sf::FloatRect rect);

	void SetHealth(int health);
	int GetHealth();

	const sf::Vector2f& GetPosition() const;
};

#endif // !CHARACTER_H