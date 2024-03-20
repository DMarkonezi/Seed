#include "Game.h"

void Game::start()
{
	ifstream inputFile("data.txt");

	int dimension;

	if (inputFile.good())
	{
		inputFile >> dimension;
		
		// It creates the field with only grass

		gameboard = new GameBoard(dimension);

		string type;
		int value, row, column;

		int countElements = 0;

		// TODO check if there is any out of boundary, if for example row or column are bigger than dimension....

		while (!inputFile.eof() && countElements < dimension)
		{
			inputFile >> type;

			// TODO what if we add a function that allows adding even more elements

			if (type == "r")
			{
				inputFile >> value >> row >> column;

				if (gameboard->getFieldElement(row, column) != nullptr) // It checks if there is already a element there
				{
					HatchItem* r = new RoseSeed();

					gameboard->setFieldElement(row, column, r);

					countElements++;
				}
				else
				{
					throw "Error at loading elements: There is already a element here.";
				}

			}
			else 
			if (type == "s")
			{
				inputFile >> row >> column;

				HatchItem* e = new SnailEgg();

				gameboard->setFieldElement(row, column, e);

				countElements++; 
			}
			else
			{
				throw "Error at loading elements: Invalid type of element.";
			}

		}

		inputFile.close();
	}
	else
	{
		throw "Error at loading data.";
	}

	// It creates the player object

	player = new Player();

}

void Game::loadTheData(const char* filename)
{
	ifstream inputFile(filename);

	if (inputFile.good())
	{
		// Loading the rose seed-s or snail egg-s type objects

		// Format: r/s - type, value, row, column

		string type;
		int value, row, column;

		while (inputFile.eof())
		{
			inputFile >> type;

			// TODO what if we add a function that allows adding even more elements

			if (type == "r")
			{
				inputFile >> value >> row >> column;

				if (gameboard->getFieldElement(row, column) != nullptr) // It checks if there is already a element there
				{
					//HatchItem* tmp = new RoseSeed();

					gameboard->setFieldElement(row, column, new RoseSeed());
				}
				else
				{
					throw "Error at loading elements: There is already a element here.";
				}
				
			}
			else if (type == "s")
			{
				inputFile >> row >> column;

				Item* tmp = gameboard->getFieldElement(row, column);
				tmp = new SnailEgg();
			}
			else
			{
				throw "Error at loading elements: Invalid type of element.";
			}

		}

		inputFile.close();

	}
	else
	{
		throw "Error: Didn't load the data from file.";
	}

}

void Game::waterJetAction()
{
	int randomRow = 0, randomCol = 0, randomWaterStrength = 0;

	if (gameboard->counterValue() == gameboard->numberOfFields())
	{
		this->isFinished = true; // Game is finished
	}
	else
	{
		randomRow = 0;
		randomCol = 0; 
		randomWaterStrength = 0;

		// It activates waterJet function that picks random row and column and random water strength
		player->waterJet(gameboard->getDimension(), randomRow, randomCol, randomWaterStrength);

		Item* tempItem = gameboard->getFieldElement(randomRow, randomCol);

		// Checks if it is discovered
		if (tempItem->getDiscovered() == false)
		{
			// It sets the isDiscovered attribute for the Item, when it is found out;
			tempItem->setDiscovered(true);

			if (tempItem->isHatchable() == true)
			{
				HatchItem* ptr = dynamic_cast<HatchItem*>(tempItem);

				ptr->reactionToWaterJet(gameboard, randomRow, randomCol, randomWaterStrength);

			}

			// Incremenents the counter that signilizes when the game is over, that is, when all fields are discovered
			gameboard->incrementCounter();

		}
		else
		{
			cout << "This field element has already been discovered!";
		}
	}
}

void Game::displayTheField()
{
	cout << "Game field: " << endl;

	gameboard->DisplayTheField();
}

void Game::end()
{
	cout << "Congratulations! You have finished the game!" << endl << endl;

	gameboard->printAll();

	player->score = gameboard->numberOfRoses();

	cout << "Your score is: " << player->score;

}
