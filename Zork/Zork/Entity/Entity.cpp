#include "Entity.h"

Entity::Entity(const std::string& name, const std::string& description, int order, bool pickable)
    : Describable(name, description, order), m_pickable(pickable)
{
}
