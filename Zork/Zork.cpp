// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include "RoomArea.h"
int heroNumber = 83;

RoomArea generateEmptyRoomArea() {
	std::string description = "There is nothing here";
	return RoomArea(false, false, description);
}

void room1DoorEvent(Player* player) {
	std::cout << "An event here";
}

Room createRoom1(){
	std::vector<std::vector<RoomArea*>> room1{ };

	for (int i{ 0 }; i <= 2; ++i) {
		room1.push_back({});
		for (int z{ 0 }; z <= 2; ++z) {
			RoomArea newRoomArea = generateEmptyRoomArea();
			RoomArea* ptrArea = &newRoomArea;
			room1[i].push_back(ptrArea);
			std::cout << room1[i][z]->description << "\n";
			std::cout << i << "\n";
			std::cout << z << "\n";
		}
	}

	Item key = { std::string("Key 1 Room") };
	room1[1][1]->description = "There is a key in the floor";
	room1[1][1]->hasItem = true;
	room1[1][1]->item = &key;
	room1[0][1]->description = "There is a door in front of you";
	room1[0][1]->hasEvent = true;
	room1[0][1]->roomEvent = &room1DoorEvent;
	return room1;
}



void startAdventure() {
	Room room1 = createRoom1();
	Player player{room1.roomAreas[2][0]};
	while (true) {
		player.Move();
	}


}


int main()
{
	startAdventure();


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