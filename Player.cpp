#include "Player.h"

void Player::waterJet(int dimension, int& n, int& m, int& strength)
{
	srand(time(NULL));

	n = rand() % dimension;
	m = rand() % dimension;
	strength = rand() % (2 - 1 + 1) + 1;
}
