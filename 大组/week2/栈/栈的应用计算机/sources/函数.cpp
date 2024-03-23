#include "touwenjian.h"

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int calculate(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

int evaluate(char* expression) {
    Stack* values = createStack(strlen(expression));
    Stack* ops = createStack(strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == ' ')
            continue;
        else if (isdigit(expression[i])) {
            int val = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            push(values, val);
            i--;
        } else if (expression[i] == '(') {
            push(ops, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(ops) && peek(ops) != '(') {
                int val2 = pop(values);
                int val1 = pop(values);
                char op = pop(ops);
                push(values, calculate(val1, val2, op));
            }
            if (!isEmpty(ops))
                pop(ops);
        } else if (isOperator(expression[i])) {
            while (!isEmpty(ops) && precedence(peek(ops)) >= precedence(expression[i])) {
                int val2 = pop(values);
                int val1 = pop(values);
                char op = pop(ops);
                push(values, calculate(val1, val2, op));
            }
            push(ops, expression[i]);
        }
    }

    while (!isEmpty(ops)) {
        int val2 = pop(values);
        int val1 = pop(values);
        char op = pop(ops);
        push(values, calculate(val1, val2, op));
    }

    return pop(values);
}

int getInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            // 清空输入缓冲区
            while (getchar() != '\n');
            printf("输入错误，请输入一个整数\n");
        } else {
            // 检查输入缓冲区是否为空
            if (getchar() != '\n') {
                // 清空输入缓冲区
                while (getchar() != '\n');
                printf("输入错误，请输入一个整数\n");
            } else {
                // 输入正确，退出循环
                break;
            }
        }
    }
    return input;
}
