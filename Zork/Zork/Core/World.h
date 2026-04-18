#pragma once
#include <list>
#include <memory>
#include <string>
#include <vector>
#include "Player.h"
#include "../Action/Action.h"
#include "../Entity/Concrete/Item.h"
#include "../Map/Room.h"

/// Owns all rooms and drives the main game loop
class World
{
public:
    World();

    /// Starts the game loop, blocking until the player quits
    void Run();

    Player& GetPlayer();

private:
    /// Processes player input
    bool ProcessInput(const std::string& input);

    /* World is the sole owner of all rooms, actions, and items.
     unique_ptr enforces this: each object has exactly one owner,
     and is automatically destroyed when the World is destroyed.
     Other classes (Room, Player) reference these via raw T* — a raw pointer
     here means "I can see this object but I don't own or delete it" */
    std::list<std::unique_ptr<Room>> m_rooms;
    std::vector<std::unique_ptr<Action>> m_actions;
    std::vector<std::unique_ptr<Item>> m_items;

    // Player is a value member (not a pointer) because there is always exactly one player — no heap allocation needed
    Player m_player;
};
