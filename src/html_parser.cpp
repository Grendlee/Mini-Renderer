#include <iostream>
#include <string_view>
#include "html_parser.h"

HTMLParser::HTMLParser(std::string_view htmlContent) : content(htmlContent) {}

HTMLElement HTMLParser::parse() {
    // TODO: Add implementation
    std::cout << "Parsing not yet implemented." << std::endl;

    return HTMLElement("html");
}
