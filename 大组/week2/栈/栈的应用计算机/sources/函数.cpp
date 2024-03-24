#include "touwenjian.h"

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed for stack\n");
        return NULL;
    }
    stack->data = (long long*)malloc(sizeof(long long) * size);
    if (stack->data == NULL) {
        printf("Memory allocation failed for stack data\n");
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->size = size;
    return stack;
}

bool isValidExpression(char* expression) {
    int len = strlen(expression);
    char prevChar = '\0';
    int operatorCount = 0;
    int operandCount = 0;
    bool inParentheses = false;
    int digitCount = 0; // 新增：用于计数操作数的位数

    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        if (isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
            if (isdigit(ch)) {
                digitCount++; // 如果是数字，增加位数计数
                if (digitCount > 19) { // 如果操作数超过19位，判定为错误
                    return false;
                }
                operandCount++;
                if (i > 0 && isOperator(prevChar)) {
                    operatorCount--;
                }
            } else if (isOperator(ch)) {
                digitCount = 0; // 如果是运算符，重置位数计数
                operatorCount++;
                if ((i == 0 || prevChar == '(') && ch != '-' && ch != '+') {
                    return false; // 表达式开始处或括号后面直接跟除负号和正号外的其他运算符，判定为错误
                }
            }
            if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/')) {
                return false; // 连续运算符判定为错误
            }
            if (ch == '/' && expression[i + 1] == '0') {
                return false; // 除数为0，判定为错误
            }
            prevChar = ch;
        } else if (ch == ' ') {
            continue; // 空格跳过
        } else {
            return false; // 非法字符判定为错误
        }
    }

    if (operatorCount >= operandCount) {
        return false; // 运算符数量大于等于操作数数量，判定为错误
    }

    return true; // 输入合法
}

void push(Stack* stack, long long value) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

long long pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

long long peek(Stack* stack) {
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

long long evaluate(char* expression) {
    // 检查表达式是否包含运算符
    int containsOperator = 0;
    for (int i = 0; i < strlen(expression); i++) {
        if (isOperator(expression[i])) {
            containsOperator = 1;
            break;
        }
    }
    // 如果表达式不包含运算符，直接将表达式转换为数字并返回
    if (!containsOperator) {
        long long result = atoll(expression);
        if (result == LLONG_MAX && strcmp(expression, "9223372036854775807") != 0) {
            printf("输入错误，数字超过最大值\n");
            return ERROR;
        }
        return result;
    }
    Stack* values = createStack(strlen(expression));
    Stack* ops = createStack(strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == ' ')
            continue;
        else if (isdigit(expression[i])) {
            long long val = 0;
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
                long long val2 = pop(values);
                if (isEmpty(values)) { // 如果操作数栈为空，表示括号中只有一个操作数
                    push(values, val2); // 将这个操作数压入结果栈
                    break;
                }
                long long val1 = pop(values);
                char op = pop(ops);
                if (op == '/' && val2 == 0) {
                    printf("除数为0，表达式错误\n");
                    return ERROR;
                }
                push(values, calculate(val1, val2, op));
            }
            if (!isEmpty(ops))
                pop(ops);
        } else if (isOperator(expression[i])) {
            // 如果遇到负号，并且负号前面没有操作数，将负号视为负一乘以后面的操作数
            if (expression[i] == '-' && (i == 0 || expression[i - 1] == '(')) {
                push(values, -1);
                push(ops, '*');
                continue;
            }
            while (!isEmpty(ops) && precedence(peek(ops)) >= precedence(expression[i])) {
                long long val2 = pop(values);
                long long val1 = pop(values);
                char op = pop(ops);
                if (op == '/' && val2 == 0) {
                    printf("除数为0，表达式错误\n");
                    return ERROR;
                }
                push(values, calculate(val1, val2, op));
            }
            push(ops, expression[i]);
        }
    }

    while (!isEmpty(ops)) {
        long long val2 = pop(values);
        long long val1 = pop(values);
        char op = pop(ops);
        if (op == '/' && val2 == 0) {
            printf("除数为0，表达式错误\n");
            return ERROR;
        }
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
