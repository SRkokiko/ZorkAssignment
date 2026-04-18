#pragma once
#include "../Entity.h"

class NPC : public Entity
{
public:
    NPC(const std::string& name, const std::string& description, int order = 0, bool pickable = false);
};
