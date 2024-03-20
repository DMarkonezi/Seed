#include "RoseSeed.h"

void RoseSeed::display()
{
	cout << "S\t";
}

void RoseSeed::reactionToWaterJet(GameBoard* gameboard, int row, int column, int waterStrength)
{
	// It checks if the combination of water strength and value of seeds is valid

	if (amountOfSeed + waterStrength > 1 && amountOfSeed + waterStrength < 5)
	{
		if (amountOfSeed + waterStrength == 2)
		{
			// Rose pops up 

			Item* rose = new Rose();

			gameboard->setFieldElement(row, column, rose);

		}
		else if (amountOfSeed + waterStrength == 3)
		{
			// Is replaced by the grass

			Item* grass = new Grass();

			gameboard->setFieldElement(row, column, grass);

			// Replaces all adjecent elements with seed with value equivalent to the replaced element

			int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
			int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

			Item* tempRoseSeed = new RoseSeed(amountOfSeed); // Create new RoseSeed with the same seed value

			for (int i = 0; i < 8; ++i) 
			{
				int newX = row + dx[i];
				int newY = column + dy[i];

				// It checks if all other elements that we are going through are valid

				if (gameboard->getFieldElement(newX, newY)->getType() == "G") // Replaces only if it is empty, that is, if there is a grass
				{

					if (newX >= 0 && newX < gameboard->getDimension() && newY >= 0 && newY < gameboard->getDimension()) // Checks if the coordinates are of the bound
					{
						gameboard->setFieldElement(newX, newY, tempRoseSeed);
					}

				}
			}
		}
		else if (amountOfSeed + waterStrength == 4)
		{
			// Trojan Rose appears

			Item* tempTrojanRose = new Rose(true);

			gameboard->setFieldElement(row, column, tempTrojanRose);

			// The roses should appear in 3 random places 

			for (int i = 0; i < 3; i++)
			{
				Item* tempRose = new Rose();

				srand(time(NULL));

				int randomRow = rand() % gameboard->getDimension();
				int randomColumn = rand() % gameboard->getDimension();

				gameboard->setFieldElement(randomRow, randomColumn, tempRose);

			}
		}
	}
	else
		throw "Invalid sum of attributes in RoseSeed::reactToWater function!";

}
