#include "Entrance.h"

Entrance::Entrance(const std::string& name, const std::string& description, Room* destination, int order)
    : Describable(name, description, order), m_destination(destination)
{
}

Room* Entrance::GetDestination() const
{
    return m_destination;
}

bool Entrance::IsLocked() const { 
    return m_locked; 
}

void Entrance::Lock(const std::string& lockedDescription)  { 
    m_locked = true; 
    m_lockedDescription = lockedDescription; 
}

void Entrance::Unlock() { 
    m_locked = false;
}

const std::string& Entrance::GetLockedDescription() const { 
    return m_lockedDescription;
}
