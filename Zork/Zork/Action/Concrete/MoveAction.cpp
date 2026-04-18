#include "MoveAction.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"

MoveAction::MoveAction()
    : Action({ "go", "move", "walk", "travel", "head", "run", "enter" })
{}

bool MoveAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    Room* current = world.GetCurrentRoom();
    Room* next = current->GetAdjacentRoom(args);

    if (!next)
        return false;

    world.SetCurrentRoom(next);
    next->Describe();
    return true;
}
