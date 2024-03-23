#include "touwenjian.h"

int main() {
    LinkStack stack;
    int length = 0; 
    int choice;
    ElemType data;
    Status result;
    initLStack(&stack);
    do {
        printf("\n菜单\n");
        printf("1. 入栈\n");
        printf("2. 弹出栈顶\n");
        printf("3. 查看栈顶\n");
        printf("4. 打印栈\n");
        printf("5. 检查栈长\n");
        printf("6. 清空栈\n");
        printf("7. 退出并销毁\n");
        printf("输入你的选择: \n");
        choice = getInput(); 
        switch (choice) {
            case 1:
                printf("输入入栈值: \n");
                data = getInput();
                result = pushLStack(&stack, data);
                if (result == SUCCESS) {
                    printf("入栈成功！\n");
                } else {
                    printf("入栈失败\n");
                }
                break;
            case 2:
                result = popLStack(&stack, &data);
                if (result == SUCCESS) {
                    printf("弹出值为： %d\n", data);
                } else {
                    printf("弹出失败\n");
                }
                break;
            case 3:
				if (getTopLStack(&stack, &data)) {
					printf("栈顶为 %d\n", data);
				}
				else {
					printf("栈为空\n");
				}
				break; 
            case 4:
                print(&stack);
                break;
            case 5:
				if (LStackLength(&stack, &length)) {
					printf("长度为 %d\n", length);
				}
                break;
            case 6:
            	if (clearLStack(&stack)) {
            		printf("清空成功\n");
				}
				break;
			case 7:
				if (destroyLStack(&stack)) {
					printf("销毁成功\n");
				}
				getchar();
				break;
            default:
                printf("错误的选择！\n");
        }
    } while (choice != 7);
    return 0;
}
