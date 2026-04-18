#pragma once
#include <string>
#include <vector>

class Entity;
class Room;

class Player
{
public:
    Player(const std::string& name);
    ~Player();

    const std::string& GetName() const { return m_name; }

    Room* GetCurrentRoom() const;
    void SetCurrentRoom(Room* room);

    void PickUp(Entity* entity);
    void Drop(Entity* entity);
    Entity* FindEntity(const std::string& name) const;
    const std::vector<Entity*>& GetInventory() const;

private:
    std::string m_name;
    Room* m_currentRoom; // non-owning; World owns rooms via unique_ptr
    std::vector<Entity*> m_inventory;  // non-owning; World owns entities via unique_ptr
};
