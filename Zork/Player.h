#pragma once
#include <utility> 
#include <vector>
#include "RoomArea.h"
#include "Room.h"
class Item;
class Room;
class Player 
{
public:

	Player(Room*);
	virtual ~Player();

	void Move(std::pair<int,int>);
	void PickItem(Item*);

	void DropItem(const Item*);

	bool HaveItem(const Item*);
	void PlayerInteractions();
	std::pair<int, int> roomPosition;
	std::vector<Item*> itemList{};
	Room* currentRoom;

};

