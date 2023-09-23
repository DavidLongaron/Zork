#pragma once
#include <utility> 
#include <vector>
#include "RoomArea.h"
#include "Room.h"
#include <algorithm>
#include <iostream>
#include <string>
class Item;
class Room;
class Player 
{
public:

	Player(Room);
	virtual ~Player();

	void Move(std::pair<int,int>);
	void PickItem(Item*);

	void DropItem(const Item*);

	bool HaveItem(const Item*);
	void PlayerInteractions();
	std::vector<std::string>inputList{ std::string("up"), std::string("down"), std::string("right"), std::string("left"), std::string("pick"), std::string("drop") };
	std::pair<int, int> roomPosition;
	std::vector<Item*> itemList{};
	Room currentRoom;

};

