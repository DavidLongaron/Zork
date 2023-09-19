#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class Item;
class Room : virtual public Entity
{
public:

	Room(const std::string &name, const std::string &description, std::vector<Item*> items );
	virtual ~Room();

	bool hasPlayer;


};

