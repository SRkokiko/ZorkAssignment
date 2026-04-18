#include "WorldBuilder.h"
#include "../Map/Room.h"
#include "../Map/Entrance.h"
#include "../Entity/Concrete/Item.h"

// Helper: registers an item with the world and immediately places it in a room
static Item* PlaceItem(std::vector<std::unique_ptr<Item>>& items, Room* room, std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
    Item* raw = items.back().get();
    room->AddEntity(raw);
    return raw;
}

void WorldBuilder::Build(std::list<std::unique_ptr<Room>>& rooms, std::vector<std::unique_ptr<Item>>& items, Room*& startRoom)
{
    // ROOMS
    auto exteriorRoom = std::make_unique<Room>("Exterior", "You are in the {exterior}...");
    Room* exterior = exteriorRoom.get();
    rooms.push_back(std::move(exteriorRoom));
    PlaceItem(items, exterior, std::make_unique<Item>("Book",  "There is a {book} on the ground.", 0));
    PlaceItem(items, exterior, std::make_unique<Item>("Spoon", "Further away, there is a {spoon} on the ground.", 3));

    auto entryHallRoom = std::make_unique<Room>("EntryHall", "You are in the {entry hall}...");
    Room* entryHall = entryHallRoom.get();
    rooms.push_back(std::move(entryHallRoom));

    // ENTRANCES
    auto exteriorDoor = std::make_unique<Entrance>("Door", "There is a {door} at the right.", entryHall, 2);
    //exteriorDoor->Lock("The door is locked.");
    exterior->AddEntrance(std::move(exteriorDoor));

    auto entryHallDoor = std::make_unique<Entrance>("Door", "There is a {door} leading back.", exterior, 2);
    //entryHallDoor->Lock("The door is locked.");
    entryHall->AddEntrance(std::move(entryHallDoor));

    startRoom = exterior;
}
