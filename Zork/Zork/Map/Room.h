#pragma once
#include "../Core/Describable.h"
#include "../Entity/Entity.h"
#include "Entrance.h"
#include <functional>
#include <memory>
#include <set>
#include <vector>

class World;

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

    /// Adds an entrance leading to an adjacent room (takes ownership)
    void AddEntrance(std::unique_ptr<Entrance> entrance);

    /// Returns the entrance matching the given name, or nullptr if not found
    Entrance* GetEntrance(const std::string& entranceName) const;

    /// Returns all entrances
    const std::vector<std::unique_ptr<Entrance>>& GetEntrances() const;

    /// Adds an entity to the room
    void AddEntity(Entity* entity);

    /// Removes an entity from the room
    void RemoveEntity(Entity* entity);

    /// Returns all entities in the room
    const std::vector<Entity*>& GetEntities() const;

    /// Returns one higher than the current highest order value among all describables in the room
    int GetNextOrder() const;

    /// Registers a callback invoked when the player enters this room; from is the room they came from
    void SetOnEntry(std::function<void(World&, Room*)> callback);

    /// Returns true if an entry callback is registered
    bool HasEntryEffect() const;

    /// Executes the entry callback; from is the room the player came from
    void OnEntry(World& world, Room* from) const;

    /// Prints name, description, then all entrances and entities interleaved by order
    void Describe() const override;

private:
    std::multiset<Describable*, DescribableOrderComparator> m_describables; // non-owning; sorted by order for Describe()
    std::vector<std::unique_ptr<Entrance>> m_entrances; // owned by this room
    std::vector<Entity*>   m_entities;  // non-owning; World holds the unique_ptrs that own these
    std::function<void(World&, Room*)> m_onEntry;
};
