#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <string>
#include <string_view>
#include "html_element.h"

class HTMLParser {
public:
    HTMLParser(std::string_view htmlContent);
    [[nodiscard]] HTMLElement parse();

private:
    std::string content;
};

#endif // HTML_PARSER_H
