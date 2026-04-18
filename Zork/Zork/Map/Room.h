#pragma once
#include "../Core/Describable.h"
#include "../Entity/Entity.h"
#include "Entrance.h"
#include <set>
#include <vector>

struct DescribableOrderComparator
{
    bool operator()(const Describable* a, const Describable* b) const
    {
        return a->GetOrder() < b->GetOrder();
    }
};

/// A location containing entrances to adjacent rooms and entities
class Room : public Describable
{
public:
    Room(const std::string& name, const std::string& description, int order = 0);
    ~Room();

    /// Adds an entrance leading to an adjacent room
    void AddEntrance(Entrance* entrance);

    /// Returns the destination room of the entrance matching the given name, or nullptr if not found
    Room* GetAdjacentRoom(const std::string& entranceName) const;

    /// Returns all entrances
    const std::vector<Entrance*>& GetEntrances() const;

    /// Adds an entity to the room
    void AddEntity(Entity* entity);

    /// Returns all entities in the room
    const std::vector<Entity*>& GetEntities() const;

    /// Prints name, description, then all entrances and entities interleaved by order
    void Describe() const override;

private:
    std::multiset<Describable*, DescribableOrderComparator> m_describables; // owns all, sorted by order for Describe() -> this could be a unique ptr!
    std::vector<Entrance*> m_entrances; // non-owning, for typed access
    std::vector<Entity*>   m_entities;  // non-owning, for typed access
};
