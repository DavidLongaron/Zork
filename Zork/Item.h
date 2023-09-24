#pragma once
#include <string>

class Item {
	public:

	Item(const std::string);
	Item();
	Item(const std::string,bool,  Item*);
	virtual ~Item();
	void SetItemHolded( Item*);
	std::string name;
	bool canHoldItem{false};
	Item* itemHolded{ nullptr };

};

