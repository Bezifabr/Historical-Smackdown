#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

class HealthBar {
	sf::Texture fullTexture;
	sf::Texture emptyTexture;
	sf::Sprite full;
	sf::Sprite empty;
public:

	void LoadTextures(const std::string& full, const std::string& empty);
	void Update(int health);
	void Draw(sf::RenderTarget& renderTarget);
};

#endif // !HEALTH_BAR_H
