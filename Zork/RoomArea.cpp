#include "RoomArea.h"





RoomArea::RoomArea( std::string description, std::function<void(Player*)> eventFunction) :
	roomEvent(eventFunction),description(description)
{
}
RoomArea::RoomArea(std::string description) :
	 description(description)
{
}

RoomArea::~RoomArea()
{
}

void RoomArea::defaultEvent() {
	if (!this->hasItem) {
		std::cout << this->description << "\n";
	}
}