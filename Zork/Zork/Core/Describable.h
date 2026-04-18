#pragma once
#include <string>

/// Base class for anything with a name and description
class Describable
{
public:
    Describable(const std::string& name, const std::string& description, int order = 0);
    virtual ~Describable() = default;

    const std::string& GetName() const;
    const std::string& GetDescription() const;
    int GetOrder() const;
    void SetOrder(int order);

    /// Prints name and description
    virtual void Describe() const;

protected:
    std::string m_name; // All actions and interactions will be "triggered" by matching exactly the name
    std::string m_description;
    int m_order; // Order will simply be used to know in which order to trigger each description
};
