#pragma once 
#include "Grass.h"
#include "HatchItem.h"
#include <random>

class HatchItem;

class GameBoard
{
protected:

	Item*** field;

	int dim;

	int fieldsDiscovered;

public:

	GameBoard()
	{
		field = nullptr;
		dim = 0;
		fieldsDiscovered = 0;
	}

	GameBoard(int n)
	{
		fieldsDiscovered = 0;

		dim = n;

		field = new Item * *[dim];

		for (int i = 0; i < dim; ++i)
			field[i] = new Item * [dim];

		// It only has grass at the beginning but it later adds seeds and eggs

		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				field[i][j] = new Grass();

	}

	~GameBoard() 
	{
		for (int i = 0; i < dim; ++i) 
		{
			for (int j = 0; j < dim; ++j) 
			{
				delete field[i][j];
			}
			
			delete[] field[i];
		}
		
		delete[] field;
	}

	// Getters and setters

	int getDimension() { return dim; }
	void setDimension(int n) { dim = n; }

	void incrementCounter() { fieldsDiscovered++; }
	int counterValue() { return fieldsDiscovered; }
	int numberOfFields() { return dim * dim; }

	Item* getFieldElement(int n, int m)
	{
		return field[n][m];
	}

	void setFieldElement(int n, int m, Item* el)
	{
		field[n][m] = el;
	}

	void DisplayTheField();

	void printAll();

	int numberOfRoses();

};
