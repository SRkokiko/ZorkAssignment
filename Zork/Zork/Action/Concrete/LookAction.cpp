#include "LookAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Map/Room.h"
#include "../../Core/Player.h"

LookAction::LookAction()
    : Action(ActionVerbs::Look())
{}

bool LookAction::Execute(World& world, const std::string& args)
{
    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    room->Describe();
    return true;
}
