#pragma once
#include "../Action.h"

class MoveAction : public Action
{
public:
    MoveAction();
    bool Execute(World& world, const std::string& args) override;
};
