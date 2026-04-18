#include "UseAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Core/Player.h"
#include "../../Entity/Concrete/Item.h"
#include "../../Helper/Console.h"
#include <iostream>

UseAction::UseAction()
    : Action(ActionVerbs::Use())
{}

bool UseAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    if (room->GetEntrance(args))
        return m_moveAction.Execute(world, args); // Use entrance → delegate to MoveAction

    Entity* entity = world.GetPlayer().FindEntity(args);
    if (!entity)
    {
        std::cout << Render("You don't have that in your inventory.") << "\n";
        return true;
    }

    Item* item = dynamic_cast<Item*>(entity);
    if (!item || !item->HasUseEffect())
    {
        std::cout << Render("Nothing happens.") << "\n";
        return true;
    }

    if (!item->IsTargetRoom(room))
    {
        std::cout << Render("You can't use that here.") << "\n";
        return true;
    }

    if (!item->Use(world))
        std::cout << Render("Nothing happens.") << "\n";

    return true;
}
