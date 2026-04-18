#include "DropAction.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Entity/Entity.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>
using namespace std;

DropAction::DropAction()
    : Action({"drop"})
{}

bool DropAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    string lower = ToLower(args);
    Entity* entity = world.GetPlayer().FindEntity(lower);
    if (!entity)
        return false;

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    world.GetPlayer().Drop(entity);
    room->AddEntity(entity);

    cout << "Dropped.\n";
    return true;
}
