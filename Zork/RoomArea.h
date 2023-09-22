#pragma once
#include <string>
#include <vector>
#include <functional>
class Player;
class Item;


class RoomArea
{
 public:

	RoomArea(bool hasEvent,bool hasItem, std::string description, std::function<void(Player*)> eventFunction=NULL);

	std::function<void(Player*)> roomEvent;
	virtual ~RoomArea();
	bool hasEvent;
	bool hasItem;
	Item* item;
	std::string description;


};

