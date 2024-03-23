#include "touwenjian.h" 

int main() {
    while(1) {
		char expression[100];
    	printf("输入表达式:");
    	scanf("%s", expression);
    	printf("Result: %d\n", evaluate(expression));
    	printf("是否继续，是输入1，否输入2\n");
    	while (1){
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
