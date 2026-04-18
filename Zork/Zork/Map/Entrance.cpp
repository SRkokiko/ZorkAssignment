#include "Entrance.h"

Entrance::Entrance(const std::string& name, const std::string& description, Room* destination, int order)
    : Describable(name, description, order), m_destination(destination)
{
}

Room* Entrance::GetDestination() const
{
    return m_destination;
}
