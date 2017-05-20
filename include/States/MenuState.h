#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"

class MenuState : public State {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	virtual void Load();
	virtual void Update(StatesMachine* statesMachine);
	virtual void Unload();

	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);
};

#endif // !MENU_STATE_H
