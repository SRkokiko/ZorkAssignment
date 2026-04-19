#include "InventoryAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Entity/Entity.h"
#include "../../Core/Player.h"
#include "../../Helper/Console.h"
#include <iostream>

InventoryAction::InventoryAction()
    : Action(ActionVerbs::Inventory())
{}

bool InventoryAction::Execute(World& world, const std::string& args)
{
    const auto& inv = world.GetPlayer().GetInventory();
    if (inv.empty())
    {
        std::cout << "You are carrying nothing.\n";
        return true;
    }

    std::cout << "You are carrying:\n";
    for (Entity* entity : inv)
    {
        std::cout << "  - ";
        entity->DescribeName();
        std::cout << "\n";
    }
    return true;
}
