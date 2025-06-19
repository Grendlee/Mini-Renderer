#include <iostream>
#include <string>
#include <string_view>
#include "html_element.h"

void HTMLElement::addChild(const HTMLElement& element) {
    children.push_back(element);
}

void HTMLElement::render() const {
    // TODO: Add implementation
    std::cout << "Render not yet implemented." << std::endl;
}
