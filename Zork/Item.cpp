#include "Item.h"



Item::Item(const std::string itemName) : name{itemName} {};
Item::Item(){}
Item::Item(const std::string itemName, bool canHold, Item* item) : name{ itemName }, canHoldItem{ canHold }, itemHolded{item} {};

Item::~Item() {};

 void Item::setItemHolded( Item* item) {
	this->itemHolded = item;
}