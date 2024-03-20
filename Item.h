#pragma once
#include <iostream>
#include <string>
using namespace std;

class Item
{
protected:

	bool isDiscovered;
	bool hatch;

public:

	Item()
	{
		isDiscovered = false;
		hatch = false;
	}

	bool getDiscovered() { return isDiscovered; }

	bool isHatchable() { return hatch; }

	void setDiscovered(bool n) { isDiscovered = n; }

	virtual void display();

	virtual string getType()
	{
		return "I";
	}

};