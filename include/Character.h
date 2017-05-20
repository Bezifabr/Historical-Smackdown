#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML\Graphics.hpp>

class Character {
	std::string name;
	sf::Sprite sprite;
	sf::Texture texture;

public:
	Character(const std::string& name) : name(name) {}
	Character() {}

	
	void LoadTexture(const std::string& filename);
	void Render(sf::RenderTarget& renderTarget);

	void SetName(const std::string& name);
	const std::string& GetName();

	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);
};

#endif // !CHARACTER_H