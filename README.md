# Mini Webpage Renderer

## Introduction

Here is my submission for the coding task. This is my attempt to showcase what you can expect from me if I were a successful candidate. 
And of course, I'd be happy to make any changes after a code review! :)

## Approach and design choices

- The HTMLElement class builds and outputs an HTML DOM tree similar to the example you provided. 
- The HTMLParser walks through the HTML file character by character, using helper functions to keep parsing logic modular.
- The HTML content is stored as a const reference to ensure it remains immutable during parsing.
- The utils.h module provides HTMLElement and HTMLParser with reusable utility functions.

## Limitations
- By supporting HTML5 spec, the parser does not parse tag names correctly if they contain whitespaces between the opening and closing brackets ('<' and '>').
- Does not parse on malformed input correctly.
- Newline characters are ignored to respect the HTML DOM tree hierarchy.
- Whitespaces are ignored unless between the first and last visible character of the textContent of an HTMLElement.


## Time complexity
- html_parser: O(n), where n is the number of characters in the HTML document.
- html_element: O(n), where n is the number of HTMLElement objects.


### Build

Run CMake with the provided CMakeLists.txt, just as in the project scaffold you shared.

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




