#pragma once
#include "Item.h"
#include <random>

class Player
{
public:

	int score;

	Player() 
	{
		score = 0;
	}

	~Player() {}

	void waterJet(int dimension, int& n, int& m, int& strength);
	

};
