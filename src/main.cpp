#include "Game.h"
#include "States/IntroState.h"

int main() {

	Game game;
	game.CreateWindow("Historical Smackdown");
	game.Initialize(new IntroState);

	game.RunLoop();

    
	return 0;
}