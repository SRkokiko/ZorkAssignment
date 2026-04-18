#pragma once
#include <list>

class Room;

class WorldBuilder
{
public:
    static void Build(std::list<Room*>& rooms, Room*& startRoom);
};
