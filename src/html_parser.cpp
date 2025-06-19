#include <iostream>
#include <string_view>
#include <cctype>
#include "html_parser.h"

HTMLParser::HTMLParser(std::string_view htmlContent) : content(htmlContent) {}

HTMLElement HTMLParser::parse() {
    
    size_t index = 0;
    return parseElement(index);
}

HTMLElement HTMLParser::parseElement(size_t& index) { // Parse

    skipSpace(index); // Skip spaces

    if(index >= content.length() || content[index] != '<') // Parse start a non-space returns null element
    {
        return HTMLElement("");
    }

    index++; // Skip the opening tag '<'

    size_t tagNameStart = index; // Start reading the tag name

    while(index < content.length() && content[index] != '>' && content[index] != ' ') // increment index to extract tagName
    {
        index++;
    }

    std::string tagName = content.substr(tagNameStart, index - tagNameStart); // Extract tagName

    skipToChar(index, '>'); // Index is now one after '>'
    
    std::vector<HTMLElement> elementChildren; // Nested tags are children of this element
    std::string elementTextContent; 
    
    while (index < content.length()) { // Parse textContent and child elements
        skipSpace(index);
        
        if (index >= content.length()) { // Array out of bounds check 
            break;
        }
        
        if (isClosingTag(index)) { // Parsed to closing tag: </tagName>
            index += 2; // Skip the "</"
            skipToChar(index, '>');
            break; // End of this element
        }
        
        if (content[index] == '<') { // Continue to parse child if there is another opening tag: '<'
            HTMLElement child = parseElement(index); 
            if (!child.getName().empty()) { // Check to ensure elementChildren has valid elements
                elementChildren.push_back(child);
            }
        }
        else { 
            size_t textStart = index;
            advanceToNextOpenTag(index);
            std::string rawText = content.substr(textStart, index - textStart); // New-line characters and white spaces between the first and last character of textContent are kept.
            elementTextContent = trimTrailingWhiteSpace(rawText); // Trim trailing white spaces, starting white spaces are not possible with this code. 
        }
    }
    
    // Construct the element with its tagName, textContent, and children
    HTMLElement element(tagName, elementTextContent); 
    for (const auto& child : elementChildren) {
        element.addChild(child);
    }
    
    return element;
}

// Skip spaces, returns index of non space character
void HTMLParser::skipSpace(size_t& index) {
    while (index < content.length() && std::isspace(content[index])) {
        index++;
    }
}

// Checks if current index is the start of a closing tag
bool HTMLParser::isClosingTag(size_t index) const {
    return index + 1 < content.length() && content[index] == '<' && content[index + 1] == '/';
}

// Skip to index past the target char
void HTMLParser::skipToChar(size_t& index, char target) { 
    while(index < content.length() && content[index] != target) {
        index++;
    }
    if (index < content.length()) {
        index++; // Skip the target character
    }
}

// Increment index to the next opening tag
void HTMLParser::advanceToNextOpenTag(size_t& index) {
    while (index < content.length() && content[index] != '<') {
        index++;
    }
}

// Trim all trailling white spaces
std::string HTMLParser::trimTrailingWhiteSpace(const std::string& str) {
    size_t end = str.find_last_not_of(" \n\r\t");
    if (end != std::string::npos) { // npos true if str is all white spaces
        return str.substr(0, end + 1);
    }
    return "";
}
