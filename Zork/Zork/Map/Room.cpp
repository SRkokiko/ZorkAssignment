#include "Room.h"
#include "../Helper/Console.h"
#include <iostream>
using namespace std;

Room::Room(const string& name, const string& description, int order)
    : Describable(name, description, order)
{
}

Room::~Room()
{
    for (Describable* d : m_describables)
        delete d;
}

void Room::AddEntrance(Entrance* entrance)
{
    m_describables.insert(entrance);
    m_entrances.push_back(entrance);
}

Room* Room::GetAdjacentRoom(const string& entranceName) const
{
    string lowerInput = ToLower(entranceName);
    for (Entrance* entrance : m_entrances)
        if (ToLower(entrance->GetName()) == lowerInput)
            return entrance->GetDestination();
    return nullptr;
}

const vector<Entrance*>& Room::GetEntrances() const
{
    return m_entrances;
}

void Room::AddEntity(Entity* entity)
{
    m_describables.insert(entity);
    m_entities.push_back(entity);
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
