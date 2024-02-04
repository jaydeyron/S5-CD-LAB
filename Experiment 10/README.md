# Infix to Postfix and Three Address Code Converter

## Problem Statement
Implement Intermediate Code Generation (ICG) for simple expressions

## Components

### 1. Functions
- `int isOp(char c)`: Checks if a character is an operator (`+`, `-`, `*`, `/`).
- `void infixToPostfix(char infix[], char postfix[])`: Converts an infix expression to its corresponding postfix expression.
- `void postfixToThreeAddressCode(char postfix[], char threeAddressCode[][100], int *codeSize)`: Generates three address code representations from a postfix expression.
- `void codeRepresentations(char threeAddressCode[][100], int codeSize)`: Prints the three address code representations in quadruple, triple, and indirect triple formats.

### 2. Main Function
- Prompts the user to enter an infix expression.
- Converts the infix expression to its corresponding postfix expression using the infixToPostfix function.
- Generates three address code representations from the postfix expression using the postfixToThreeAddressCode function.
- Prints the three address code representations in quadruple, triple, and indirect triple formats using the codeRepresentations function.

## How to Use
1. Compile the code using a C compiler (e.g., `gcc -o infix_to_postfix_3addr infix_to_postfix_3addr.c`).
2. Run the compiled program (e.g., `./infix_to_postfix_3addr`).
3. Enter an infix expression when prompted.
4. View the postfix expression and the generated three address code representations.

## Note
- Ensure that the code accurately converts infix expressions to postfix expressions and generates correct three address code representations.
- Make necessary adjustments to the code as per specific requirements or to accommodate additional features.
