#include "touwenjian.h"

int main() {
    LQueue Q;
    InitLQueue(&Q);
    int choice;
    char data[30];
    char type;					
	char datatype[30];	

    while (1) {
        printf("\n1. ���\n");
        printf("2. ����\n");
        printf("3. ��ȡ��ͷԪ��\n");
        printf("4. ��ӡ����Ԫ��\n");
        printf("5. ���г���\n");
        printf("6. �˳�\n");
        printf("��ѡ�������");
        choice = getInput();

        switch (choice) {
            case 1:
                printf("����Ҫ��ӵ����ݣ�");
                scanf("%s", data);
                EnLQueue(&Q, data);
                break;
            case 2:
                DeLQueue(&Q);
                break;
            case 3:
                if (!GetHeadLQueue(&Q, data)) {
                	printf("����Ϊ�գ�\n"); 
					getchar(); 
                	break;
				} 
                printf("��ͷԪ��Ϊ��%s\n", data);
                break;
            case 4:
                printf("��ǰ����Ԫ��Ϊ��\n");
                TraverseLQueue(&Q, LPrint);
                break;
            case 5:
                printf("��ǰ���г���Ϊ��%d\n", LengthLQueue(&Q));
                break;
            case 6:
                DestoryLQueue(&Q);
                exit(EXIT_SUCCESS);
            default:
                printf("��ѡ����ȷ�Ĳ���\n");
        }
    }

    return 0;
}
