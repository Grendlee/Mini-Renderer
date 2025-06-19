#include <iostream>
#include <string_view>
#include "html_element.h"

int main() {
    HTMLElement html("html");
    HTMLElement head("head");
    HTMLElement title("title", "Test Page");
    HTMLElement body("body");
    HTMLElement h1("h1", "Hello, World!");
    HTMLElement p("p", "This is a test paragraph.");

    head.addChild(title);
    body.addChild(h1);
    body.addChild(p);
    body.addChild(p);
    html.addChild(head);
    html.addChild(body);

    std::cout << "Testing simple HTML document render: " << std::endl;
    html.render();

    return 0;
}
