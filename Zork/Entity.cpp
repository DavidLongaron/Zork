#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string &name, const std::string &description, Entity* parent = NULL, std::vector<Item*> items) :
	name{ name }, description{ description }, parent{ parent }, itemList{items}
{
	type = ENTITY;
}
Entity::~Entity()
{}