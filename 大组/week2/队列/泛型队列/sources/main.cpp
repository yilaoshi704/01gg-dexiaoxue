#include "touwenjian.h"


int main() {
    LQueue Q;
    InitLQueue(&Q);
    int choice;
    char data[30];
    char type;					
	char datatype[30];
	char *input = (char *)malloc(sizeof(char) * MAX_LENGTH); 

    while (1) {
        printf("\n1. 入队\n");
        printf("2. 出队\n");
        printf("3. 获取队头元素\n");
        printf("4. 打印队列元素\n");
        printf("5. 队列长度\n");
        printf("6. 退出\n");
        printf("请选择操作：");
        choice = getInput();

        switch (choice) {
            case 1:
                printf("输入要入队的数据：");
				newinput(input);
				scanf("%s", input);
				EnLQueue(&Q, input);  // 将 const char* 转换为 void* 进行传递
                break;
            case 2:
                if (!DeLQueue(&Q)) printf("队列为空！\n");
                break;
            case 3:
                if (!GetHeadLQueue(&Q, data)) {
                	printf("队列为空！\n"); 
                	break;
				} 
                printf("队头元素为：%s\n", data);
                break;
            case 4:
                printf("当前队列元素为：\n");
                TraverseLQueue(&Q, LPrint);
                break;
            case 5:
                printf("当前队列长度为：%d\n", LengthLQueue(&Q));
                break;
            case 6:
                DestoryLQueue(&Q);
                exit(EXIT_SUCCESS);
            default:
                printf("请选择正确的操作\n");
        }
    }

    return 0;
}
