#include "UseAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Core/Player.h"

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
        return m_moveAction.Execute(world, args); // Fallback to move action

    // TODO handle entity use

    return false;
}
