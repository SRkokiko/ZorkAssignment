#pragma once
#include <list>
#include <memory>
#include <vector>

class Room;
class Item;
class NPC;

class WorldBuilder
{
public:
    static void Build(std::list<std::unique_ptr<Room>>& rooms, std::vector<std::unique_ptr<Item>>& items, std::vector<std::unique_ptr<NPC>>& npcs, Room*& startRoom);
};
