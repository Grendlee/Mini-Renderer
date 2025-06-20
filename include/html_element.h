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

    /**
     * Renders the element and all its children to stdout with proper indentation.
     * Output format: "tagName" or "tagName: textContent", Indentations are made to represent HTMLElement hierarchy. 
     * New line characters in textConent are not considered to respect HTMLElement hierarchy.
     */
    void render() const;

    /**
     * The following functions are used for calls from external classes, not to be used for calls from internal classes
     */
    [[nodiscard]] std::string_view getName() const noexcept { return name; }
    [[nodiscard]] std::string_view getTextContent() const noexcept { return textContent; }
    [[nodiscard]] const std::vector<HTMLElement>& getChildren() const noexcept { return children; }

private:
    std::string name;
    std::string textContent;
    std::vector<HTMLElement> children;

    /**
     * Recursive helper to render the element tree with indentation respecting hierarchy
     * @param indents Number of indentation levels for this element
     */
    void render_indentations(int indents) const;
    void printIndents(int indents) const;
};

#endif // HTML_ELEMENT_H
