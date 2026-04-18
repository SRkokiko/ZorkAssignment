#include "TakeAction.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Entity/Entity.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>
using namespace std;

TakeAction::TakeAction()
    : Action({"take", "get", "pick"})
{}

bool TakeAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;
   

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    string lower = ToLower(args);

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
        cout << "You can't pick that up.\n";
        return true;
    }

    room->RemoveEntity(match);
    world.GetPlayer().PickUp(match);

    cout << "Taken.\n";
    return true;
}
