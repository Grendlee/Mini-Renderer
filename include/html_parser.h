#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <string>
#include <string_view>
#include "html_element.h"

class HTMLParser {
public:
    HTMLParser(std::string_view htmlContent);

    /**
     * @brief Parses the HTML content and returns the parent element.
     * @return The parent HTMLElement of the parsed document tree
     */
    [[nodiscard]] HTMLElement parse();

private:
    const std::string content;  // The HTML content to parse - never modified
    
    /**
     * @brief Recursively parses an HTML element starting at the given position
     * @param pos Current position in the content string, position changes when parsing
     * @return The parsed HTMLElement with correctly constructed objects that respect hierarchy or empty element if parsing fails
     */
    HTMLElement parseElement(size_t& pos);

    /**
     * @brief Skips whitespace characters starting from the current position
     * @param index Current position and changed to first non-whitespace character
     */
    void skipSpace(size_t& index);

    /**
     * @brief Checks if the current position marks the start of a closing tag '</'
     * @param index Position to check
     * @return true if a closing tag "</" is found at the position
     */
    bool isClosingTag(size_t index) const;

    /**
     * @brief Advances position to just after the specified character
     * @param index Current position (updated to position after target)
     * @param target Character to find and skip past
     */
    void skipToChar(size_t& index, char target);
    
    /**
     * @brief Advances position to the next opening tag '<'.
     * @param index Current position (updated to next '<' character)
     */
    void advanceToNextOpenTag(size_t& index);
};

#endif // HTML_PARSER_H
