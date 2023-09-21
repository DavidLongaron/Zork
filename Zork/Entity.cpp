#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string &name, std::vector<Item*> items) :
	name{ name }, itemList{items}
{
	type = ENTITY;
}
Entity::~Entity()
{}