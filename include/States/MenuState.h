#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "Menu.h"
#include "State.h"

class MenuState : public State {
	sf::Texture playTexture;
	sf::Texture statsTexture;
	sf::Texture exitTexture;
	sf::Sprite sprite;

	Menu menu;
public:
	virtual void OnLoad();
	virtual void OnUnload();

	virtual void Update();
	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);

private:
	void ProceedMenuOption();
};

#endif // !MENU_STATE_H
