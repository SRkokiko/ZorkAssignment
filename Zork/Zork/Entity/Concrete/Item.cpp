#include "Item.h"
#include "../../Core/World.h"
#include "../../Helper/Console.h"
#include <iostream>
#include <algorithm>

Item::Item(const std::string& name, const std::string& description, int order, bool pickable, const std::string& displacedDescription)
    : Entity(name, description, order, pickable), m_displacedDescription(displacedDescription)
{
}

void Item::AddTargetRoom(Room* room)
{
    m_targetRooms.push_back(room);
}

bool Item::IsTargetRoom(Room* room) const
{
    if (m_targetRooms.empty())
        return true;
    return std::find(m_targetRooms.begin(), m_targetRooms.end(), room) != m_targetRooms.end();
}

bool Item::HasUseEffect() const
{
    return (bool)m_onUse;
}

bool Item::Use(World& world)
{
    return m_onUse ? m_onUse(world) : false;
}

void Item::SetOnUse(std::function<bool(World&)> effect)
{
    m_onUse = std::move(effect);
}

void Item::Describe() const
{
    bool isDisplaced = GetCurrentRoom() != GetOriginalRoom();
    const std::string& desc = (isDisplaced && !m_displacedDescription.empty()) ? m_displacedDescription : GetDescription();
    std::cout << Render(desc);
}
