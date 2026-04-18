#include "Action.h"
#include <algorithm>

Action::Action(std::vector<std::string> verbs) : m_verbs(std::move(verbs)) {}

bool Action::Matches(const std::string& verb) const
{
    return std::find(m_verbs.begin(), m_verbs.end(), verb) != m_verbs.end();
}
