#pragma once
#include "../Action.h"

class LookAction : public Action
{
public:
    LookAction();
    bool Execute(World& world, const std::string& args) override;
};
