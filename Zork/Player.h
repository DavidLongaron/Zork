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
public:

	Player(Room);
	virtual ~Player();
	void Move(std::pair<int,int>);
	std::pair<int, int> roomPosition;
	std::vector< Item*> itemList{};
	Room currentRoom;
	void PickItem( Item*);
	void DropItem();
	void PutItem();
	void PlayerInteractions();

};

