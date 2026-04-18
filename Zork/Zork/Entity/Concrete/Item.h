#pragma once
#include "../Entity.h"

class Item : public Entity
{
public:
    Item(const std::string& name, const std::string& description, int order = 0, bool pickable = true);
};
