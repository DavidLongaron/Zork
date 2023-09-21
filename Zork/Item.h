#pragma once
#include <string>

class Item 
{
	public:

	Item(const std::string itemName);
	virtual ~Item();

	std::string name;

};

