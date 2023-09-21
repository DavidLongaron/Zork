#pragma once
#include "Entity.h"
class Player :public Entity
{
public:
	Player();
	virtual ~Player();

	
	void PickItem(Item*);

	void DropItem(const Item*);

	bool HaveItem(const Item*);
};

