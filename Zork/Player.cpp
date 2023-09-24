#include "Player.h"
#define CURRENT_ROOM_AREA this->currentRoom.roomAreas[this->roomPosition.first][this->roomPosition.second]
#define NOT_VALID_INPUTS playerInput != "up" && playerInput != "down" && playerInput != "right" && playerInput != "left" && playerInput != "pick" && playerInput != "drop"&& playerInput != "put"
 Player::Player(Room room):
	 currentRoom{room}
{
}

Player::~Player()
{
}

void Player::PickItem(Item* item){
	itemList.push_back(item);
	std::cout << "You picked a " << item->name << "\n";
	CURRENT_ROOM_AREA.hasItem = false;
	CURRENT_ROOM_AREA.item = nullptr;
}

void Player::DropItem() {

	std::size_t length{ this->itemList.size() };
	int playerInput = - 1;
	bool condition = true;
	while (condition) {
		std::cout << "Which item do you want to drop?: \n";
		for (std::size_t index{ 0 }; index < length; ++index) {
			std::cout << "Input " << index << " to drop:" << this->itemList[index]->name << "\n";
		}

		std::cin >> playerInput;
		if (playerInput>-1 && playerInput<length) {
			condition = false;
		}
	}
	std::cout << "You dropped: " << itemList[playerInput]->name<< "\n";
	CURRENT_ROOM_AREA.hasItem = true;
	CURRENT_ROOM_AREA.item = itemList[playerInput];
	CURRENT_ROOM_AREA.itemDescription = std::string("There is a ") + CURRENT_ROOM_AREA.item->name + std::string(" in the floor\n");
	itemList.erase(itemList.begin() + playerInput);	
}

void Player::PutItem() {

	std::size_t length{ this->itemList.size() };
	int playerInputItem1 = -1;
	int playerInputItem2 = -1;
	bool conditionItem1 = true;
	bool conditionItem2 = true;
	while (conditionItem1) {
		std::cout << "Pick an item to be the holder: \n";
		for (std::size_t index{ 0 }; index < length; ++index) {
				std::cout << "Input " << index << " to choose:" << this->itemList[index]->name << "\n";
		}
		std::cin >> playerInputItem1;
		if (!this->itemList[playerInputItem1]->canHoldItem) {
			std::cout << "This item cannot hold others \n";
			return;
		}
		if (this->itemList[playerInputItem1]->itemHolded != nullptr) {
			std::cout << "There is already an item inside, you take it away \n";
			this->itemList.push_back(this->itemList[playerInputItem1]->itemHolded);
			this->itemList[playerInputItem1]->itemHolded = nullptr;
		}
		if (playerInputItem1 > -1 && playerInputItem1 < length) {
			conditionItem1 = false;
		}
		
	}
	while (conditionItem2) {
		std::cout << "Now pick an item to put inside: \n";
		for (std::size_t index{ 0 }; index < length; ++index) {
			if (this->itemList[index]->itemHolded==nullptr) {
				if (index !=playerInputItem1 ) {
					std::cout << "Input " << index << " to choose:" << this->itemList[index]->name << "\n";
				}
			}
		}
		std::cin >> playerInputItem2;
		if (playerInputItem2 > -1 && playerInputItem2 < length) {
			conditionItem2 = false;
		}
	}
	std::cout << "You put: " << this->itemList[playerInputItem2]->name << " inside "<< this->itemList[playerInputItem1]->name<<"\n";
	 Item* newItem = this->itemList[playerInputItem2];
	this->itemList[playerInputItem1]->setItemHolded(newItem);
	
	this->itemList.erase(itemList.begin() + playerInputItem2);
}



void Player::Move(std::pair<int, int>newRoomPosition) {
	this->roomPosition.first = newRoomPosition.first;
	this->roomPosition.second = newRoomPosition.second;

	if (!CURRENT_ROOM_AREA.hasEvent) {
		CURRENT_ROOM_AREA.defaultEvent();

		if (CURRENT_ROOM_AREA.hasItem) {
			std::cout<<CURRENT_ROOM_AREA.itemDescription;
		}
	}
	else {
		CURRENT_ROOM_AREA.roomEvent(this);

		if (CURRENT_ROOM_AREA.hasItem) {
			std::cout << CURRENT_ROOM_AREA.itemDescription;
		}
	}


}

void Player::PlayerInteractions() {
	std::string playerInput = "";
	
	while (NOT_VALID_INPUTS) {
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
		if (this->itemList.size() > 1) {
			std::cout << " Input put: Put an Item into another \n";
		}
		std::cout << "-----------\n";
		std::getline(std::cin >> std::ws, playerInput);
		if (NOT_VALID_INPUTS) {
			std::cout << "Wrong input\n";
		}
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
	if (playerInput == "put") {
		if (this->itemList.size() > 1) {
			this->PutItem();
		}
		else {
			std::cout << "You dont have enough items\n";
		}
		
	}
	playerInput = "";
}

