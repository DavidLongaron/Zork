#pragma once
#include <string>
#include <vector>
enum EntityType
{
	ENTITY,
	ROOM,
	ITEM,
	PLAYER
};
class Item;


class Entity
{
public:

	Entity(const std::string &name, const std::string &description, Entity* parent, std::vector<Item*> items);
	virtual ~Entity();

	EntityType type;
	std::string name;
	std::string description;

	Entity* parent;
	std::vector<Item*> itemList;
};

