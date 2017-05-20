#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"

class MenuState : public State {
	sf::Texture playTexture;
	sf::Texture statsTexture;
	sf::Texture exitTexture;
	sf::Sprite sprite;

	int option;
	bool isOptionSelected = false;
public:
	virtual void OnLoad();
	virtual void Unload();

	virtual void Update();
	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);
};

#endif // !MENU_STATE_H
