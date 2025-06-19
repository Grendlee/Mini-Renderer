#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

#include "html_element.h"
#include "html_parser.h"

[[nodiscard]] std::string readFile(std::string_view filePath) {
    std::ifstream file(filePath.data());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filePath << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        (std::istreambuf_iterator<char>()));
    file.close();
    return content;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <html_file_path>" << std::endl;
        return 1;
    }

    std::string_view filePath = argv[1];
    std::string htmlContent = readFile(filePath);

    if (htmlContent.empty()) {
        std::cerr << "Error: The file is empty or could not be read." << std::endl;
        return 1;
    }

    HTMLParser parser(htmlContent);
    HTMLElement document = parser.parse();

    document.render();

    return 0;
}
