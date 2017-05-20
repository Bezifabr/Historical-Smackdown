#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class StatesMachine;
class State {
public:
	virtual void Load(StatesMachine* statesMachine);
	virtual void Update() = 0;
	virtual void Unload();

	virtual void HandleEvent(sf::Event event) = 0;
	virtual void Render(sf::RenderTarget& renderTarget) = 0;

	bool IsGameFinished();
protected:
	virtual void OnLoad() = 0;
	virtual void OnUnload() = 0;

	bool isGameFinished = false; 
	StatesMachine* statesMachine;
};

#endif // !STATE_H
