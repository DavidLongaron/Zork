#pragma once
#include "Entity.h"
class Player :public Entity
{
public:
	Player(const std::string& name, const std::string& description);
	virtual ~Player();

	
	void PickItem(Item*);

	void DropItem(Item*);


};

