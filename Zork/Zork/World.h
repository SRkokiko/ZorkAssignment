#pragma once
#include <vector>
#include <string>

class World
{
public:
    World();       
    void Run();    

private:
    void ProcessInput(const std::string& input);
    void PrintHelp() const;
};