#include "World.h"
#include "../Map/Room.h"
#include "../Builder/WorldBuilder.h"
#include "../Action/Concrete/MoveAction.h"
#include "../Action/Concrete/UseAction.h"
#include "../Action/Concrete/TakeAction.h"
#include "../Action/Concrete/DropAction.h"
#include "../Action/Concrete/InventoryAction.h"
#include "../Action/Concrete/LookAction.h"
#include "../Action/Concrete/HelpAction.h"
#include "Player.h"
#include "../Helper/Console.h"
#include <iostream>
#include <cstdlib>
#include "../Enums/UnknownPhrases.h"

World::World()
    : m_player("Player")
{
    Room* startRoom = nullptr;
    WorldBuilder::Build(m_rooms, m_items, startRoom);

    m_player.SetCurrentRoom(startRoom);

    m_actions.push_back(std::make_unique<MoveAction>());
    m_actions.push_back(std::make_unique<UseAction>());
    m_actions.push_back(std::make_unique<TakeAction>());
    m_actions.push_back(std::make_unique<DropAction>());
    m_actions.push_back(std::make_unique<InventoryAction>());
    m_actions.push_back(std::make_unique<LookAction>());
    m_actions.push_back(std::make_unique<HelpAction>());
}

Player& World::GetPlayer()
{
    return m_player;
}

void World::Run()
{
    std::cout << "Welcome to Zork!\n";
    std::cout << "Made by Pau Bermudez Valle\n";

    std::cout << "\nPlease write 'help' for a description of available actions.\n";

    std::cout <<
        "\nYou have wandered the woods for what feels like an eternity, long enough for time itself to lose meaning. "
        "Your stomach growls like a starved beast. Cold seeps into your bones, your body trembling. "
        "Your vision blurs. You feel yourself fading, ready to collapse and be swallowed by the indifferent earth-"
        "\n"
        "But then... something changes. "
        "\n"
        "Through the trees, as if conjured from a half-remembered dream, a vast mansion reveals itself. "
        "It was not there before. You are certain of it. "
        "And yet, despite the dread tightening in your chest, you find yourself moving towards it."
        "\n\n";

    Room* startRoom = m_player.GetCurrentRoom();
    if (startRoom)
        startRoom->Describe();

    std::string input;
    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (!ProcessInput(input))
            break;
    }
}

bool World::ProcessInput(const std::string& input)
{
    std::string cmd = ToLower(input);

    if (cmd == "quit" || cmd == "exit")
        return false;

    std::size_t spacePos = cmd.find(' ');
    std::string verb = (spacePos == std::string::npos) ? cmd : cmd.substr(0, spacePos);
    std::string args = (spacePos == std::string::npos) ? "" : cmd.substr(spacePos + 1);

    for (const auto& action : m_actions)
    {
        if (action->Matches(verb)) {
            if (action->Execute(*this, args)) {
                return true;
            }
        }
    }

    const auto& phrases = UnknownPhrases::Phrases();
    std::cout << phrases[std::rand() % phrases.size()] << "\n";
    return true;
}
