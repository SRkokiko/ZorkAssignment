#pragma once
#include "../Core/Describable.h"

class Room;

/// An entity that can exist inside a Room
class Entity : public Describable
{
public:
    Entity(const std::string& name, const std::string& description, int order = 0, bool pickable = false);

    bool IsPickable() const { return m_pickable; }

    Room* GetCurrentRoom() const { return m_currentRoom; }
    Room* GetOriginalRoom() const { return m_originalRoom; }
    int GetOriginalOrder() const { return m_originalOrder; }

    void SetCurrentRoom(Room* room)
    {
        if (!m_originalRoom && room)
        {
            m_originalRoom = room;
            m_originalOrder = GetOrder();
        }
        m_currentRoom = room;
    }

private:
    bool m_pickable;
    Room* m_currentRoom = nullptr;
    Room* m_originalRoom = nullptr;
    int m_originalOrder = 0;
};
