#include "touwenjian.h"

int main() {
    LinkStack stack;
    int length = 0; 
    int choice;
    ElemType data;
    Status result;
    initLStack(&stack);
    do {
        printf("\n�˵�\n");
        printf("1. ��ջ\n");
        printf("2. ����ջ��\n");
        printf("3. �鿴ջ��\n");
        printf("4. ��ӡջ\n");
        printf("5. ���ջ��\n");
        printf("6. ���ջ\n");
        printf("7. �˳�������\n");
        printf("�������ѡ��: \n");
        choice = getInput(); 
        switch (choice) {
            case 1:
                printf("������ջֵ: \n");
                data = getInput();
                result = pushLStack(&stack, data);
                if (result == SUCCESS) {
                    printf("��ջ�ɹ���\n");
                } else {
                    printf("��ջʧ��\n");
                }
                break;
            case 2:
                result = popLStack(&stack, &data);
                if (result == SUCCESS) {
                    printf("����ֵΪ�� %d\n", data);
                } else {
                    printf("����ʧ��\n");
                }
                break;
            case 3:
				if (getTopLStack(&stack, &data)) {
					printf("ջ��Ϊ %d\n", data);
				}
				else {
					printf("ջΪ��\n");
				}
				break; 
            case 4:
                print(&stack);
                break;
            case 5:
				if (LStackLength(&stack, &length)) {
					printf("����Ϊ %d\n", length);
				}
                break;
            case 6:
            	if (clearLStack(&stack)) {
            		printf("��ճɹ�\n");
				}
				break;
			case 7:
				if (destroyLStack(&stack)) {
					printf("���ٳɹ�\n");
				}
				getchar();
				break;
            default:
                printf("�����ѡ��\n");
        }
    } while (choice != 7);
    return 0;
}
