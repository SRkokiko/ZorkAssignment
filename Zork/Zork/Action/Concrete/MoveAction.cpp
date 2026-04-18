#include "MoveAction.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Map/Entrance.h"
#include "../../Core/Player.h"
#include <iostream>

MoveAction::MoveAction() // Also called directly by UseAction when the target is an entrance, so "use door" and "go door" both resolve through the same logic
    : Action({"go", "walk", "enter"})
{}

bool MoveAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    Room* current = world.GetPlayer().GetCurrentRoom();
    if (!current)
        return false;

    Entrance* entrance = current->GetEntrance(args);
    if (!entrance)
        return false;
    if (entrance->IsLocked())
    {
        std::cout << entrance->GetLockedDescription() << "\n";
        return true;
    }

    Room* next = entrance->GetDestination();
    if (!next)
        return false;

    world.GetPlayer().SetCurrentRoom(next);
    next->Describe();

    return true;
}
