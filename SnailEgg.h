#pragma once
#include "Item.h"
#include "Grass.h"
#include "HatchItem.h"
#include "Snail.h"

class GameBoard;

class SnailEgg : public HatchItem
{
protected:

	int amountOfEggs;

public:

	SnailEgg()
	{
		amountOfEggs = 1;
	}

	~SnailEgg() {}

	void display();

	string getType() { return "s";}

	void destroyRoses(GameBoard* gameboard, int n, int m);

	void reactionToWaterJet(GameBoard* gameboard, int row, int column, int waterStrength);
};