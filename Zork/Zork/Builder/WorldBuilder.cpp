#include "WorldBuilder.h"
#include "../Map/Room.h"
#include "../Map/Entrance.h"
#include "../Entity/Concrete/Item.h"
#include "../Entity/Concrete/NPC.h"
#include "../Helper/Console.h"
#include "../Core/World.h"
#include <iostream>


void WorldBuilder::Build(std::list<std::unique_ptr<Room>>& rooms, std::vector<std::unique_ptr<Item>>& items, std::vector<std::unique_ptr<NPC>>& npcs, Room*& startRoom)
{
    // ── ROOMS ─────────────────────────────────────────────────────────────────
    
    // FOREST
    auto forestRoom = std::make_unique<Room>("FOREST", "...");
    Room* forest = forestRoom.get();
    rooms.push_back(std::move(forestRoom));

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
        "A long, narrow corridor stretches before you, vanishing into complete darkness.");
    Room* corridor = corridorRoom.get();
    rooms.push_back(std::move(corridorRoom));

    // HALL
    auto hallRoom = std::make_unique<Room>("HALL",
        "The room is wrong. Not in any way you can point to - just wrong. It stretches far beyond what the mansion "
        "could ever contain, larger than anything that has any right to exist indoors.The walls are dotted with "
        "windows, yet none of them seem to show the outside they should. "
        "At the center, a fireplace burns with a light that does not flicker - powerful and absolute, the kind of "
        "heat that would reduce you to nothing. Luckily it lies far away. Still, you find yourself unwilling to "
        "look at it directly. The room offers nothing else to rest your eyes on - nothing, except a single chair near you... " 
        "And someone is sitting in it.");
    Room* hall = hallRoom.get();
    rooms.push_back(std::move(hallRoom));

    // ABYSS
    auto abyssRoom = std::make_unique<Room>("ABYSS", "...");
    Room* abyss = abyssRoom.get();
    rooms.push_back(std::move(abyssRoom));

    // END CORRIDOR
    auto endCorridorRoom = std::make_unique<Room>("END CORRIDOR",
        "Only two steps ahead, you stumble into a wall. The corridor ends abruptly.");
    Room* endCorridor = endCorridorRoom.get();
    rooms.push_back(std::move(endCorridorRoom));

    // MIRRORED CORRIDOR
    auto mirroredCorridorRoom = std::make_unique<Room>("MIRRORED CORRIDOR",
        "You step back into the corridor.");
    Room* mirroredCorridor = mirroredCorridorRoom.get();
    rooms.push_back(std::move(mirroredCorridorRoom));

    // KITCHEN
    auto kitchenRoom = std::make_unique<Room>("KITCHEN",
        "You find yourself back in the woods. Wh- What? ...\n\n"
        "The trees are tall and quiet, their branches letting through just enough light to see by. Moss covers "
        "everything. The air smells of pine and rain. It is, despite everything, peaceful. "
        "A worn wooden table sits among the roots, set as though someone knew you were coming."
        " It is full of ingredients. ");
    Room* kitchen = kitchenRoom.get();
    rooms.push_back(std::move(kitchenRoom));

    // ── ENTRANCES ─────────────────────────────────────────────────────────────────

    // EXTERIOR ENTRANCES 
    auto exteriorDoorEntrance = std::make_unique<Entrance>("DOOR", "A massive {DOOR} towers before you, far too large to have been made for human use.", corridor, 0);
    exteriorDoorEntrance->Lock("The knob is a grotesque mass of overgrown fungus, soft and glistening, faintly pulsing at your touch. You twist it. The {DOOR} won't budge.");
    Entrance* exteriorDoor = exteriorDoorEntrance.get();
    exterior->AddEntrance(std::move(exteriorDoorEntrance));

    auto exteriorForestPathEntrance = std::make_unique<Entrance>("FOREST", "I cou- I could always go back into the {FOREST}...", forest, 2);
    exterior->AddEntrance(std::move(exteriorForestPathEntrance));

    // CORRIDOR ENTRANCES
    auto corridorDoorEntrance = std::make_unique<Entrance>("DOOR", "Behind you stands a massive wooden {DOOR}, leading out.", exterior, 3);
    corridorDoorEntrance->Lock("The {DOOR} won't open.");
    Entrance* corridorDoor = corridorDoorEntrance.get();
    corridor->AddEntrance(std::move(corridorDoorEntrance));

    auto corridorWhiteDoorEntrance = std::make_unique<Entrance>("WHITE DOOR", "To your right, there is a {WHITE DOOR}. It seems to have been recently painted.", hall, 0);
    Entrance* corridorWhiteDoor = corridorWhiteDoorEntrance.get();
    corridor->AddEntrance(std::move(corridorWhiteDoorEntrance));

    auto corridorHoleEntrance = std::make_unique<Entrance>("HOLE", "To your left lies a human-shaped {HOLE}. As your vision settles in, you realize it perfectly matches your silhouette. Chills run down your spine. What... What on earth?!", abyss, 1);
    corridorHoleEntrance->Lock("... I am not going that way.");
    Entrance* corridorHole = corridorHoleEntrance.get();
    corridor->AddEntrance(std::move(corridorHoleEntrance));

    auto corridorFurtherEntrance = std::make_unique<Entrance>("FURTHER", "The corridor stretches further into darkness ahead... I could go {FURTHER}...", endCorridor, 2);
    Entrance* corridorFurther = corridorFurtherEntrance.get();
    corridor->AddEntrance(std::move(corridorFurtherEntrance));

    // HALL ENTRANCES
    auto hallWhiteDoorEntrance = std::make_unique<Entrance>("WHITE DOOR", "Behind you is a {WHITE DOOR}, leading back to the corridor.", corridor, 1);
    Entrance* hallWhiteDoor = hallWhiteDoorEntrance.get();
    hall->AddEntrance(std::move(hallWhiteDoorEntrance));

    // KITCHEN ENTRANCES
    auto kitchenRoomHallEntrance = std::make_unique<Entrance>("DOOR", "Behind you, a plain {DOOR} hangs in open air, attached to nothing.", hall, 7);
    kitchen->AddEntrance(std::move(kitchenRoomHallEntrance));

    auto kitchenRoomDeepEntrance = std::make_unique<Entrance>("DEEPER", "You could try wandering {DEEPER} into the woods.", hall, 8);
    kitchenRoomDeepEntrance->Lock("You cannot walk far in any direction. You don't know why. Your feet simply refuse. You turn back.");
    kitchen->AddEntrance(std::move(kitchenRoomDeepEntrance));

    // ABYSS ENTRANCES
    auto abyssHoleEntrance = std::make_unique<Entrance>("HOLE", "Behind you is a human-shaped {HOLE}, leading back to the corridor.", corridor, 0);
    abyssHoleEntrance->Lock("... How on earth did I end up here!?");
    Entrance* abyssHole = abyssHoleEntrance.get();
    abyss->AddEntrance(std::move(abyssHoleEntrance));

    // END CORRIDOR ENTRANCES
    auto endCorridorBackEntrance = std::make_unique<Entrance>("BACK", "Behind you the corridor leads {BACK}.", mirroredCorridor, 1);
    Entrance* endCorridorBack = endCorridorBackEntrance.get();
    endCorridor->AddEntrance(std::move(endCorridorBackEntrance));

    // MIRRORED CORRIDOR ENTRANCES
    auto mirroredCorridorDoorEntrance = std::make_unique<Entrance>("DOOR", "In front of you stands a massive wooden {DOOR}, leading out.", exterior, 0);
    mirroredCorridorDoorEntrance->Lock("The {DOOR} won't open.");
    Entrance* mirroredCorridorDoor = mirroredCorridorDoorEntrance.get();
    mirroredCorridor->AddEntrance(std::move(mirroredCorridorDoorEntrance));

    auto mirroredCorridorWhiteDoorEntrance = std::make_unique<Entrance>("WHITE DOOR", "To your left, there is a {WHITE DOOR}. It seems to have been recently painted.", hall, 1);
    Entrance* mirroredCorridorWhiteDoor = mirroredCorridorWhiteDoorEntrance.get();
    mirroredCorridor->AddEntrance(std::move(mirroredCorridorWhiteDoorEntrance));

    auto mirroredCorridorHoleEntrance = std::make_unique<Entrance>("HOLE", "To your right lies a human-shaped {HOLE}. As your vision settles in, you realize it perfectly matches your silhouette. Chills run down your spine. What... What on earth?!", abyss, 2);
    mirroredCorridorHoleEntrance->Lock("... I am not going that way.");
    Entrance* mirroredCorridorHole = mirroredCorridorHoleEntrance.get();
    mirroredCorridor->AddEntrance(std::move(mirroredCorridorHoleEntrance));

    auto mirroredCorridorFurtherEntrance = std::make_unique<Entrance>("BACK", "I could also go {BACK}...", endCorridor, 3);
    Entrance* mirroredCorridorFurther = mirroredCorridorFurtherEntrance.get();
    mirroredCorridor->AddEntrance(std::move(mirroredCorridorFurtherEntrance));

    // ── ITEMS ─────────────────────────────────────────────────────────────────

    // Rusty Key (Exterior) — toggles the Exterior <-> Corridor lock
    items.push_back(std::make_unique<Item>(
        "RUSTY KEY",
        "A {RUSTY KEY} lies on the ground, set in plain sight... as if waiting for you to notice it.",
        1, true,
        "The {RUSTY KEY} lies on the floor."));
    Item* rustyKey = items.back().get();
    exterior->AddEntity(rustyKey);

    rustyKey->AddTargetRoom(exterior);
    rustyKey->AddTargetRoom(corridor);
    rustyKey->AddTargetRoom(mirroredCorridor);
    rustyKey->SetOnUse([exteriorDoor, corridorDoor, mirroredCorridorDoor, exterior](World& world) {
        bool isOutside = world.GetPlayer().GetCurrentRoom() == exterior;
        if (exteriorDoor->IsLocked()) {
            exteriorDoor->Unlock();
            corridorDoor->Unlock();
            mirroredCorridorDoor->Unlock();
            if (isOutside)
                std::cout << Render("You push the {RUSTY KEY} through a mass of living fungus. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
            else
                std::cout << Render("You slide the {RUSTY KEY} into the wooden {DOOR}'s keyhole. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
        } else {
            exteriorDoor->Lock("The knob is a grotesque mass of overgrown fungus, soft and glistening, faintly pulsing at your touch. You twist it. The {DOOR} won't budge.");
            corridorDoor->Lock("The {DOOR} won't open.");
            mirroredCorridorDoor->Lock("The {DOOR} won't open.");
            if (isOutside)
                std::cout << Render("You push the {RUSTY KEY} through a mass of living fungus. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
            else
                std::cout << Render("You slide the {RUSTY KEY} into the wooden {DOOR}'s keyhole. The {DOOR} creaks, followed by a heavy, resonant click.") << "\n";
        }
        return true;
    });

    // Mirror (End Corridor)
    items.push_back(std::make_unique<Item>(
        "MIRROR",
        "A {MIRROR} hangs on the wall in front of you. It is completely covered in grease, yet you can still make out the faint reflection of an unrecognizable human face. Is... is that me...? Oh god...",
        0, false));
    Item* mirror = items.back().get();
    endCorridor->AddEntity(mirror);

    // KITCHEN INGREDIENTS
    items.push_back(std::make_unique<Item>(
        "POT",
        "The clay {POT} at the center of the table is old and dark with long use.",
        0, true,
        "The {POT} rests undisturbed on the ground.",
        true));
    Item* pot = items.back().get();
    kitchen->AddEntity(pot);

    items.push_back(std::make_unique<Item>(
        "MEAT",
        "Something wrapped loosely - {MEAT}, you assume. You try not to think too hard about what it is.",
        1, true,
        "The {MEAT} lies on the ground."));
    Item* meat = items.back().get();
    meat->SetTargetContainer(pot);
    kitchen->AddEntity(meat);

    items.push_back(std::make_unique<Item>(
        "WATER",
        "Someone left a jar full of {WATER} on the table. The {WATER} inside is, inexplicably, boiling.",
        2, true,
        "The jar sits on the ground. The {WATER} inside is, inexplicably, boiling."));
    Item* jar = items.back().get();
    jar->SetTargetContainer(pot);
    jar->SetRemovableFromContainer(false);
    kitchen->AddEntity(jar);

    items.push_back(std::make_unique<Item>(
        "CARROT",
        "Perfectly peeled and cut, a {CARROT} lies on the table. Too orange to be a carrot.",
        3, true,
        "The {CARROT} pieces lay scattered on the floor."));
    Item* carrot = items.back().get();
    carrot->SetTargetContainer(pot);
    kitchen->AddEntity(carrot);

    items.push_back(std::make_unique<Item>(
        "POTATO",
        "A {POTATO}, still earthy from the ground. Honest and unremarkable. A relief.",
        4, true,
        "The {POTATO} lies on the ground."));
    Item* potato = items.back().get();
    potato->SetTargetContainer(pot);
    kitchen->AddEntity(potato);

    items.push_back(std::make_unique<Item>(
        "MUSHROOM",
        "There is a pale {MUSHROOM} growing from the roots at your feet. You did not notice it until just now.",
        5, true,
        "The {MUSHROOM} sits on the ground. It is, somehow, rooted to the ground, growing again... How?"));
    Item* mushroom = items.back().get();
    mushroom->SetTargetContainer(pot);
    kitchen->AddEntity(mushroom);

    // ── EVENTS ─────────────────────────────────────────────────────────────────
 
    // FOREST ENTRY
    forest->SetOnEntry([](World& world, Room*) {
        std::cout <<
            "\nYou run. You run until your lungs burn and your legs give out. "
            "The forest swallows you whole - dark, indifferent, eternal. "
            "Behind you, the mansion is gone, as if it never existed. "
            "You collapse onto the cold earth and stare up at a sky full of stars that do not care. "
            "\nYou are finally free."
            "\n\n"
            "================================================\n"
            "                    THE END                     \n"
            "             Ending 1  --  Freedom              \n"
            "================================================\n\n";
        world.SetGameOver();
    });

    // CORRIDOR ENTRY FROM EXTERIOR
    corridor->SetOnEntry([exterior](World&, Room* from) {
        if (from != exterior)
            return;
        std::cout <<
            "You gather what little courage you have and step forward. The light is weak and trembling. The wooden floor creaks beneath your weight, each step echoing unnaturally far. "
            "A putrid stench of rotten wood fills the air. You freeze in place.\n\n";
    });

    // HALL ENTRY
    hall->SetOnEntry([](World&, Room* from) {
        std::cout <<
            "A sudden light floods your senses. You blink until shapes begin to form.\n\n";
        });

    // Kitchen ENTRY
    kitchen->SetOnEntry([](World&, Room* from) {
        std::cout <<
            "You open the door expecting the corridor - basic geometry demands it - but geometry, it seems, has no authority here.\n\n";
        });

    // ── NPCS ──────────────────────────────────────────────────────────────────

    // LADY (Hall)
    npcs.push_back(std::make_unique<NPC>("LADY",
        "A pale {LADY}, draped in shadows despite the blazing light that fills the room. "
        "You can barely distinguish her features. She seems old. Older than time itself. "
        "Her eyes are fixed on you - piercing, unblinking, as though looking straight through your chest.",
        0));
    NPC* lady = npcs.back().get();
    hall->AddEntity(lady);

    DialogueNode* root = lady->AddNode("'...'");
    DialogueNode* nodeHello = lady->AddNode("'...'");
    DialogueNode* nodeAreYouReal = lady->AddNode("'Yes.'");
    DialogueNode* nodeIAmToo = lady->AddNode("'Yes. We all are.' A smile. '...'");
    DialogueNode* nodeWhoAreYou = lady->AddNode("'I am.'");
    DialogueNode* nodeWhatIsThisPlace = lady->AddNode("'This is.'");
    DialogueNode* nodeWhatShouldIDo = lady->AddNode("'What do you want to do?'");
    DialogueNode* nodeYouAreAlive = lady->AddNode("'You are alive.'");
    DialogueNode* nodeYouAreFound = lady->AddNode("'I found you.' A smile. '...'");
    DialogueNode* nodeEat = lady->AddNode("'The other door will lead you to the kitchen. Help yourself; for I do not hunger.' A smile. '...'");
    DialogueNode* nodeEnd = lady->AddNode("'Do NOT eat the {MEAT}.' A smile. '...'");

    root->SetOptions({
        { "'Hello?'", nodeHello },
        { "'...'", nullptr }
    });

    nodeHello->SetOptions({
        { "'Are you real?'",  nodeAreYouReal },
        { "'Who are you?'", nodeWhoAreYou },
        { "'What is this place?'", nodeWhatIsThisPlace },
        { "'What should I do?'", nodeWhatShouldIDo },
    });

    nodeAreYouReal->SetOptions({
        { "'Hum... Okay.'", nodeHello },
        { "'...'", nodeHello }
    });

    nodeWhoAreYou->SetOptions({
        { "'Hum... Okay.'", nodeHello },
        { "'I am too.'", nodeIAmToo }
    });

    nodeIAmToo->SetOptions({
        { "'...'", nodeHello }
    });

    nodeWhatIsThisPlace->SetOptions({
        { "'...'", nodeHello }
    });

    nodeWhatShouldIDo->SetOptions({
        { "'Live.'", nodeYouAreAlive },
        { "'Be found.'", nodeYouAreFound },
        { "'Eat.'", nodeEat }
    });

    nodeYouAreAlive->SetOptions({
        { "'I am?'", nodeHello }
    });

    nodeYouAreFound->SetOptions({
        { "'Thanks?'", nodeHello }
    });

    nodeEat->SetOptions({
        { "'Thanks?'", nodeEnd }
    });

    nodeEnd->onReach = [hall, kitchen](World&) {
        if (!hall->GetEntrance("YELLOW DOOR")) {
            std::cout << Render("... Other door? What other door?\n");
            hall->AddEntrance(std::make_unique<Entrance>("YELLOW DOOR",
                "Beyond the {WHITE DOOR} awaits a {YELLOW DOOR}, set into the same wall, not a step away. The paint is fresh - still bleeding down the wood. "
                "That door was not there before. You are certain of this. You are trying very hard to remain certain of this.",
                kitchen,
                hall->GetNextOrder()));
        }
    };

    lady->SetDialogueRoot(root);

    startRoom = exterior;
}
