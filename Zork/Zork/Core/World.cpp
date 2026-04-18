#include "World.h"
#include "../Map/Room.h"
#include "../Builder/WorldBuilder.h"
#include "../Action/Concrete/MoveAction.h"
#include "../Action/Concrete/UseAction.h"
#include "../Action/Concrete/TakeAction.h"
#include "../Action/Concrete/DropAction.h"
#include "../Action/Concrete/InventoryAction.h"
#include "Player.h"
#include "../Helper/Console.h"
#include <iostream>
using namespace std;

World::World()
    : m_player("Player")
{
    Room* startRoom = nullptr;
    WorldBuilder::Build(m_rooms, m_items, startRoom);

    m_player.SetCurrentRoom(startRoom);

    m_actions.push_back(make_unique<MoveAction>());
    m_actions.push_back(make_unique<UseAction>());
    m_actions.push_back(make_unique<TakeAction>());
    m_actions.push_back(make_unique<DropAction>());
    m_actions.push_back(make_unique<InventoryAction>());
}

Player& World::GetPlayer()
{
    return m_player;
}

void World::Run()
{
    cout << "Welcome to (placeholder name)!\n";
    cout << "Made by Pau Bermudez Valle\n";

    Room* startRoom = m_player.GetCurrentRoom();
    if (startRoom)
        startRoom->Describe();

    string input;
    while (true)
    {
        cout << "\n> ";
        getline(cin, input);

        if (!ProcessInput(input))
            break;
    }
}

bool World::ProcessInput(const string& input)
{
    string cmd = ToLower(input);

    if (cmd == "quit" || cmd == "exit")
        return false;

    size_t spacePos = cmd.find(' ');
    string verb = (spacePos == string::npos) ? cmd : cmd.substr(0, spacePos);
    string args = (spacePos == string::npos) ? "" : cmd.substr(spacePos + 1);

    for (const auto& action : m_actions)
    {
        if (action->Matches(verb)) {
            if (action->Execute(*this, args)) {
                return true;
            }
        }
    }

    cout << "What?\n";
    return true;
}
