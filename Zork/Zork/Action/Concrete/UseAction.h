#pragma once
#include "../Action.h"
#include "MoveAction.h"

class UseAction : public Action
{
public:
    UseAction();
    bool Execute(World& world, const std::string& args) override;

private:
    MoveAction m_moveAction;
};
