#include "Player.h"
#include <algorithm>
#include <iostream>
#include <string>

 Player::Player(Room* room):
	 currentRoom{room}
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

void Player::Move(std::pair<int, int>newRoomPosition) {
	this->roomPosition.first = newRoomPosition.first;
	this->roomPosition.second = newRoomPosition.second;
	if (!this->currentRoom->roomAreas[this->roomPosition.first][this->roomPosition.second]->hasEvent) {
		this->currentRoom->roomAreas[this->roomPosition.first][this->roomPosition.second]->defaultEvent(this);
	}
	else {
		this->currentRoom->roomAreas[this->roomPosition.first][this->roomPosition.second]->roomEvent(this);
	}


}

void Player::PlayerInteractions() {
	std::string playerInput = "";

	while (playerInput != "up" && playerInput != "down" && playerInput != "right" && playerInput != "left" && playerInput != "pick" && playerInput != "drop") {
		std::cout << "Llegas bien?";
		
		//Could use a switch but I feel more comfortable with if chains, and for this type of asignment I prefer what I know best
		
		if (this->roomPosition.first > 0) {
			std::cout << " Input up: Go up \n";
		}
		if (this->roomPosition.first < 2) {
			std::cout << " Input down: Go down \n";
		}
		if (this->roomPosition.second < 2) {
			std::cout << " Input right: Go right \n";
		}
		if (this->roomPosition.second > 0) {
			std::cout << " Input left: Go left \n";
		}
		if (this->itemList.size() > 0) {
			std::cout << " Input pick: Pick Item \n";
		}
		if (this->itemList.size() > 0) {
			std::cout << " Input drop: Drop Item \n";
		}
		std::getline(std::cin >> std::ws, playerInput);
		if (playerInput != "up" && playerInput != "down" && playerInput != "right" && 
			playerInput != "left" && playerInput != "pick" && playerInput != "drop" && 
			(playerInput == "up" && this->roomPosition.first==0 )&&
			(playerInput == "down" && this->roomPosition.first == 2)&&
			(playerInput == "right" && this->roomPosition.second == 0)&&
			(playerInput == "left" && this->roomPosition.second == 2)) {

			std::cout << "Wrong Input \n";
			playerInput = "";
		}
		if (playerInput == "pick" && !this->currentRoom->roomAreas[this->roomPosition.first][this->roomPosition.second]->hasItem) {
			std::cout << "There is no item here \n";
			playerInput = "";
		}
		if (playerInput == "drop" && this->currentRoom->roomAreas[this->roomPosition.first][this->roomPosition.second]->hasItem) {
			std::cout << "There is already an item here \n";
			playerInput = "";
		}
	}

	

	if (playerInput == "up") {
		std::pair<int, int> newPosition{ this->roomPosition.first+1,this->roomPosition.second };
		this->Move(newPosition);
	}
	if (playerInput == "down") {
		std::cout << "Por aqui pasas? down  \n";
		std::pair<int, int> newPosition{ this->roomPosition.first-1,this->roomPosition.second };
		this->Move(newPosition);
	}
	if (playerInput == "right") {
		std::pair<int, int> newPosition{ this->roomPosition.first,this->roomPosition.second+1 };
		this->Move(newPosition);
	}
	if (playerInput == "up") {
		std::pair<int, int> newPosition{ this->roomPosition.first ,this->roomPosition.second-1 };
		this->Move(newPosition);
	}
}


