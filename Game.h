#pragma once
#include "Item.h"
#include "Player.h"
#include "RoseSeed.h"
#include "Rose.h"
#include "SnailEgg.h"
#include "Snail.h"
#include "GameBoard.h"
#include <fstream>
#include <string>
#include <time.h>

class Game
{
protected:

	bool isFinished;

	Player* player;
	GameBoard* gameboard;

public:

	Game()
	{
		gameboard = nullptr;

		player = nullptr;

		isFinished = false;
	}

	~Game() 
	{
		delete gameboard;
		delete player;
	}

	void start();
	
	bool finished() { return isFinished; }

	void loadTheData(const char* filename);

	void waterJetAction();

	void displayTheField();

	void end();
};