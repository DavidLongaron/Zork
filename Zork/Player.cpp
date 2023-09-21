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
	itemList.push_back(item);	
}

void Player::DropItem(const Item* item){
	auto itemIndex = find(itemList.begin(), itemList.end(), item);
		if(itemIndex != itemList.end()) {
			__int64 index = itemIndex - itemList.begin();
			itemList.erase(itemList.begin() + index);
		}
	}

bool Player::HaveItem(const Item* item) {

	auto test=std::find(itemList.begin(),itemList.end(), item) != itemList.end();
	return test;
}

