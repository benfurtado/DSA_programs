#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to represent a stack of integers
struct Stack {
    int data;
    struct Stack* next;
};

// Function to create a new stack node
struct Stack* createNode(int data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Stack** top, int data) {
    struct Stack* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
    struct Stack* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Function to evaluate an arithmetic expression
int evaluateExpression(const char* expression) {
    struct Stack* operandStack = NULL;
    struct Stack* operatorStack = NULL;

    for (int i = 0; expression[i]; i++) {
        if (isspace(expression[i])) {
            continue; // Skip spaces
        } else if (isdigit(expression[i])) {
            // Read the entire number and push it onto the operand stack
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Move back one position to account for the non-digit character
            push(&operandStack, operand);
        } else if (expression[i] == '(') {
            push(&operatorStack, expression[i]);
        } else if (expression[i] == ')') {
            while (operatorStack != NULL && operatorStack->data != '(') {
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                char op = pop(&operatorStack);
                if (op == '+') {
                    push(&operandStack, operand1 + operand2);
                } else if (op == '-') {
                    push(&operandStack, operand1 - operand2);
                } else if (op == '*') {
                    push(&operandStack, operand1 * operand2);
                } else if (op == '/') {
                    push(&operandStack, operand1 / operand2);
                }
            }
            if (operatorStack != NULL && operatorStack->data == '(') {
                pop(&operatorStack); // Pop the '(' from the operator stack
            }
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {
            // Process operators
            while (operatorStack != NULL &&
                   (expression[i] == '+' || expression[i] == '-') &&
                   (operatorStack->data == '*' || operatorStack->data == '/')) {
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                char op = pop(&operatorStack);
                if (op == '+') {
                    push(&operandStack, operand1 + operand2);
                } else if (op == '-') {
                    push(&operandStack, operand1 - operand2);
                } else if (op == '*') {
                    push(&operandStack, operand1 * operand2);
                } else if (op == '/') {
                    push(&operandStack, operand1 / operand2);
                }
            }
            push(&operatorStack, expression[i]);
        } else {
            printf("Invalid character in expression: %c\n", expression[i]);
            exit(1);
        }
    }

    while (operatorStack != NULL) {
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        char op = pop(&operatorStack);
        if (op == '+') {
            push(&operandStack, operand1 + operand2);
        } else if (op == '-') {
            push(&operandStack, operand1 - operand2);
        } else if (op == '*') {
            push(&operandStack, operand1 * operand2);
        } else if (op == '/') {
            push(&operandStack, operand1 / operand2);
        }
    }

    if (operandStack == NULL) {
        printf("Invalid expression.\n");
        exit(1);
    }

    return operandStack->data;
}

int main() {
    const char* expression = "3 + 5 * ( 4 - 2 )";
    int result = evaluateExpression(expression);
    printf("Result of expression: %s = %d\n", expression, result);
    return 0;
}
