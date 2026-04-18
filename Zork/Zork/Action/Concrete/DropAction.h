#pragma once
#include "../Action.h"

class DropAction : public Action
{
public:
    DropAction();
    bool Execute(World& world, const std::string& args) override;
};
