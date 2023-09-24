#pragma once
#include <string>

class Item 
{
	public:

	Item(const std::string itemName);
	Item();
	virtual ~Item();

	std::string name;

};

