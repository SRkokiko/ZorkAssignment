#include "NPC.h"

NPC::NPC(const std::string& name, const std::string& description, int order)
    : Entity(name, description, order, false)
{}

DialogueNode* NPC::AddNode(std::string npcText, std::vector<DialogueOption> options)
{
    auto node = std::make_unique<DialogueNode>();
    node->npcText = std::move(npcText);
    node->options = std::move(options);
    m_nodes.push_back(std::move(node));
    return m_nodes.back().get();
}

void NPC::SetDialogueRoot(DialogueNode* node)
{
    m_root = node;
}

DialogueNode* NPC::GetActiveRoot() const
{
    return m_resumeNode ? m_resumeNode : m_root;
}

void NPC::SaveProgress(DialogueNode* node)
{
    m_resumeNode = node;
}
