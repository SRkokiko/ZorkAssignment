#include "PutAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Entity/Concrete/Item.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>

PutAction::PutAction()
    : Action(ActionVerbs::Put())
{}

bool PutAction::Execute(World& world, const std::string& args)
{
    std::string lower = ToLower(args);
    size_t sepPos = lower.find(" into ");
    size_t sepLen = 6;
    if (sepPos == std::string::npos)
    {
        sepPos = lower.find(" in ");
        sepLen = 4;
    }
    if (sepPos == std::string::npos)
    {
            std::cout << "Put it where?\n";
        return true;
    }

    std::string itemName = lower.substr(0, sepPos);
    std::string containerName = lower.substr(sepPos + sepLen);

    if (itemName.empty() || containerName.empty())
        return false;

    Player& player = world.GetPlayer();
    Room* room = player.GetCurrentRoom();
    if (!room)
        return false;

    Entity* itemEntity = player.FindEntity(itemName);
    if (!itemEntity)
    {
        std::cout << "You don't have " << Bold(itemName) << ".\n";
        return true;
    }

    Item* item = dynamic_cast<Item*>(itemEntity);
    if (!item)
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
        Entity* invEntity = player.FindEntity(containerName);
        if (invEntity)
            container = dynamic_cast<Item*>(invEntity);
    }

    if (!container)
    {
        std::cout << "You can't find " << Bold(containerName) << ".\n";
        return true;
    }

    if (!container->IsContainer())
    {
        container->DescribeName();
        std::cout << " can't hold items.\n";
        return true;
    }

    if (item->GetTargetContainer() != container)
    {
        item->DescribeName();
        std::cout << " doesn't belong in ";
        container->DescribeName();
        std::cout << ".\n";
        return true;
    }

    player.Drop(item);
    container->AddContainedItem(item);

    std::cout << "You put ";
    item->DescribeName();
    std::cout << " into ";
    container->DescribeName();
    std::cout << ".\n";
    return true;
}
