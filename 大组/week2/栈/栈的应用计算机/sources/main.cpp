#include "touwenjian.h" 

int main() {
    while (1) {
        char expression[1000];
        printf("������ʽ:");
        scanf("%s", expression);
        
        if (!isValidExpression(expression)) {
            printf("������󣬱��ʽ�Ƿ�\n");
            continue;
        }
        long long result = evaluate(expression);
        if (result == ERROR) {
            printf("������󣬿�������Ϊջ���,����Ϊ0�ȵ�\n");
            continue;
        }
        printf("Result: %lld\n", result);
        printf("�Ƿ������������1��������2\n");
        
        while (1) {
            int res = getInput();
            if (res == 1) break;
            else if (res == 2) exit(1);
            else {
                printf("������Ч������������"); 
                continue;
            }
        }
    }
    return 0;
}
