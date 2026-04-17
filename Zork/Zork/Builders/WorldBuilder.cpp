#include "WorldBuilder.h"
#include "FirstRoomBuilder.h"
#include "../Rooms/Room.h"

void WorldBuilder::Build(std::list<Room*>& rooms, Room*& startRoom)
{
    Room* firstRoom = BuildFirstRoom();

    rooms.push_back(firstRoom);
    startRoom = firstRoom;
}
