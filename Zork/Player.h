#pragma once
#include <utility> 
#include <vector>
class Item;
class Player 
{
public:

	Player();
	virtual ~Player();

	
	void PickItem(Item*);

	void DropItem(const Item*);

	bool HaveItem(const Item*);

	std::pair<int, int> roomPosition;
	std::vector<Item*> itemList{};

};

