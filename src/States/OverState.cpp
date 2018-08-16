#include "States/OverState.h"
#include "StatesMachine.h"
#include "States/MenuState.h"

void OverState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
		statesMachine->Change(new MenuState);
}

void OverState::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(background);
	renderTarget.draw(winner);
	renderTarget.draw(backToMenuTip);
}

void OverState::OnUpdate()
{
}

void OverState::OnLoad()
{
	backgroundTexture.loadFromFile("resources/textures/screens/EmptyScreen.png");
	background.setTexture(backgroundTexture);

	font.loadFromFile("resources/fonts/font.ttf");
	winner.setFont(font);
	backToMenuTip.setFont(font);

	winner.setPosition(400, 600);
	winner.setString(winnersName);

	backToMenuTip.setPosition(100, 700);
	backToMenuTip.setString("Press any key to back to menu");


}

void OverState::OnUnload()
{
}
