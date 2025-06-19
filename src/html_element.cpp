#include <iostream>
#include <string>
#include <string_view>
#include "html_element.h"

using namespace std;

void HTMLElement::addChild(const HTMLElement& element) {
    children.push_back(element);
}

void HTMLElement::render() const {
    render_indentations(0); // call helper function to print out root data and its children
}

void HTMLElement::render_indentations(int indents) const {

    for(int i = 0; i < indents; i++)
    {
        cout << " ";
    }
    
    if(textContent.empty()) { 
        cout << name << endl;
    }
    else {
        cout << name << ": " << textContent << endl;
    }

    for(const auto& child : children)
    {
        child.render_indentations(indents + 1);
    }
}
