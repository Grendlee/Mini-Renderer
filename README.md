# HTML Mini Renderer

Hi Redbrick team! Here is my submission for the coding task. This is my attempt to showcase what you can expect from me if I were a successful candidate. 
And of course, I'd be happy to make any changes after a code review! :)

## Approach and design choices

- The HTMLElement class builds and outputs an HTML DOM tree. 
- The HTMLParser walks through the HTML file character by character, using helper functions to keep parsing logic modular.
- The HTML content is stored as a const reference to ensure it remains immutable during parsing.
- The utils.h module provides html_element and html_parser with reusable utility functions. 

## Limitations
- Child elements are stored as copies in vectors. While this simplifies memory management and prevents pointer-related bugs, it's less memory-efficient than using smart pointers. For a production system, I would refactor to use `std::unique_ptr<HTMLElement>` for better performance with large documents. 
- The parser expects all tags to have closing tags.
- Does not parse on malformed input correctly
- Newline characters are ignored to respect the HTML DOM tree hierarchy
- Whitespaces are ignored unless between the first and last visible character of the textContent of an HTMLElement

## Time complexity
html_parser: O(n), where n is the number of characters in the HTML document.
html_element: O(n), where n is the number of HTMLElement objects.


### Build

Run CMake with the provided CMakeLists.txt, just as in the project scaffold you shared.”

```bash
cd mini-renderer
mkdir build
cd build
cmake ..
make
```

### Run

To run the program, execute the program binary:

```bash
./mini-renderer ../example.html
```

To run the tests, execute the compiled test binary:

```bash
./test
```




