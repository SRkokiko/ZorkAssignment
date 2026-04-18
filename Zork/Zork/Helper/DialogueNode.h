#pragma once
#include <string>
#include <vector>

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
};
