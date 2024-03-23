#include "touwenjian.h" 

int main() {
    int c = 0;
	while (1){
		printf("输入1单向链表，输入2双向链表,输入3结束\n");
		printf("请选择操作: \n");
        c = getInput();
		if (c == 1) {
			caidan1();
		}
		if (c == 2) {
			caidan2();
		}
		if (c == 3){
			break;
		} 
		else {
			printf("输入无效！\n");
			continue;
		}
	}
	return 0;
}
