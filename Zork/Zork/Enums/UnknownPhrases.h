#pragma once
#include <vector>

namespace UnknownPhrases {
    inline const std::vector<const char*>& Phrases() {
        static const std::vector<const char*> v = {
            "What?",
            "Huh?",
            "How?",
            "What should I do? What should I do...",
            "That doesn't make any sense.",
            "I think I may have hit my head.",
            "My brain is not braining.",
            "I'm not thinking clearly.",
            "I was never good with letters.",
            "Something's not clicking.",
            "I need a moment.",
        };
        return v;
    }
}
