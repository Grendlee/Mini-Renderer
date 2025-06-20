#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

// String manipulation utilities
namespace StringUtility {
    // Remove all newline characters from a string
    std::string removeNewlines(const std::string& str);
}

// Printing utilities
namespace PrintUtility {
    // Print indentation (2 spaces per indent level)
    void printIndents(int indents);
}

#endif // UTILS_H
