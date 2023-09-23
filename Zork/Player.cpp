#include "Player.h"
#include <algorithm>
#include <iostream>
#include <string>
 Player::Player(Room room):
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
	std::cout << this->roomPosition.first << "--aaaa--" << this->roomPosition.second << "\n";
	if (!this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].hasEvent) {
		std::cout << "Llegas aqui bien? 2 \n";
		this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].defaultEvent();
	}
	else {
		std::cout << "Llegas aqui bien? 3 \n";
		this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].roomEvent(this);
	}


}

void Player::PlayerInteractions() {
	std::string playerInput = "";

	while (playerInput != "up" && playerInput != "down" && playerInput != "right" && playerInput != "left" && playerInput != "pick" && playerInput != "drop") {
		
		//Could use a switch but I feel more comfortable with if chains, and for this type of asignment I prefer what I know best
		std::cout << "\n----------- \n";
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
			std::cout << " Input pick: Pick Item \n";
		if (this->itemList.size() > 0) {
			std::cout << " Input drop: Drop Item \n";
		}	
		std::cout << "-----------\n";
		std::getline(std::cin >> std::ws, playerInput);

		if (playerInput == "pick" && !this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].hasItem) {
			std::cout << "There is no item here \n";
		}
		if (playerInput == "drop" && this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].hasItem) {
			std::cout << "There is already an item here \n";
	
		}
	}

	 if (playerInput == "up" ) {
		 if (!(this->roomPosition.first == 0)) {
			 std::pair<int, int> newPosition{ this->roomPosition.first - 1,this->roomPosition.second };
			 this->Move(newPosition);
		 }
		 else {
			 std::cout << "Wrong Input \n";
		 }
	}
	if (playerInput == "down") {
		if (!(this->roomPosition.first == 2)) {
			std::pair<int, int> newPosition{ this->roomPosition.first + 1,this->roomPosition.second };
			this->Move(newPosition);
		}
		else {
			std::cout << "Wrong Input \n";
		}


	}
	if (playerInput == "right") {
		if (!(this->roomPosition.second == 2)) {
			std::pair<int, int> newPosition{ this->roomPosition.first,this->roomPosition.second+1 };
			this->Move(newPosition);
		}
		else {
			std::cout << "Wrong Input \n";
		}


	}
	if (playerInput == "left" ) {
		if (!(this->roomPosition.second == 0)) {
			std::pair<int, int> newPosition{ this->roomPosition.first,this->roomPosition.second-1 };
			this->Move(newPosition);
		}
		else {
			std::cout << "Wrong Input \n";
		}
	
	}
	playerInput = "";
}


