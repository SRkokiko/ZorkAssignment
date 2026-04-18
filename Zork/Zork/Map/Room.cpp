#include "Room.h"
#include "../Core/World.h"
#include "../Helper/Console.h"
#include <iostream>
#include <algorithm>

Room::Room(const std::string& name, const std::string& description, int order)
    : Describable(name, description, order)
{
}

Room::~Room() = default;

void Room::AddEntrance(std::unique_ptr<Entrance> entrance)
{
    m_describables.insert(entrance.get());
    m_entrances.push_back(std::move(entrance));
}

Entrance* Room::GetEntrance(const std::string& entranceName) const
{
    std::string lowerInput = ToLower(entranceName);
    for (const auto& entrance : m_entrances)
        if (ToLower(entrance->GetName()) == lowerInput)
            return entrance.get();
    return nullptr;
}

const std::vector<std::unique_ptr<Entrance>>& Room::GetEntrances() const
{
    return m_entrances;
}

void Room::AddEntity(Entity* entity)
{
    m_describables.insert(entity);
    m_entities.push_back(entity);
    entity->SetCurrentRoom(this);
}

void Room::RemoveEntity(Entity* entity)
{
    entity->SetCurrentRoom(nullptr);
    auto range = m_describables.equal_range(entity);
    for (auto it = range.first; it != range.second; ++it)
    {
        if (*it == entity)
        {
            m_describables.erase(it);
            break;
        }
    }
    m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), entity), m_entities.end());
}

const std::vector<Entity*>& Room::GetEntities() const
{
    return m_entities;
}

int Room::GetNextOrder() const
{
    if (m_describables.empty())
        return 0;
    return (*m_describables.rbegin())->GetOrder() + 1;
}

void Room::SetOnEntry(std::function<void(World&, Room*)> callback)
{
    m_onEntry = std::move(callback);
}

bool Room::HasEntryEffect() const
{
    return static_cast<bool>(m_onEntry);
}

void Room::OnEntry(World& world, Room* from) const
{
    if (m_onEntry)
        m_onEntry(world, from);
}

void Room::Describe() const
{
    std::cout << Render(m_description) << "\n";

    bool first = true;
    for (const Describable* d : m_describables)
    {
        if (!first) std::cout << "\n";
        d->Describe();
        first = false;
    }
    if (!m_describables.empty())
        std::cout << "\n";
}
