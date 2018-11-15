#include "States/OverState.h"
#include "StatesMachine.h"
#include "States/MenuState.h"


void OverState::OnUpdate()
{
}

void OverState::OnDraw()
{
	renderWindow->draw(background);
	renderWindow->draw(winner);
	renderWindow->draw(backToMenuTip);
}

void OverState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed)
		transition->Switch(std::unique_ptr<State>(new MenuState()));
}

void OverState::OnEnter()
{
	textures.Load("background", "screens/EmptyScreen");
	background.setTexture(textures.GetTexture("background"));

	font.loadFromFile("resources/fonts/font.ttf");
	winner.setFont(font);
	backToMenuTip.setFont(font);

	winner.setPosition(400, 600);
	winner.setString(winnersName);

	backToMenuTip.setPosition(100, 700);
	backToMenuTip.setString("Press any key to back to menu");
}

void OverState::OnLeave()
{
}
