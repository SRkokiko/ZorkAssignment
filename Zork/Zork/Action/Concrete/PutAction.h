#pragma once
#include "../Action.h"

class PutAction : public Action
{
public:
    PutAction();
    bool Execute(World& world, const std::string& args) override;
};
