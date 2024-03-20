#include "GameBoard.h"

void GameBoard::DisplayTheField() 
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (field[i][j]->getDiscovered())
			{
				field[i][j]->display();
			}
			else
				cout << "X\t";
		}

		cout << endl << endl;
	}
}

int GameBoard::numberOfRoses()
{
	int result;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (field[i][j]->getType() == "R")
			{
				result++;
			}
		}
	}

	return result;
}

void GameBoard::printAll()
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			field[i][j]->display();	
		}

		cout << endl << endl;
	}
}
