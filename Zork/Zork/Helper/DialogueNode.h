#pragma once
#include <functional>
#include <string>
#include <vector>

class World;
struct DialogueNode;

struct DialogueOption
{
    std::string playerText;
    DialogueNode* next; // dialoge resets on nullptr
};

struct DialogueNode
{
    std::string npcText;
    std::vector<DialogueOption> options;
    std::function<void(World&)> onReach; // fires when the player arrives at this node

    void SetOptions(std::vector<DialogueOption> opts) { options = std::move(opts); }
};
