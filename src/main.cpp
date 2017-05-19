#include "Game.h"

int main() {

	Game game;
	game.SetTitle("Historical Smackdown");
	game.CreateWindow();

	game.RunLoop();

    
	return 0;
}