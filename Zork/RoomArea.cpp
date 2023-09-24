#include "RoomArea.h"





RoomArea::RoomArea( std::string description, std::function<void(Player*)> eventFunction=NULL) :
	roomEvent(eventFunction),description(description)
{
}

RoomArea::~RoomArea()
{
}

void RoomArea::defaultEvent() {
	std::string description = this->description;
	std::cout << description << "\n";
}