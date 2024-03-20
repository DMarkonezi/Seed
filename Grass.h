#pragma once
#include "Item.h"

class Grass : public Item
{
public:

	Grass() : Item()
	{
		//isDiscovered = false;
	}

	void display();

	string getType() { return "G"; }
};