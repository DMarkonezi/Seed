#pragma once
#include "Item.h"
#include "GameBoard.h"

class GameBoard;


class HatchItem : public Item
{
public:

	HatchItem()
	{
		hatch = true;
	}

	~HatchItem() {}

	virtual void reactionToWaterJet(GameBoard* gameboard, int row, int column, int waterStrength);

};