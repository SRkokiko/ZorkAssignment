#pragma once
#include "../Action.h"

class TakeAction : public Action
{
public:
    TakeAction();
    bool Execute(World& world, const std::string& args) override;
};
