#pragma once
#include "Item.h"

class Rose : public Item
{
protected:

	bool trojan;

public:

	Rose() : Item()
	{
		trojan = false;
		//isDiscovered = false;
	}

	Rose(bool trojan) : Item()
	{
		this->trojan = trojan;
		//isDiscovered = false;
	}

	~Rose() {}

	void display();

	string getType() { return "R"; }
};