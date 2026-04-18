#include "Player.h"
#include "../Entity/Entity.h"
#include "../Map/Room.h"
#include "../Helper/Console.h"
#include <algorithm>
using namespace std;

Player::Player(const std::string& name)
    : m_name(name), m_currentRoom(nullptr)
{}

Room* Player::GetCurrentRoom() const
{
    return m_currentRoom;
}

void Player::SetCurrentRoom(Room* room)
{
    m_currentRoom = room;
}

Player::~Player()
{
    // Inventory holds non-owning pointers; World is responsible for entity lifetime
}

void Player::PickUp(Entity* entity)
{
    m_inventory.push_back(entity);
}

void Player::Drop(Entity* entity)
{
    m_inventory.erase(remove(m_inventory.begin(), m_inventory.end(), entity), m_inventory.end());
}

Entity* Player::FindEntity(const std::string& name) const
{
    string lower = ToLower(name);
    for (Entity* entity : m_inventory)
        if (ToLower(entity->GetName()) == lower)
            return entity;
    return nullptr;
}

const vector<Entity*>& Player::GetInventory() const
{
    return m_inventory;
}
