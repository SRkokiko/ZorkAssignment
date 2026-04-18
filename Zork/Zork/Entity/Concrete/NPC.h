#pragma once
#include "../Entity.h"
#include "../../Helper/DialogueNode.h"
#include <memory>
#include <vector>

class NPC : public Entity
{
public:
    NPC(const std::string& name, const std::string& description, int order = 0);

    /// Creates a node owned by this NPC and returns a raw pointer for tree wiring
    DialogueNode* AddNode(std::string npcText, std::vector<DialogueOption> options = {});

    void SetDialogueRoot(DialogueNode* node);

    /// Returns the last mid-conversation node if the player left early, otherwise the root
    DialogueNode* GetActiveRoot() const;

    /// Saves the node where the conversation ended as the resume point for next time
    void SaveProgress(DialogueNode* node);

private:
    std::vector<std::unique_ptr<DialogueNode>> m_nodes;
    DialogueNode* m_root = nullptr;
    DialogueNode* m_resumeNode = nullptr;
};
