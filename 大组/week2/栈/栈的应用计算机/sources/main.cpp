#include "touwenjian.h" 

int main() {
    while (1) {
        char expression[1000];
        printf("输入表达式:");
        scanf("%s", expression);
        
        if (!isValidExpression(expression)) {
            printf("输入错误，表达式非法\n");
            continue;
        }
        long long result = evaluate(expression);
        if (result == -1) {
            printf("计算错误，可能是因为栈溢出\n");
            continue;
        }
        printf("Result: %lld\n", result);
        printf("是否继续，是输入1，否输入2\n");
        
        while (1) {
            int res = getInput();
            if (res == 1) break;
            else if (res == 2) exit(1);
            else {
                printf("输入无效！请重新输入"); 
                continue;
            }
        }
    }
    return 0;
}
