#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

/**
 * @brief String manipulation utility functions.
 * Common string processing operations used throughout HTML_parser.cpp
 */
namespace StringUtility {
    /**
     * @brief Removes all newline characters from a string.
     * 
     * Strips both '\n' and '\r' characters
     * to respect HTMLElement hierarchy. 
     * Does not remove both "\n" and "\r" strings
     * 
     * @param str The input string to process
     * @return A new string with all newline characters removed
     */
    std::string removeNewlines(const std::string& str);
}

/**
 * @brief Output formatting utility functions.
 * 
 * Provides consistent formating for rendering HTML_element.cpp
 */
namespace PrintUtility {
    /**
     * @brief Prints indentation spaces to standard output.
     * 
     * Outputs 2 spaces for each indentation level to create a visual
     * hierarchy when rendering HTML elements.
     * 
     * @param indents Number of indentation levels (0 = no indent, 1 = 2 spaces)
     */
    void printIndents(int indents);
}

#endif // UTILS_H
