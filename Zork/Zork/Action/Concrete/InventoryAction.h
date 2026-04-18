#pragma once
#include "../Action.h"

class InventoryAction : public Action
{
public:
    InventoryAction();
    bool Execute(World& world, const std::string& args) override;
};
