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


int isValidExpression(char* expression) {
    int len = strlen(expression);
    char prevChar = '\0';
    int operatorCount = 0;
    int operandCount = 0;

    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        if (isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
            if (isdigit(ch)) {
                operandCount++;
                if (i > 0 && isOperator(prevChar)) {
                    operatorCount--;
                }
            } else if (isOperator(ch)) {
                operatorCount++;
                if (i == 0 || prevChar == '(') {
                    return 0; // ���ʽ��ʼ�������ź���ֱ�Ӹ���������ж�Ϊ����
                }
            }
            if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/')) {
                return 0; // ����������ж�Ϊ����
            }
            prevChar = ch;
        } else if (!isspace(ch)) {
            return 0; // �Ƿ��ַ��ж�Ϊ����
        }
    }

    if (operatorCount >= operandCount) {
        return 0; // ������������ڵ��ڲ������������ж�Ϊ����
    }

    return 1; // ����Ϸ�
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
    // �����ʽ�Ƿ���������
    int containsOperator = 0;
    for (int i = 0; i < strlen(expression); i++) {
        if (isOperator(expression[i])) {
            containsOperator = 1;
            break;
        }
    }
    // ������ʽ�������������ֱ�ӽ����ʽת��Ϊ���ֲ�����
    if (!containsOperator) {
        long long result = atoll(expression);
        if (result == LLONG_MAX && strcmp(expression, "9223372036854775807") != 0) {
            printf("����������ֳ������ֵ\n");
            return -1;
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
                long long val1 = pop(values);
                char op = pop(ops);
                push(values, calculate(val1, val2, op));
            }
            if (!isEmpty(ops))
                pop(ops);
        } else if (isOperator(expression[i])) {
            while (!isEmpty(ops) && precedence(peek(ops)) >= precedence(expression[i])) {
                long long val2 = pop(values);
                long long val1 = pop(values);
                char op = pop(ops);
                push(values, calculate(val1, val2, op));
            }
            push(ops, expression[i]);
        }
    }

    while (!isEmpty(ops)) {
        long long val2 = pop(values);
        long long val1 = pop(values);
        char op = pop(ops);
        push(values, calculate(val1, val2, op));
    }

    return pop(values);
}

int getInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            // ������뻺����
            while (getchar() != '\n');
            printf("�������������һ������\n");
        } else {
            // ������뻺�����Ƿ�Ϊ��
            if (getchar() != '\n') {
                // ������뻺����
                while (getchar() != '\n');
                printf("�������������һ������\n");
            } else {
                // ������ȷ���˳�ѭ��
                break;
            }
        }
    }
    return input;
}
