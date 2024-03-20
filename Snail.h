#pragma once
#include "Item.h"

// Mozda nasledjuje nesto drugo

class Snail : public Item
{
protected:

	bool trojan;

public:

	Snail() : Item()
	{
		trojan = false;
		//sDiscovered = false;
	}

	Snail(bool trojan) : Item()
	{
		this->trojan = trojan;
		//isDiscovered = false;
	}

	~Snail() {}

	void display();

	string getType() { return "S"; }
};