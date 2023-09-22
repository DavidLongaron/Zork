#pragma once
#include <string>
#include <vector>
#include <functional>
#include <iostream>
class Player;
class Item;


class RoomArea
{
 public:

	RoomArea(bool hasEvent,bool hasItem, std::string description, std::function<void(Player*)> eventFunction);

	std::function<void(Player*)> roomEvent;
	void defaultEvent(Player*);
	virtual ~RoomArea();
	bool hasEvent;
	bool hasItem;
	Item* item;
	std::string description;

	
};

