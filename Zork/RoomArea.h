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

	RoomArea(std::string description, std::function<void(Player*)> eventFunction);

	std::function<void(Player*)> roomEvent;
	void defaultEvent();
	virtual ~RoomArea();
	bool hasEvent{false};
	bool hasItem{false};
	Item* item;
	std::string description;

	
};

