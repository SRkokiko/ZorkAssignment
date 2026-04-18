#pragma once
#include "../Action.h"

class HelpAction : public Action
{
public:
    HelpAction();
    bool Execute(World& world, const std::string& args) override;
};
