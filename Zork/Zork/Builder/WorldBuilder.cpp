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
    auto exteriorRoom = std::make_unique<Room>("EXTERIOR", 
    "The mansion rises before you, vast and obscene. Its angles bend in ways your mind refuses to follow, "
    "sliding just beyond comprehension. The structure seems to breathe, its moss-covered walls shifting subtly, "
    "as though alive. A deep, instinctive terror coils in your gut. You should leave. You MUST leave. "
    "And yet... something draws you closer.");
    Room* exterior = exteriorRoom.get();
    rooms.push_back(std::move(exteriorRoom));
    PlaceItem(items, exterior, std::make_unique<Item>("RUSTY KEY", "A {RUSTY KEY} lies on the ground, set in plain sight... as if waiting for you to notice it.", 1, true, "The {RUSTY KEY} lies on the floor."));

    auto entryHallRoom = std::make_unique<Room>("ENTRY HALL", "You are in the {ENTRY HALL}...");
    Room* entryHall = entryHallRoom.get();
    rooms.push_back(std::move(entryHallRoom));

    // ENTRANCES
    auto exteriorDoor = std::make_unique<Entrance>("DOOR","A massive {DOOR} towers before you, far too large to have been made for human use.", entryHall ,0);
    exteriorDoor->Lock("The knob is a grotesque mass of overgrown fungus, soft and glistening, faintly pulsing at your touch. You twist it. The {DOOR} won't budge.");
    exterior->AddEntrance(std::move(exteriorDoor));

    auto entryHallDoor = std::make_unique<Entrance>("DOOR", "There is a {DOOR} leading back.", exterior, 2);
    entryHallDoor->Lock("The {DOOR} is locked.");
    entryHall->AddEntrance(std::move(entryHallDoor));

    startRoom = exterior;
}
