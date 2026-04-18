#include "WorldBuilder.h"
#include "../Map/Room.h"
#include "../Map/Entrance.h"
#include "../Entity/Entity.h"

void WorldBuilder::Build(std::list<Room*>& rooms, Room*& startRoom)
{   
    // ROOMS
    Room* exterior = new Room("Exterior", "You are in the {exterior}...");
    exterior->AddEntity(new Entity("Book", "There is a {book} on the ground.", 0));
    exterior->AddEntity(new Entity("Spoon", "Further away, there is a {spoon} on the ground.", 3));
    rooms.push_back(exterior);

    Room* entryHall = new Room("EntryHall", "You are in the {entry hall}...");
    rooms.push_back(entryHall);

    // ENTRANCES
    exterior->AddEntrance(new Entrance("Door", "There is a {door} at the right.", entryHall, 2));
    entryHall->AddEntrance(new Entrance("Door", "There is a {door} leading back.", exterior, 2));

    startRoom = exterior;
}
