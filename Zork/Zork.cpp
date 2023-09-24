
#include "Room.h"
#include "Item.h"
#include "RoomArea.h"
#include "Player.h"
#include<windows.h>           

const Item keyDoor1 = { std::string("Key") };
const Item yellowKeyDoor2 = { std::string("Yellow Key") };
const Item purpleKeyDoor2 = { std::string("Purple Key") };
bool gameLoopCondition = true;


Room generateEmptyRoom() {
	std::string description = "There is nothing here";
	std::vector<std::vector<RoomArea>> room{};
	for (int i{ 0 }; i <= 2; ++i) {
		room.push_back({});

		for (int z{ 0 }; z <= 2; ++z) {
			RoomArea newRoomArea = RoomArea(description);

			room[i].push_back(newRoomArea);
		}
	}


	return room;
}

Room createSecondRoom();
Room createThirdRoom();


void room2YellowEvent(Player* player) 
{
	if (player->currentRoom.roomAreas[0][0].hasItem && player->currentRoom.roomAreas[0][0].item == &yellowKeyDoor2) {
		std::cout << "The yellow key fits perfectly in the hole\n";
	}
	else {
		std::cout << "There is a yellow hole in the floor you could drop an item there\n";
	}
}

void room2PurpleEvent(Player* player)
{
	if (player->currentRoom.roomAreas[0][2].hasItem && player->currentRoom.roomAreas[0][2].item == &purpleKeyDoor2) {
		std::cout << "The purple key fits perfectly in the hole\n";
	}
	else {
		std::cout << "There is a purple hole in the floor you could drop an item there\n";
	}
}
void room3Event(Player* player) {
	std::cout << "You find a man, he starts talking to you. \n";
	Sleep(2000);
	std::cout << "Hello, I'm David, the programmer of this test, thank you for playing!\n";
	std::cout << "I hope that even if this was very simple you still find it a bit interesting.\n";
	Sleep(2000);
	std::cout << "And that the code looks good enough!\n";
	Sleep(2000);
	std::cout << "At first I wanted to make a more story focus game, with secret lore.\n";
	std::cout << "But due to the time limit and well being a bit busy in general I had to settle with something simpler\n";
	Sleep(2000);
	std::cout << "I hope that if I get accepted in the master I can make more interesting games!\n";
	std::cout << "Hope to see you soon! \n";
	Sleep(2000);
	std::cout << "\nCongratulations, you finished the game!\n";
	gameLoopCondition = false;
}




void room2DoorEvent(Player* player) {

	if ((player->currentRoom.roomAreas[0][0].hasItem && player->currentRoom.roomAreas[0][0].item == &yellowKeyDoor2)
		&& 
		player->currentRoom.roomAreas[0][2].hasItem && player->currentRoom.roomAreas[0][2].item == &purpleKeyDoor2) {
		std::cout << "The door is already open!\n";
		std::cout << "You move to the next room \n";
		Room room3 = createThirdRoom();
		player->currentRoom = room3;
		player->roomPosition.first = 2;
		player->roomPosition.second = 1;
	}
	else {
		std::cout << "There is a door in front of you, however you don't see any keyhole or similar\n";
	}

}




void room1DoorEvent(Player* player) {
	std::cout << "There is a door in front of you\n";
	auto itemIndex = find(player->itemList.begin(), player->itemList.end(), &keyDoor1);
	if (itemIndex != player->itemList.end()) {
		std::cout << "You use the key to open the door and move towards the next room \n";
		Room room2 = createSecondRoom();
		player->currentRoom=room2;
		player->roomPosition.first = 2;
		player->roomPosition.second = 1;
	}

}


Room createFirstRoom(){

	Room room1 = generateEmptyRoom();

	room1.roomAreas[1][1].itemDescription = std::string("There is a ") + keyDoor1.name + std::string(" in the floor\n");
	room1.roomAreas[1][1].hasItem = true;
	room1.roomAreas[1][1].item = &keyDoor1;
	room1.roomAreas[0][1].hasEvent = true;
	room1.roomAreas[0][1].roomEvent = &room1DoorEvent;
	return room1;
}

Room createSecondRoom() {
	Room room2 = generateEmptyRoom();

	room2.roomAreas[2][0].itemDescription = std::string("There is a ") + yellowKeyDoor2.name + std::string(" in the floor\n");
	room2.roomAreas[2][0].hasItem = true;
	room2.roomAreas[2][0].item = &yellowKeyDoor2;

	room2.roomAreas[2][2].itemDescription = std::string("There is a ") + purpleKeyDoor2.name + std::string(" in the floor\n");
	room2.roomAreas[2][2].hasItem = true;
	room2.roomAreas[2][2].item = &purpleKeyDoor2;


	room2.roomAreas[0][0].hasEvent = true;
	room2.roomAreas[0][0].roomEvent = &room2YellowEvent;

	room2.roomAreas[0][2].hasEvent = true;
	room2.roomAreas[0][2].roomEvent = &room2PurpleEvent;


	room2.roomAreas[1][2].hasEvent = true;
	room2.roomAreas[1][2].roomEvent = &room2DoorEvent;

	return room2;
}

Room createThirdRoom() {
	Room room3 = generateEmptyRoom();

	room3.roomAreas[1][1].hasEvent = true;
	room3.roomAreas[1][1].roomEvent = &room3Event;

	return room3;
}


void startAdventure(Player& player) {
		player.PlayerInteractions();
}


int main()
{

	Room room1 = createFirstRoom();
	Player  player{ room1 };
	player.roomPosition.first = 2;
	player.roomPosition.second = 1;
	std::cout << "Welcome to the Test, advance until the third room and talk with the person waiting there. \n";
	while (gameLoopCondition) {

		startAdventure(player);
	}

}
