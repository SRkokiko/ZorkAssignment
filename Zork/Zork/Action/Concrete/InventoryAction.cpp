#include "InventoryAction.h"
#include "../../Core/World.h"
#include "../../Entity/Entity.h"
#include "../../Core/Player.h"
#include <iostream>
using namespace std;

InventoryAction::InventoryAction()
    : Action({"inventory", "i", "items"})
{}

bool InventoryAction::Execute(World& world, const std::string& args)
{
    const auto& inv = world.GetPlayer().GetInventory();
    if (inv.empty())
    {
        cout << "You are carrying nothing.\n";
        return true;
    }

    cout << "You are carrying:\n";
    for (Entity* entity : inv)
        cout << "  - " << entity->GetName() << "\n";
    return true;
}
