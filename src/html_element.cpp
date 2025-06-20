#include <iostream>
#include <string>
#include <string_view>
#include "html_element.h"
#include "utils.h"

using namespace std;

void HTMLElement::addChild(const HTMLElement& element) {
    children.push_back(element);
}

void HTMLElement::render() const {
    render_indentations(0); // call helper function to print out root data and its children
}

void HTMLElement::render_indentations(int indents) const {

    printIndents(indents);
    
    if(textContent.empty()) { // Print element name and possible textContents
        cout << name << endl;
    }
    else {
        cout << name << ": " << textContent << endl;
    }

    for(const auto& child : children) // Each child of the parent must contain atleast 1 more indent
    {
        child.render_indentations(indents + 1);
    }
}

void HTMLElement::printIndents(int indents) const {
    PrintUtility::printIndents(indents);
}
