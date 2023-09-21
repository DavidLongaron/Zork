#pragma once
#include <string>
#include <vector>

class RoomArea;
class Room {
public:

	Room(std::vector<std::vector<RoomArea*>>);
	virtual ~Room();

	bool hasPlayer{ false};
	std::vector<std::vector<RoomArea*>> roomAreas{ };


};

