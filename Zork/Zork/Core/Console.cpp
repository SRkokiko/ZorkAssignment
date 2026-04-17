#include "Console.h"

std::string Bold(const std::string& text)
{
    return "\033[1m" + text + "\033[0m";
}

std::string Render(const std::string& text)
{
    std::string result;
    result.reserve(text.size());
    size_t i = 0;
    while (i < text.size())
    {
        if (text[i] == '{')
        {
            size_t end = text.find('}', i + 1);
            if (end != std::string::npos)
            {
                result += Bold(text.substr(i + 1, end - i - 1));
                i = end + 1;
                continue;
            }
        }
        result += text[i++];
    }
    return result;
}
