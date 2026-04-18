#include "DropAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Entity/Entity.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>

DropAction::DropAction()
    : Action(ActionVerbs::Drop())
{}

bool DropAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    std::string lower = ToLower(args);
    Entity* entity = world.GetPlayer().FindEntity(lower);
    if (!entity)
        return false;

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    world.GetPlayer().Drop(entity);
    int order = (room == entity->GetOriginalRoom()) ? entity->GetOriginalOrder() : room->GetNextOrder();
    entity->SetOrder(order);
    room->AddEntity(entity);

    std::cout << "Dropped " << Bold(entity->GetName()) << "." << "\n";
    return true;
}
