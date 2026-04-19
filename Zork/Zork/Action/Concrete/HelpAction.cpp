#include "HelpAction.h"
#include "../../Enums/ActionVerbs.h"
#include "../../Core/World.h"
#include "../../Helper/Console.h"
#include <iostream>

HelpAction::HelpAction()
    : Action(ActionVerbs::Help())
{}

bool HelpAction::Execute(World& world, const std::string& args)
{
    std::cout << Bold("Available actions:") << "\n";
    std::cout << "  " << Bold("go/enter") << " <target> - Move through an entrance\n";
    std::cout << "  " << Bold("use") << " <target> - Use an entrance or item in your inventory\n";
    std::cout << "  " << Bold("talk/speak") << " <target> - Start a conversation with someone\n";
    std::cout << "  " << Bold("take/pick") << " <target> - Pick up an item\n";
    std::cout << "  " << Bold("take/pick") << " <target> from <container> - Take an item out of a container\n";
    std::cout << "  " << Bold("drop") << " <target>  - Drop an item from your inventory\n";
    std::cout << "  " << Bold("put") << " <target> in/into <target> - Place an item in your inventory into a container\n";
    std::cout << "  " << Bold("inventory/i") << " - List carried items\n";
    std::cout << "  " << Bold("look/l") << " - Describe the current room\n";
    std::cout << "  " << Bold("help/h") << " - Show this help\n";
    std::cout << "  " << Bold("quit/exit") << " - Quit the game\n";
    std::cout << "\n";
    std::cout << "  Note: Many synonyms and additional verbs are understood, but only single commands are supported (no composite or chained verbs).\n";
    std::cout << "\n";
    std::cout << Bold("Highlighted words:") << "\n";
    std::cout << "  Words shown in " << Bold("UPPERCASE BOLD") << " are interactive - you can use them as targets for some actions.\n";
    return true;
}
