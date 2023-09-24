#pragma once
#include <vector>
#include "RoomArea.h"

class RoomArea;
class Room {
public:

	Room(std::vector<std::vector<RoomArea>>);
	virtual ~Room();
	std::vector<std::vector<RoomArea>> roomAreas{ };

};

