#pragma once
#include "../Entity.h"
#include <functional>
#include <vector>

class World;

class Item : public Entity
{
public:
    Item(const std::string& name, const std::string& description, int order = 0, bool pickable = true, const std::string& displacedDescription = "", bool isContainer = false);

    void DescribeName() const override;
    void Describe() const override;

    void AddTargetRoom(Room* room);
    bool IsTargetRoom(Room* room) const;

    bool HasUseEffect() const;
    bool Use(World& world);
    void SetOnUse(std::function<bool(World&)> effect);

    bool IsContainer() const;
    void SetAsContainer();
    void AddContainedItem(Item* item);
    bool RemoveContainedItem(Item* item);
    const std::vector<Item*>& GetContainedItems() const;
    void SetTargetContainer(Item* container);
    Item* GetTargetContainer() const;

    bool IsRemovableFromContainer() const;
    void SetRemovableFromContainer(bool removable);

private:
    std::string m_displacedDescription;
    std::vector<Room*> m_targetRooms;
    std::function<bool(World&)> m_onUse;

    bool m_isContainer = false;
    std::vector<Item*> m_containedItems;
    Item* m_targetContainer = nullptr;
    bool m_removableFromContainer = true;
};
