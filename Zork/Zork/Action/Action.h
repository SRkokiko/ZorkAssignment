#pragma once
#include <string>
#include <vector>

class World;

class Action
{
public:
    Action(std::vector<std::string> verbs);
    virtual ~Action() = default;

    bool Matches(const std::string& verb) const;
    virtual bool Execute(World& world, const std::string& args) = 0;

private:
    std::vector<std::string> m_verbs;
};
