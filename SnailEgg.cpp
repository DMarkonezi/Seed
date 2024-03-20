#include "SnailEgg.h"

void SnailEgg::display()
{
	cout << "E\t";
}

void SnailEgg::destroyRoses(GameBoard* gameboard, int n, int m)
{
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	Item* tempGrass = new Grass();
		
	for (int i = 0; i < 8; ++i)
	{
		int newX = n + dx[i];
		int newY = m + dy[i];

		// It checks if it is rose and if all other elements that we are going through are valid by the coordinates

		if (gameboard->getFieldElement(n, m)->getType() == "R")
		{
			if (newX >= 0 && newX < gameboard->getDimension() && newY >= 0 && newY < gameboard->getDimension())
			{
				gameboard->setFieldElement(newX, newY, tempGrass);
			}
		}
	}
}

void SnailEgg::reactionToWaterJet(GameBoard* gameboard, int row, int column, int waterStrength)
{
	if (amountOfEggs + waterStrength > 1 && amountOfEggs + waterStrength < 4)
	{
		if (amountOfEggs + waterStrength == 2)
		{
			// It replaces him with the snail

			Item* tempSnail = new Snail();
			gameboard->setFieldElement(row, column, tempSnail);

			destroyRoses(gameboard, row, column);

		}
		else if (amountOfEggs + waterStrength == 3)
		{
			// Trojan snail appears

			Item* tempTrojanSnail = new Snail(true);

			gameboard->setFieldElement(row, column, tempTrojanSnail);

			for (int i = 0; i < 3; i++)
			{
				Item* tempSnail = new Snail();

				//srand(time(NULL));

				int randomRow = rand() % gameboard->getDimension();
				int randomColumn = rand() % gameboard->getDimension();

				gameboard->setFieldElement(randomRow, randomColumn, tempSnail);

				destroyRoses(gameboard, randomRow, randomColumn);

			}
		}
	}
	else
		throw "Invalid sum of attributes in snailEggs::reactToWater function!";

}


