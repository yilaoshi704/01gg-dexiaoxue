#include "touwenjian.h" 

int main() {
    while(1) {
		char expression[100];
    	printf("������ʽ:");
    	scanf("%s", expression);
    	printf("Result: %d\n", evaluate(expression));
    	printf("�Ƿ������������1��������2\n");
    	while (1){
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
