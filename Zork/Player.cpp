#include "Player.h"
#define CURRENT_ROOM_AREA this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second]
 Player::Player(Room room):
	 currentRoom{room}
{
}

Player::~Player()
{
}

void Player::PickItem( Item* item){
	itemList.push_back(item);
	std::cout << "You picked a " << item->name << "\n";
	CURRENT_ROOM_AREA.hasItem = false;
	CURRENT_ROOM_AREA.description = "There is nothing here";
}

void Player::DropItem() {

	std::size_t length{ this->itemList.size() };
	int playerInput = - 1;

	while (playerInput<0 || playerInput>length ) {
		std::cout << "Which item do you want to drop?: \n";
		for (std::size_t index{ 0 }; index < length; ++index) {
			std::cout << "Input " << index << " to drop:" << this->itemList[index]->name << "\n";
		}

		std::cin >> playerInput;


	}
	std::cout << "You dropped: " << itemList[playerInput]->name<< "\n";
	CURRENT_ROOM_AREA.hasItem = true;
	CURRENT_ROOM_AREA.item = itemList[playerInput];
	itemList.erase(itemList.begin() + playerInput);
	
	
}
bool Player::HaveItem(const Item* item) {

	auto test=std::find(itemList.begin(),itemList.end(), item);
	return true;
}

void Player::Move(std::pair<int, int>newRoomPosition) {
	this->roomPosition.first = newRoomPosition.first;
	this->roomPosition.second = newRoomPosition.second;
	std::cout << this->roomPosition.first << "--aaaa--" << this->roomPosition.second << "\n";
	if (!this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].hasEvent) {
		this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second].defaultEvent();
	}
	else {
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
	}

	 if (playerInput == "up" ) {
		 if (!(this->roomPosition.first == 0)) {
			 std::pair<int, int> newPosition{ this->roomPosition.first - 1,this->roomPosition.second };
			 this->Move(newPosition);
		 }
		 else {
			 std::cout << "There is a wall in front of you\n";
		 }
	}
	if (playerInput == "down") {
		if (!(this->roomPosition.first == 2)) {
			std::pair<int, int> newPosition{ this->roomPosition.first + 1,this->roomPosition.second };
			this->Move(newPosition);
		}
		else {
			std::cout << "There is a wall behind you \n";
		}


	}
	if (playerInput == "right") {
		if (!(this->roomPosition.second == 2)) {
			std::pair<int, int> newPosition{ this->roomPosition.first,this->roomPosition.second+1 };
			this->Move(newPosition);
		}
		else {
			std::cout << "There is a wall in your right \n";
		}


	}
	if (playerInput == "left" ) {
		if (!(this->roomPosition.second == 0)) {
			std::pair<int, int> newPosition{ this->roomPosition.first,this->roomPosition.second-1 };
			this->Move(newPosition);
		}
		else {
			std::cout << "There is a wall in your left \n";
		}
	
	}
	if (playerInput == "pick") {
		if (CURRENT_ROOM_AREA.hasItem) {
			this->PickItem(CURRENT_ROOM_AREA.item);
		}
		else {
			std::cout << "There is no item here \n";
		}

	}
	if (playerInput == "drop") {
		if (!CURRENT_ROOM_AREA.hasItem) {
			this->DropItem();
		}
		else {
			std::cout << "There is already an item here \n";
		}

	}
	playerInput = "";
}


