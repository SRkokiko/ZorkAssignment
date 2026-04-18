#include "UseAction.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Core/Player.h"

UseAction::UseAction()
    : Action({ "use" })
{}

bool UseAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
        return false;

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    if (room->GetEntrance(args))
        return m_moveAction.Execute(world, args); // Fallback to move action

    // TODO handle entity use

    return false;
}
