#include "RoomArea.h"


RoomArea::RoomArea(bool hasEvent, bool hasItem, std::string description, std::function<void(Player*)> eventFunction) :
	roomEvent(eventFunction)
{
	this->hasEvent = hasEvent;
	this->hasItem = hasItem;
	this->description = description;


}

RoomArea::~RoomArea()
{
}