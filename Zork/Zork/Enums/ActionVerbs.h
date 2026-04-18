#pragma once
#include <vector>
#include <string>

namespace ActionVerbs {

    inline const std::vector<std::string>& Move() { 
        static const std::vector<std::string> v = { "go", "walk", "enter" }; 
        return v; 
    }

    inline const std::vector<std::string>& Use() { 
        static const std::vector<std::string> v = { "use" };                        
        return v; 
    }

    inline const std::vector<std::string>& Take() { 
        static const std::vector<std::string> v = { "take", "get", "pick" };       
        return v; 
    }

    inline const std::vector<std::string>& Drop() { 
        static const std::vector<std::string> v = { "drop" };                      
        return v; 
    }

    inline const std::vector<std::string>& Inventory() {
        static const std::vector<std::string> v = { "inventory", "i", "items" };    
        return v; 
    }

    inline const std::vector<std::string>& Look() { 
        static const std::vector<std::string> v = { "look", "l", "examine" };
        return v; 
    }

    inline const std::vector<std::string>& Help() { 
        static const std::vector<std::string> v = { "help", "h", "?" };                   
        return v; 
    }

}
