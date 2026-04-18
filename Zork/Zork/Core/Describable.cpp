#include "Describable.h"
#include "../Helper/Console.h"
#include <iostream>
using namespace std;

Describable::Describable(const string& name, const string& description, int order)
    : m_name(name), m_description(description), m_order(order)
{
}

const string& Describable::GetName() const
{
    return m_name;
}

const string& Describable::GetDescription() const
{
    return m_description;
}

int Describable::GetOrder() const
{
    return m_order;
}

void Describable::Describe() const
{
    cout << Render(m_description);
}
