#include "Item.h"

Item::Item(const std::string& name, const std::string& description, int order, bool pickable)
    : Entity(name, description, order, pickable)
{
}
