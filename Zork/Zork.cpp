// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "RoomArea.h"
#include "Player.h"
#include <algorithm>

const Item keyDoor1 = { std::string("Key") };
const Item yellowKeyDoor2 = { std::string("Yellow Key") };
const Item purpleKeyDoor2 = { std::string("Purple Key") };

void emptyFunction(Player* player) {};

Room generateEmptyRoom() {
	std::string description = "There is nothing here";
	std::vector<std::vector<RoomArea>> room{};
	for (int i{ 0 }; i <= 2; ++i) {
		room.push_back({});

		for (int z{ 0 }; z <= 2; ++z) {
			RoomArea newRoomArea = RoomArea(description, emptyFunction);

			room[i].push_back(newRoomArea);
		}
	}


	return room;
}

//Room createSecondRoom() {
//	Room room2 = generateEmptyRoom();
//
//	room2.roomAreas[1][1].itemDescription = std::string("There is a ") + keyDoor1.name + std::string(" in the floor\n");
//	std::cout << room2.roomAreas[1][1].itemDescription;
//	room2.roomAreas[1][1].hasItem = true;
//	room2.roomAreas[1][1].item = &keyDoor1;
//	room2.roomAreas[0][1].description = "There is a door in front of you";
//	room2.roomAreas[0][1].hasEvent = true;
//	room2.roomAreas[0][1].roomEvent = &room1DoorEvent;
//	return room2;
//}



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

void room2DoorEvent(Player* player) {

	if ((player->currentRoom.roomAreas[0][0].hasItem && player->currentRoom.roomAreas[0][0].item == &yellowKeyDoor2)
		&& 
		player->currentRoom.roomAreas[0][2].hasItem && player->currentRoom.roomAreas[0][2].item == &purpleKeyDoor2) {
		std::cout << "The door is already open!\n";
		std::cout << "You move to the next room \n";

	}
	else {
		std::cout << "There is a door in front of you, however you don't see any keyhole or similar\n";
	}

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

//Room createRoom2() {
//
//	std::vector<std::vector<RoomArea>> room2{};
//
//	for (int i{ 0 }; i <= 2; ++i) {
//		room2.push_back({});
//
//		for (int z{ 0 }; z <= 2; ++z) {
//			RoomArea newRoomArea = generateEmptyRoomArea();
//
//			room2[i].push_back(newRoomArea);
//		}
//	}
//
//
//
//	room2[1][1].itemDescription = std::string("There is a ") + keyDoor1.name + std::string(" in the floor\n");
//	std::cout << room1[1][1].itemDescription;
//	room1[1][1].hasItem = true;
//	room1[1][1].item = &keyDoor1;
//	room1[0][1].description = "There is a door in front of you";
//	room1[0][1].hasEvent = true;
//	room1[0][1].roomEvent = &room1DoorEvent;
//	return room1;
//}



void startAdventure(Player& player) {
		player.PlayerInteractions();
}


int main()
{

	Room room1 = createFirstRoom();
	Player  player{ room1 };
	player.roomPosition.first = 2;
	player.roomPosition.second = 1;
	while (true) {

		startAdventure(player);
	}

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln



// 
//void room1Interactions() {
//
//	std::string playerInput ="";
//
//
//	while (playerInput != "Door" && playerInput != "Vases" && playerInput != "Floor") {
//		std::cout << "You see a door at the other side room, a vase in one corner of the room, and in another corner a strange floor tile, what do you want to inspect? \n";
//		std::cout << " Input Door: Check the Door \n";
//		std::cout << " Input Vase: Check the vase \n";
//		std::cout << " Input Floor: Check the  strange floor tile\n";
//		std::getline(std::cin >> std::ws, playerInput);
//
//		if (playerInput != "Door" && playerInput != "Vase" &&  playerInput != "Floor") {
//			std::cout << "Wrong Input \n";
//		}
//	}
//	std::cout << "Good job \n";
//
//
//}
//void room1VaseInteractions() {
//	std::string playerInput = "";
//
//	while (playerInput != "Shake" && playerInput != "Break" && playerInput != "Pick") {
//		std::cout << "You get closer to the vase, what do you want to do? \n";
//		std::cout << " Input Shake: Try to shake the vase \n";
//		std::cout << " Input Break: Try to break the vase \n";
//		std::cout << " Input Pick: Try to take it with you \n";
//		std::getline(std::cin >> std::ws, playerInput);
//		if (playerInput != "Shake" && playerInput != "Break" && playerInput != "Pick") {
//			std::cout << "Wrong Input \n";
//		}
//		else if (playerInput == "Shake") {
//			std::cout << " You shake the vase, you can heard  a metalic sound inside";
//			playerInput = "";
//
//		}
//		else if (playerInput == "Break") {
//			std::cout << "Is a litle bit heavy but you manage to crash the vase against the flood,\n";
//			std::cout << "Between the fragmes you find a key, it seem important so you take it with you \n";
//			playerInput = "";
//			std::cout << "You go back to the start of the room \n";
//
//		}
//	}
//}