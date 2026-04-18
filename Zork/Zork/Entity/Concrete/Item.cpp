#include "Item.h"
#include "../../Helper/Console.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description, int order, bool pickable, const std::string& displacedDescription)
    : Entity(name, description, order, pickable), m_displacedDescription(displacedDescription)
{
}

void Item::Describe() const
{
    bool isDisplaced = GetCurrentRoom() != GetOriginalRoom();
    const std::string& desc = (isDisplaced && !m_displacedDescription.empty()) ? m_displacedDescription : GetDescription();
    std::cout << Render(desc);
}
