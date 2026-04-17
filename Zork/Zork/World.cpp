#include "World.h"
#include <iostream>

World::World()
{
    // TODO
}

void World::Run()
{
    std::cout << "Welcome to Zork!\n";
    std::string input;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "quit" || input == "exit")
            break;

        ProcessInput(input);
    }
}

void World::ProcessInput(const std::string& input)
{
    // TODO
}