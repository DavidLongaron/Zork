#pragma once
#include <vector>

class Player;
class Room;
class World
{
public:

	World();
	~World();

	void GameLoop();


private: 
	std::vector<Room*> rooms;
	Player* player;
};
