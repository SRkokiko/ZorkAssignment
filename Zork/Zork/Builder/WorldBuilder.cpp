#include "WorldBuilder.h"
#include "../Map/Room.h"
#include "../Map/Entrance.h"
#include "../Entity/Concrete/Item.h"
#include "../Helper/Console.h"
#include "../Core/World.h"
#include <iostream>

// Registers an item with the world and places it in a room
static Item* PlaceItem(std::vector<std::unique_ptr<Item>>& items, Room* room, std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
    Item* raw = items.back().get();
    room->AddEntity(raw);
    return raw;
}

void WorldBuilder::Build(std::list<std::unique_ptr<Room>>& rooms, std::vector<std::unique_ptr<Item>>& items, Room*& startRoom)
{
    // ── ROOMS ─────────────────────────────────────────────────────────────────

    // EXTERIOR
    auto exteriorRoom = std::make_unique<Room>("EXTERIOR",
        "The mansion rises before you, vast and obscene. Its angles bend in ways your mind refuses to follow, "
        "sliding just beyond comprehension. The structure seems to breathe, its moss-covered walls shifting subtly, "
        "as though alive. A deep, instinctive terror coils in your gut. You should leave. You MUST leave. "
        "And yet... something draws you closer.");
    Room* exterior = exteriorRoom.get();
    rooms.push_back(std::move(exteriorRoom));

    // CORRIDOR
    auto corridorRoom = std::make_unique<Room>("CORRIDOR",
        "A long, narrow corridor stretches before you, vanishing into complete darkness. "
        "The light is weak and trembling. The wooden floor creaks beneath your weight, each step echoing unnaturally far. "
        "A putrid stench of rotten wood fills the air. You freeze in place.");
    Room* corridor = corridorRoom.get();
    rooms.push_back(std::move(corridorRoom));

    // HALL
    auto hallRoom = std::make_unique<Room>("HALL",
        "Hi you are in HALL.");
    Room* hall = hallRoom.get();
    rooms.push_back(std::move(hallRoom));

    // KITCHEN
    auto kitchenRoom = std::make_unique<Room>("KITCHEN",
        "Hi you are in KITCHEN.");
    Room* kitchen = kitchenRoom.get();
    rooms.push_back(std::move(kitchenRoom));

    // END CORRIDOR
    auto endCorridorRoom = std::make_unique<Room>("END CORRIDOR",
        "Only two steps ahead, you stumble into a wall. The corridor ends abruptly.");
    Room* endCorridor = endCorridorRoom.get();
    rooms.push_back(std::move(endCorridorRoom));

    // ── ENTRANCES ─────────────────────────────────────────────────────────────────

    // ── EXTERIOR ENTRANCES ────────────────────────────────────────────────────

    auto exteriorDoorEntrance = std::make_unique<Entrance>("DOOR", "A massive {DOOR} towers before you, far too large to have been made for human use.", corridor, 0);
    exteriorDoorEntrance->Lock("The knob is a grotesque mass of overgrown fungus, soft and glistening, faintly pulsing at your touch. You twist it. The {DOOR} won't budge.");
    Entrance* exteriorDoor = exteriorDoorEntrance.get();
    exterior->AddEntrance(std::move(exteriorDoorEntrance));

    // ── CORRIDOR ENTRANCES ────────────────────────────────────────────────────

    auto corridorDoorEntrance = std::make_unique<Entrance>("DOOR", "Behind you stands a massive wooden {DOOR}, leading out.", exterior, 3);
    corridorDoorEntrance->Lock("The {DOOR} won't open.");
    Entrance* corridorDoor = corridorDoorEntrance.get();
    corridor->AddEntrance(std::move(corridorDoorEntrance));

    auto corridorWhiteDoorEntrance = std::make_unique<Entrance>("WHITE DOOR", "To your right, there is a {WHITE DOOR}. It seems to have been recently painted.", hall, 0);
    Entrance* corridorWhiteDoor = corridorWhiteDoorEntrance.get();
    corridor->AddEntrance(std::move(corridorWhiteDoorEntrance));

    auto corridorHoleEntrance = std::make_unique<Entrance>("HOLE", "To your left lies a human-shaped {HOLE}. As your vision settles in, you realize it perfectly matches your silhouette. Chills run down your spine. What... What on earth?!", kitchen, 1);
    corridorHoleEntrance->Lock("... I am not going that way.");
    Entrance* corridorHole = corridorHoleEntrance.get();
    corridor->AddEntrance(std::move(corridorHoleEntrance));

    auto corridorFurtherEntrance = std::make_unique<Entrance>("FURTHER", "The corridor stretches further into darkness ahead... I could go {FURTHER}...", endCorridor, 2);
    Entrance* corridorFurther = corridorFurtherEntrance.get();
    corridor->AddEntrance(std::move(corridorFurtherEntrance));

    // ── HALL ENTRANCES ────────────────────────────────────────────────────────

    auto hallWhiteDoorEntrance = std::make_unique<Entrance>("WHITE DOOR", "Behind you is a {WHITE DOOR}, leading back to the corridor.", corridor, 0);
    Entrance* hallWhiteDoor = hallWhiteDoorEntrance.get();
    hall->AddEntrance(std::move(hallWhiteDoorEntrance));

    // ── KITCHEN ENTRANCES ─────────────────────────────────────────────────────

    auto kitchenHoleEntrance = std::make_unique<Entrance>("HOLE", "Behind you is a human-shaped {HOLE}, leading back to the corridor.", corridor, 0);
    kitchenHoleEntrance->Lock("... How on earth did I end up here!?");
    Entrance* kitchenHole = kitchenHoleEntrance.get();
    kitchen->AddEntrance(std::move(kitchenHoleEntrance));

    // ── END CORRIDOR ENTRANCES ────────────────────────────────────────────────

    auto endCorridorBackEntrance = std::make_unique<Entrance>("BACK", "Behind you the corridor leads {BACK}.", corridor, 1);
    Entrance* endCorridorBack = endCorridorBackEntrance.get();
    endCorridor->AddEntrance(std::move(endCorridorBackEntrance));


    // ── ITEMS ─────────────────────────────────────────────────────────────────

    // Rusty Key (Exterior) — toggles the Exterior <-> Corridor lock
    Item* rustyKey = PlaceItem(items, exterior, std::make_unique<Item>(
        "RUSTY KEY",
        "A {RUSTY KEY} lies on the ground, set in plain sight... as if waiting for you to notice it.",
        1, true,
        "The {RUSTY KEY} lies on the floor."));

    rustyKey->AddTargetRoom(exterior);
    rustyKey->AddTargetRoom(corridor);
    rustyKey->SetOnUse([exteriorDoor, corridorDoor, exterior](World& world) {
        bool isOutside = world.GetPlayer().GetCurrentRoom() == exterior;
        if (exteriorDoor->IsLocked()) {
            exteriorDoor->Unlock();
            corridorDoor->Unlock();
            if (isOutside)
                std::cout << Render("You push the {RUSTY KEY} through a mass of living fungus. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
            else
                std::cout << Render("You slide the {RUSTY KEY} into the wooden {DOOR}'s keyhole. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
        } else {
            exteriorDoor->Lock("The knob is a grotesque mass of overgrown fungus, soft and glistening, faintly pulsing at your touch. You twist it. The {DOOR} won't budge.");
            corridorDoor->Lock("The {DOOR} won't open.");
            if (isOutside)
                std::cout << Render("You push the {RUSTY KEY} through a mass of living fungus. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
            else
                std::cout << Render("You slide the {RUSTY KEY} into the wooden {DOOR}'s keyhole. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
        }
        return true;
    });

    // Mirror (End Corridor)
    Item* mirror = PlaceItem(items, endCorridor, std::make_unique<Item>(
        "MIRROR",
        "A {MIRROR} hangs on the wall in front of you. It is completely covered in grease, yet you can still make out the faint reflection of an unrecognizable human face. Is... is that me...? Oh god...",
        0, false));

    startRoom = exterior;
}
