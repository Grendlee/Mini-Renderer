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

    HTMLElement parseElement(size_t& pos);
    void skipSpace(size_t& index);
    bool isClosingTag(size_t index) const;
    void skipToChar(size_t& index, char target);
    void advanceToNextOpenTag(size_t& index);
};

#endif // HTML_PARSER_H
