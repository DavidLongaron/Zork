#include "Player.h"

 Player::Player(const std::string& name, const std::string& description) :
	 Entity(name, description, NULL, {})
{

}

Player::~Player()
{
}

Player::PickItem(Item* item){
	Entity::itemList.push_back(item);	
}

Player::DropItem(Item* item){
	auto itemIndex= find(Entity::itemList.begin(), Entity::itemList.end(), item)
	if(itemIndex != Entity::itemList.end()){
		int index = itemIndex- Entity::itemList.begin();
		Entity::itemList.erase(Entity::itemList.begin()+index);
	}
}
