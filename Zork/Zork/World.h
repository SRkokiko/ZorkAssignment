#pragma once
#include <list>
#include <string>

class Room;

/// Owns all rooms and drives the main game loop
class World
{
public:
    World();
    ~World();

    /// Starts the game loop, blocking until the player quits
    void Run();

private:
    /// Processes player input
    bool ProcessInput(const std::string& input);

    std::list<Room*> m_rooms;
    Room* m_currentRoom;
};
