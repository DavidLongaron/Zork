#pragma once
#include <utility> 
#include <vector>
class Item;
class Player 
{
public:

	Player();
	virtual ~Player();

	void Move(std::pair<int,int>);
	void PickItem(Item*);

	void DropItem(const Item*);

	bool HaveItem(const Item*);

	std::pair<int, int> roomPosition;
	std::vector<Item*> itemList{};

};

