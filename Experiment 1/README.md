# Token Type Identification Program

## Problem Statement
Design and implement a lexical analyzer for given language using C and the lexical analyzer should ignore redundant spaces, tabs and new lines.

## Components

### 1. Headers and Macros
- Includes standard C libraries such as `stdio.h`, `stdint.h`, `stdlib.h`, etc.
- Defines a macro `intmax` as `INT_MAX`.

### 2. Typedefs
- Defines `typedef` aliases for data types:
  - `ll`: long long
  - `ull`: unsigned long long
  - `lld`: long double

### 3. Global Variables
- `type`: a 2D array of strings containing different token types:
  - "Identifier"
  - "Operator"
  - "Keyword"
  - "Special symbol"
  - "Punctuation"
  - "Opening bracket"
  - "Closing bracket"

### 4. Functions
- `max()`: Returns the maximum of two integers.
- `min()`: Returns the minimum of two integers.
- `typeCheck(char token[])`: Checks the type of a given token (string) based on predefined arrays of operators, keywords, special symbols, punctuation, opening brackets, and closing brackets.

### 5. Main Function
- Opens the file `"exp1.txt"` in read mode.
- Reads each line from the file.
- Tokenizes each line based on space, tab, and newline characters.
- Prints each token along with its type and current line number.
- Closes the file after processing.

## File: exp1.txt
- This file contains text data that the program reads and processes.

## How to Use
1. Ensure the file `exp1.txt` exists and contains text data.
2. Compile the code using a C compiler (e.g., `gcc -o token_identifier token_identifier.c`).
3. Run the compiled program (e.g., `./token_identifier`).
4. View the output, which displays each token along with its type and line number.

## Note
- Ensure that the token types and their associated strings in the code are accurate and comprehensive for your specific requirements.
- Make necessary adjustments to the code as per your project's needs.
