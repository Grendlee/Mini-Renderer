#include <iostream>
#include <string_view>
#include <cctype>
#include "html_parser.h"
#include "utils.h"

HTMLParser::HTMLParser(std::string_view htmlContent) : content(htmlContent) {}

HTMLElement HTMLParser::parse() {
    
    size_t index = 0;
    return parseElement(index);
}

HTMLElement HTMLParser::parseElement(size_t& index) { // Parse html file and build objects of HTMLElement

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

    HTMLElement element(tagName, ""); // Create element with empty textContent first
    
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
                element.addChild(child); // directly add child without temp storage
            }
        }
        else { 
            size_t textStart = index;
            advanceToNextOpenTag(index);
            std::string rawText = content.substr(textStart, index - textStart); 
            element.setTextContent(StringUtility::removeNewlines(rawText)); // Set textContent and remove all newline characters to improve distinction between hierarchy of elements
        }
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
