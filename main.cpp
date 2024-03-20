#include "Game.h"

int main()
{

	Game* game = new Game();

	game->start();

	game->displayTheField();

	while(game->finished() == false)
	{
		game->waterJetAction(); 

		game->displayTheField();
	}

	game->end();

	return 0;

}