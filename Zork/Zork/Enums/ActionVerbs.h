#pragma once
#include <vector>
#include <string>

namespace ActionVerbs {

    inline const std::vector<std::string>& Move() {
        static const std::vector<std::string> v = { "go", "walk", "enter", "move", "travel", "head", "proceed", "run" };
        return v;
    }

    inline const std::vector<std::string>& Use() {
        static const std::vector<std::string> v = { "use", "activate", "operate", "apply", "interact", "open" };
        return v;
    }

    inline const std::vector<std::string>& Take() {
        static const std::vector<std::string> v = { "take", "get", "pick", "grab", "collect", "acquire", "lift", "carry", "snatch", "steal", "pocket" };
        return v;
    }

    inline const std::vector<std::string>& Drop() {
        static const std::vector<std::string> v = { "drop", "put", "place", "leave", "throw", "discard", "toss", "release", "set" };
        return v;
    }

    inline const std::vector<std::string>& Inventory() {
        static const std::vector<std::string> v = { "inventory", "i", "items", "inv", "bag", "backpack", "pockets", "carrying" };
        return v;
    }

    inline const std::vector<std::string>& Look() {
        static const std::vector<std::string> v = { "look", "l", "examine", "inspect", "check", "survey", "scan", "study", "observe", "search", "describe" };
        return v;
    }

    inline const std::vector<std::string>& Help() {
        static const std::vector<std::string> v = { "help", "h", "?", "commands", "hint", "hints", "manual", "man" };
        return v;
    }

    inline const std::vector<std::string>& Talk() {
        static const std::vector<std::string> v = { "talk", "speak", "chat", "ask", "greet" };
        return v;
    }

}
