#include "World.h"
#include "Rooms/Room.h"
#include "Builders/WorldBuilder.h"
#include <iostream>
#include <algorithm>
using namespace std;

World::World() : m_currentRoom(nullptr)
{
    WorldBuilder::Build(m_rooms, m_currentRoom);
}

World::~World()
{
    for (Room* room : m_rooms)
        delete room;
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
    string cmd = input;
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    if (cmd == "quit" || cmd == "exit")
        return false;

    // TODO...

    return true;
}
