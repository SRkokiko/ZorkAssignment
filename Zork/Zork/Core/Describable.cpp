#include "Describable.h"
#include "../Helper/Console.h"
#include <iostream>

Describable::Describable(const std::string& name, const std::string& description, int order)
    : m_name(name), m_description(description), m_order(order)
{
}

const std::string& Describable::GetName() const
{
    return m_name;
}

const std::string& Describable::GetDescription() const
{
    return m_description;
}

int Describable::GetOrder() const
{
    return m_order;
}

void Describable::SetOrder(int order)
{
    m_order = order;
}

void Describable::Describe() const
{
    std::cout << Render(m_description);
}
