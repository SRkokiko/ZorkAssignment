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
    std::cout << "  " << Bold("go/enter") << " <entrance> - Move through an entrance\n";
    std::cout << "  " << Bold("use") << " <target> - Use an item or entrance\n";
    std::cout << "  " << Bold("take/pick") << " <item> - Pick up an item\n";
    std::cout << "  " << Bold("drop") << " <item>  - Drop an item from your inventory\n";
    std::cout << "  " << Bold("inventory/i") << " - List carried items\n";
    std::cout << "  " << Bold("look/l") << " - Describe the current room\n";
    std::cout << "  " << Bold("help/h") << " - Show this help\n";
    std::cout << "  " << Bold("quit/exit") << " - Quit the game\n";
    std::cout << "  Note: Many synonyms and additional verbs are understood, but only single commands are supported (no composite or chained verbs).\n";
    return true;
}
