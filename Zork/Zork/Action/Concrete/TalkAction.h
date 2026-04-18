#pragma once
#include "../Action.h"

class TalkAction : public Action
{
public:
    TalkAction();
    bool Execute(World& world, const std::string& args) override;
};
