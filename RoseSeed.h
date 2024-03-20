#pragma once
#include "Item.h"
#include "GameBoard.h"
#include "Rose.h"

class RoseSeed : public HatchItem
{
protected:

	int amountOfSeed;

public:

	RoseSeed()
	{
		// int randNum = rand()%(max-min + 1) + min;

		int tmp = rand() % (2 - 1 + 1) + 1;

		amountOfSeed = tmp;
	}

	RoseSeed(int n)
	{
		if (n > 0 && n < 3)
			amountOfSeed = n;
		else
			throw "Number of seeds in class RoseSeed is invalid!";
	}

	~RoseSeed() {}

	void display();

	string getType() { return "r"; }

	void reactionToWaterJet(GameBoard* gameboard, int row, int column, int waterStrength);

};

