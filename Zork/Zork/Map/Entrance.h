#pragma once
#include "../Core/Describable.h"

class Room;

/// A navigable exit from a room leading to a destination
class Entrance : public Describable
{
public:
    Entrance(const std::string& name, const std::string& description, Room* destination, int order = 0);

    Room* GetDestination() const;

    bool IsLocked() const;
    void Lock(const std::string& lockedDescription = "It's locked.");
    void Unlock();

    const std::string& GetLockedDescription() const;

private:
    Room* m_destination;

    bool m_locked = false;
    std::string m_lockedDescription;
};
