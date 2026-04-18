#include "World.h"
#include "../Map/Room.h"
#include "../Builder/WorldBuilder.h"
#include "../Action/Concrete/MoveAction.h"
#include "../Helper/Console.h"
#include <iostream>
using namespace std;

World::World() : m_currentRoom(nullptr)
{
    WorldBuilder::Build(m_rooms, m_currentRoom);

    m_actions.push_back(new MoveAction());
}

World::~World()
{
    for (Room* room : m_rooms)
        delete room;

    for (Action* action : m_actions)
        delete action;
}

Room* World::GetCurrentRoom() const
{
    return m_currentRoom;
}

void World::SetCurrentRoom(Room* room)
{
    m_currentRoom = room;
}

void World::Run()
{
    cout << "Welcome to (placeholder name)!\n";
    cout << "Made by Pau Bermudez Valle\n";

    if (m_currentRoom)
        m_currentRoom->Describe();

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

    for (Action* action : m_actions)
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
