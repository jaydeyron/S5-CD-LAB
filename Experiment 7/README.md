# String Pattern Recognition Program

## Problem Statement
Write a C program to recognize strings under 'a', 'a*b+', 'abb'.

## Components

### 1. Main Function
- Prompts the user to enter a string.
- Calculates the occurrences of the characters 'a' and 'b' in the string, as well as the occurrences of the substring 'ba'.
- Determines the pattern the string follows based on the following rules:
  1. If the string contains exactly one 'a' and no 'b's, it follows the rule 'a'.
  2. If the string contains exactly one 'a', two 'b's, and no occurrence of 'ba', it follows the rule 'abb'.
  3. If the string contains zero or more 'a's, one or more 'b's, and no occurrence of 'ba', it follows the rule 'a*b+'.
- Prints a message indicating which rule the string follows, or if it does not match any of the predefined rules.

## How to Use
1. Compile the code using a C compiler (e.g., `gcc -o string_pattern string_pattern.c`).
2. Run the compiled program (e.g., `./string_pattern`).
3. Enter a string when prompted.
4. View the output message indicating the pattern followed by the entered string.

## Note
- Ensure that the code accurately defines the rules for string patterns and correctly identifies strings that match these rules.
- Adjust the code as necessary to meet specific requirements or accommodate additional rules.
