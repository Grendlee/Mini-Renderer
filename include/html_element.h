#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include <string>
#include <string_view>
#include <vector>

class HTMLElement {
public:
    HTMLElement(std::string_view name, std::string_view textContent = "")
        : name(name), textContent(textContent) {}

    void addChild(const HTMLElement& element);
    void render() const;
    void render_indentations(int indents) const;

    [[nodiscard]] std::string_view getName() const noexcept { return name; }
    [[nodiscard]] std::string_view getTextContent() const noexcept { return textContent; }
    [[nodiscard]] const std::vector<HTMLElement>& getChildren() const noexcept { return children; }

private:
    std::string name;
    std::string textContent;
    std::vector<HTMLElement> children;
};

#endif // HTML_ELEMENT_H
