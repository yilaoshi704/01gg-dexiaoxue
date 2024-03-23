#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Stack {
    int* data;
    int top;
    int size;
} Stack;
int getInput();
Stack* createStack(int size);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
int isOperator(char ch);
int precedence(char ch);
int calculate(int a, int b, char op);
int evaluate(char* expression);
