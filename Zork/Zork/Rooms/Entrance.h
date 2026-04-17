#pragma once
#include "../Core/Describable.h"

class Room;

/// A navigable exit from a room leading to a destination
class Entrance : public Describable
{
public:
    Entrance(const std::string& name, const std::string& description, Room* destination, int order = 0);

    Room* GetDestination() const;

private:
    Room* m_destination;
};
