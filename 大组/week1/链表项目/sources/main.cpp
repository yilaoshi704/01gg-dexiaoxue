#include "touwenjian.h" 

int main() {
    int c = 0;
	while (1){
		printf("����1������������2˫������,����3����\n");
		printf("��ѡ�����: \n");
        if (scanf("%d", &c) != 1) {
        	while (getchar() != '\n');
    		printf("�������������һ������\n");
    		continue; // ����ѭ�����ȴ��û���������
		}
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
			printf("������Ч��\n");
			continue;
		}
	}
	return 0;
}
