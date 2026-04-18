#pragma once
#include "../Entity.h"
#include <functional>
#include <vector>

class World;

class Item : public Entity
{
public:
    Item(const std::string& name, const std::string& description, int order = 0, bool pickable = true, const std::string& displacedDescription = "");

    void Describe() const override;

    void AddTargetRoom(Room* room);
    bool IsTargetRoom(Room* room) const;

    bool HasUseEffect() const;
    bool Use(World& world);
    void SetOnUse(std::function<bool(World&)> effect);

private:
    std::string m_displacedDescription;
    std::vector<Room*> m_targetRooms;
    std::function<bool(World&)> m_onUse;
};
