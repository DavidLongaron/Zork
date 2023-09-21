#include "Player.h"
#include <algorithm>
#include <iostream>
 Player::Player()
{
}

Player::~Player()
{
}

void Player::PickItem( Item* item){
	Entity::itemList.push_back(item);	
}

void Player::DropItem(const Item* item){
	auto itemIndex = find(Entity::itemList.begin(), Entity::itemList.end(), item);
		if(itemIndex != Entity::itemList.end()) {
			__int64 index = itemIndex - Entity::itemList.begin();
			Entity::itemList.erase(Entity::itemList.begin() + index);
		}
	}

bool Player::HaveItem(const Item* item) {

	auto test=std::find(Entity::itemList.begin(), Entity::itemList.end(), item) != Entity::itemList.end();
	std::cout << test;
	return true;
}

