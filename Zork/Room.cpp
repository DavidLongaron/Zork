#include "Room.h"
#include <iostream>

Room::Room(const std::string &name, const std::string &description, std::vector<Item*> items) :
	Entity(name,description, NULL, items)
{
	type = ROOM;
	hasPlayer = false;
}

Room::~Room()
{
}