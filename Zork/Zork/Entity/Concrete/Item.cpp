#include "Item.h"
#include "../../Core/World.h"
#include "../../Helper/Console.h"
#include <iostream>
#include <algorithm>

Item::Item(const std::string& name, const std::string& description, int order, bool pickable, const std::string& displacedDescription, bool isContainer)
    : Entity(name, description, order, pickable), m_displacedDescription(displacedDescription), m_isContainer(isContainer)
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

void Item::DescribeName() const
{
    std::cout << Bold(m_name);
    if (m_isContainer && !m_containedItems.empty())
    {
        std::cout << " (";
        for (size_t i = 0; i < m_containedItems.size(); ++i)
        {
            if (i > 0) std::cout << ", ";
            std::cout << m_containedItems[i]->GetName();
        }
        std::cout << ")";
    }
}

void Item::Describe() const
{
    bool isDisplaced = GetCurrentRoom() != GetOriginalRoom();
    const std::string& desc = (isDisplaced && !m_displacedDescription.empty()) ? m_displacedDescription : GetDescription();
    std::cout << Render(desc);

    if (m_isContainer)
    {
        if (m_containedItems.empty())
        {
            std::cout << " It is empty... Although it yearns to be filled.";
        }
        else
        {
            std::cout << " Contains: ";
            for (size_t i = 0; i < m_containedItems.size(); ++i)
            {
                if (i > 0) std::cout << ", ";
                std::cout << Bold(m_containedItems[i]->GetName());
            }
            std::cout << ".";
        }
    }
}

bool Item::IsContainer() const
{
    return m_isContainer;
}

void Item::SetAsContainer()
{
    m_isContainer = true;
}

void Item::AddContainedItem(Item* item)
{
    m_containedItems.push_back(item);
}

bool Item::RemoveContainedItem(Item* item)
{
    auto it = std::find(m_containedItems.begin(), m_containedItems.end(), item);
    if (it == m_containedItems.end())
        return false;
    m_containedItems.erase(it);
    return true;
}

const std::vector<Item*>& Item::GetContainedItems() const
{
    return m_containedItems;
}

void Item::SetTargetContainer(Item* container)
{
    m_targetContainer = container;
}

Item* Item::GetTargetContainer() const
{
    return m_targetContainer;
}

bool Item::IsRemovableFromContainer() const
{
    return m_removableFromContainer;
}

void Item::SetRemovableFromContainer(bool removable)
{
    m_removableFromContainer = removable;
}
