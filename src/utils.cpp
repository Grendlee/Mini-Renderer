#include "utils.h"

namespace StringUtility {
    // Remove new line characters in a string and returns
    std::string removeNewlines(const std::string& str) {
        std::string result;
        
        for (char c : str) {
            if (c != '\n' && c != '\r') {
                result += c;
            }
        }
        return result;
    }
}

namespace PrintUtility {
    // Print spaces for indentation (2 spaces per indent)
    void printIndents(int indents) {
        for(int i = 0; i < indents; i++) {
            std::cout << "  ";
        }
    }
}