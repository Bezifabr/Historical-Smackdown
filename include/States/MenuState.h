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

private:
	void ProceedMenuOption();

	virtual void OnHandleEvent() override;

	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !MENU_STATE_H
