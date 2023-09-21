#pragma once
#include <string>
#include <vector>

class RoomArea;
class Room {
public:

	Room(std::vector<RoomArea>);
	virtual ~Room();

	bool hasPlayer;
	std::vector<RoomArea> roomAreas;


};

