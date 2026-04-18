#include "TakeAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Entity/Entity.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>

TakeAction::TakeAction()
    : Action(ActionVerbs::Take())
{}

bool TakeAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    std::string lower = ToLower(args);

    Entity* match = nullptr;
    for (Entity* entity : room->GetEntities())
    {
        if (ToLower(entity->GetName()) == lower)
        {
            match = entity;
            break;
        }
    }

    if (!match)
        return false;

    if (!match->IsPickable())
    {
        std::cout << "You can't pick that up.\n";
        return true;
    }

    room->RemoveEntity(match);
    world.GetPlayer().PickUp(match);

    std::cout << "Taken " << Bold(match->GetName()) << "." << "\n";
    return true;
}
