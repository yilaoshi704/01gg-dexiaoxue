#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

typedef struct Stack {
    long long* data;
    long long top;
    long long size;
    int isFull;
} Stack;
int getInput();
int isValidExpression(char* expression); 
Stack* createStack(int size);
void push(Stack* stack, long long value);
long long pop(Stack* stack);
long long peek(Stack* stack);
int isEmpty(Stack* stack);
int isOperator(char ch);
int precedence(char ch);
int calculate(int a, int b, char op);
long long evaluate(char* expression);
