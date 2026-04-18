#include "Room.h"
#include "../Helper/Console.h"
#include <iostream>
#include <algorithm>
using namespace std;

Room::Room(const string& name, const string& description, int order)
    : Describable(name, description, order)
{
}

Room::~Room() = default;

void Room::AddEntrance(std::unique_ptr<Entrance> entrance)
{
    m_describables.insert(entrance.get());
    m_entrances.push_back(std::move(entrance));
}

Entrance* Room::GetEntrance(const string& entranceName) const
{
    string lowerInput = ToLower(entranceName);
    for (const auto& entrance : m_entrances)
        if (ToLower(entrance->GetName()) == lowerInput)
            return entrance.get();
    return nullptr;
}

const vector<unique_ptr<Entrance>>& Room::GetEntrances() const
{
    return m_entrances;
}

void Room::AddEntity(Entity* entity)
{
    m_describables.insert(entity);
    m_entities.push_back(entity);
}

void Room::RemoveEntity(Entity* entity)
{
    auto range = m_describables.equal_range(entity);
    for (auto it = range.first; it != range.second; ++it)
    {
        if (*it == entity)
        {
            m_describables.erase(it);
            break;
        }
    }
    m_entities.erase(remove(m_entities.begin(), m_entities.end(), entity), m_entities.end());
}

const vector<Entity*>& Room::GetEntities() const
{
    return m_entities;
}

void Room::Describe() const
{
    cout << Bold(m_name) << "\n" << Render(m_description) << "\n";

    bool first = true;
    for (const Describable* d : m_describables)
    {
        if (!first) cout << " ";
        d->Describe();
        first = false;
    }
}
