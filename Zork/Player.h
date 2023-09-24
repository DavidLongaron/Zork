#pragma once
#include <utility> 
#include <vector>
#include "RoomArea.h"
#include "Room.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "Item.h"
class Item;
class Room;
class Player 
{
private:

	std::vector<std::string>inputList{ std::string("up"), std::string("down"), std::string("right"), std::string("left"), std::string("pick"), std::string("drop") };


public:

	Player(Room);
	virtual ~Player();
	void Move(std::pair<int,int>);
	std::pair<int, int> roomPosition;
	std::vector<const Item*> itemList{};
	Room currentRoom;
	void PickItem(const Item*);
	void DropItem();
	bool HaveItem(const Item*);
	void PlayerInteractions();

};

