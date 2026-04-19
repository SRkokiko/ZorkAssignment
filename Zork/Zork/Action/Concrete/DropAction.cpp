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
    {
        std::cout << "Drop what?\n";
        return true;
    }

    std::string lower = ToLower(args);
    Entity* entity = world.GetPlayer().FindEntity(lower);
    if (!entity)
    {
        std::cout << "You don't have " << Bold(lower) << ".\n";
        return true;
    }

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    world.GetPlayer().Drop(entity);
    int order = (room == entity->GetOriginalRoom()) ? entity->GetOriginalOrder() : room->GetNextOrder();
    entity->SetOrder(order);
    room->AddEntity(entity);

    std::cout << "Dropped ";
    entity->DescribeName();
    std::cout << ".\n";
    return true;
}
