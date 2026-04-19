#include "TakeAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Entity/Entity.h"
#include "../../Entity/Concrete/Item.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>

TakeAction::TakeAction()
    : Action(ActionVerbs::Take())
{}

bool TakeAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
    {
        std::cout << "Take what?\n";
        return true;
    }

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    std::string lower = ToLower(args);

    // Handle "take X from Y"
    size_t sepPos = lower.find(" from ");
    if (sepPos != std::string::npos)
    {
        std::string itemName = lower.substr(0, sepPos);
        std::string containerName = lower.substr(sepPos + 6);

        if (itemName.empty() || containerName.empty())
            return false;

        Item* container = nullptr;
        for (Entity* e : room->GetEntities())
        {
            if (ToLower(e->GetName()) == containerName)
            {
                container = dynamic_cast<Item*>(e);
                break;
            }
        }
        if (!container)
        {
            Entity* invEntity = world.GetPlayer().FindEntity(containerName);
            if (invEntity)
                container = dynamic_cast<Item*>(invEntity);
        }

        if (!container || !container->IsContainer())
        {
            std::cout << Render("You can't take anything from that.") << "\n";
            return true;
        }

        Item* found = nullptr;
        for (Item* contained : container->GetContainedItems())
        {
            if (ToLower(contained->GetName()) == itemName)
            {
                found = contained;
                break;
            }
        }

        if (!found)
        {
            std::cout << Render("That item isn't in there.") << "\n";
            return true;
        }

        if (!found->IsRemovableFromContainer())
        {
            std::cout << Render("You can't take that out of there.") << "\n";
            return true;
        }

        container->RemoveContainedItem(found);
        world.GetPlayer().PickUp(found);

        std::cout << "Taken ";
        found->DescribeName();
        std::cout << ".\n";
        return true;
    }

    // Standard take from room
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
    {
        std::cout << "I don't see " << Bold(lower) << " here.\n";
        return true;
    }

    if (!match->IsPickable())
    {
        std::cout << Render("You can't pick that up.") << "\n";
        return true;
    }

    room->RemoveEntity(match);
    world.GetPlayer().PickUp(match);

    std::cout << "Taken ";
    match->DescribeName();
    std::cout << ".\n";
    return true;
}
