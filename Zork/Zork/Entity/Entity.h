#pragma once
#include "../Core/Describable.h"

/// An entity that can exist inside a Room
class Entity : public Describable
{
public:
    Entity(const std::string& name, const std::string& description, int order = 0);
};
