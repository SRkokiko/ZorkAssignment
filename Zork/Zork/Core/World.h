#pragma once
#include <list>
#include <string>
#include <vector>

class Room;
class Action;

/// Owns all rooms and drives the main game loop
class World
{
public:
    World();
    ~World();

    /// Starts the game loop, blocking until the player quits
    void Run();

    Room* GetCurrentRoom() const;
    void SetCurrentRoom(Room* room);

private:
    /// Processes player input
    bool ProcessInput(const std::string& input);

    std::list<Room*> m_rooms;
    Room* m_currentRoom;
    std::vector<Action*> m_actions;
};
