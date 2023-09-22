#include "RoomArea.h"





RoomArea::RoomArea(bool hasEvent, bool hasItem, std::string description, std::function<void(Player*)> eventFunction=NULL) :
	roomEvent(eventFunction)
{
	this->hasEvent = hasEvent;
	this->hasItem = hasItem;
	this->description = description;


}

RoomArea::~RoomArea()
{
}

void RoomArea::defaultEvent(Player* player) {
	std::string description = this->description;
	std::cout << description << "\n";
}