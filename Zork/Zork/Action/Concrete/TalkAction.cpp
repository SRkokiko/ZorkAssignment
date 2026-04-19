#include "TalkAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Core/Player.h"
#include "../../Map/Room.h"
#include "../../Entity/Concrete/NPC.h"
#include "../../Helper/Console.h"
#include <iostream>

TalkAction::TalkAction()
    : Action(ActionVerbs::Talk())
{}

bool TalkAction::Execute(World& world, const std::string& args)
{
    if (args.empty())
    {
        std::cout << Render("Talk to whom?") << "\n";
        return true;
    }

    Room* room = world.GetPlayer().GetCurrentRoom();
    if (!room)
        return false;

    NPC* npc = nullptr;
    for (Entity* entity : room->GetEntities())
    {
        if (ToLower(entity->GetName()) == args)
        {
            npc = dynamic_cast<NPC*>(entity);
            if (npc) break;
        }
    }

    if (!npc)
    {
        std::cout << Render("There is no one here by that name.") << "\n";
        return true;
    }

    DialogueNode* current = npc->GetActiveRoot();
    if (!current)
    {
        std::cout << "\n" << Bold(npc->GetName()) << " has nothing to say.\n";
        return true;
    }

    while (current)
    {
        if (current->options.empty())
        {
            std::cout << "- " << Bold(npc->GetName()) << ": " << Render(current->npcText) << "\n";
            break;
        }

        std::cout << "- " << Bold(npc->GetName()) << ": " << Render(current->npcText) << "\n\n";

        for (std::size_t i = 0; i < current->options.size(); ++i)
            std::cout << "  [" << (i + 1) << "] " << Render(current->options[i].playerText) << "\n";
        std::cout << "\n" << Render("Choose a valid option, or type 'bye' to leave.") << "\n";

        std::string input;
        std::cout << "\n> ";
        std::getline(std::cin, input);
        input = ToLower(input);

        if (input == "bye")
        {
            std::cout << "- " << Bold("YOU") << ": " << Render("'Sorry, I have to go... Talk later.'") << "\n";
            std::cout << "- " << Bold(npc->GetName()) << ": " << Render("'Later...' She smiles.") << "\n";
            break;
        }

        int choice = -1;
        try { choice = std::stoi(input) - 1; }
        catch (...) {}

        if (choice < 0 || choice >= static_cast<int>(current->options.size()))
        {
            std::cout << Render("That's not a valid option.") << "\n\n";
            continue;
        }

        std::cout << "- " << Bold("YOU") << ": " << Render(current->options[choice].playerText) << "\n";
        current = current->options[choice].next;
        if (current && current->onReach)
            current->onReach(world);
    }

    npc->SaveProgress(current);
    return true;
}
