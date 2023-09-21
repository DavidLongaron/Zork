// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Player.h"
int heroNumber = 83;


void startAdventure() {

}

void room1Interactions() {

	std::string playerInput ="";


	while (playerInput != "Door" && playerInput != "Vases" && playerInput != "Floor") {
		std::cout << "You see a door at the other side room, a vase in one corner of the room, and in another corner a strange floor tile, what do you want to inspect? \n";
		std::cout << " Input Door: Check the Door \n";
		std::cout << " Input Vase: Check the vase \n";
		std::cout << " Input Floor: Check the  strange floor tile\n";
		std::getline(std::cin >> std::ws, playerInput);

		if (playerInput != "Door" && playerInput != "Vase" &&  playerInput != "Floor") {
			std::cout << "Wrong Input \n";
		}
	}
	std::cout << "Good job \n";


}
void room1VaseInteractions() {
	std::string playerInput = "";

	while (playerInput != "Shake" && playerInput != "Break" && playerInput != "Pick") {
		std::cout << "You get closer to the vase, what do you want to do? \n";
		std::cout << " Input Shake: Try to shake the vase \n";
		std::cout << " Input Break: Try to break the vase \n";
		std::cout << " Input Pick: Try to take it with you \n";
		std::getline(std::cin >> std::ws, playerInput);
		if (playerInput != "Shake" && playerInput != "Break" && playerInput != "Pick") {
			std::cout << "Wrong Input \n";
		}
		else if (playerInput == "Shake") {
			std::cout << " You shake the vase, you can heard  a metalic sound inside";
			playerInput = "";

		}
		else if (playerInput == "Break") {
			std::cout << "Is a litle bit heavy but you manage to crash the vase against the flood,\n";
			std::cout << "Between the fragmes you find a key, it seem important so you take it with you \n";
			playerInput = "";
			std::cout << "You go back to the start of the room \n";

		}
	}
}

int main()
{
	room1Interactions();

	//std::cout << "You are the" << heroNumber << " hero to finally arrive to the tower where someone is being held captured, you enter the first room \n";
	//std::cout << " Now what do you want to do?";
	//
	//Room Room1{"Room 1","A quite small room, not a lot of things that catch your attention",};




 //   std::cout << "Hello World!\n";
	//std::vector<int> list{ 1,45,20,2,98 };
	//
	//auto itemIndex = find(list.begin(), list.end(), 45);
	//__int64 index = itemIndex - list.begin();
	//list.erase(list.begin() + index);

	//std::cout << list[index] << "\n" << list.size();
	//	
	/*if (itemIndex != Entity::itemList.end()) {
		int index = itemIndex - Entity::itemList.begin();
		Entity::itemList.erase(Entity::itemList.begin() + index);
	}
	*/
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
