#include "head.h"
int main() {
	int n = 0;
	int range = 0;
	int choice = -1;
	while (1){
		printf("������������(ע���������Ҳ�����int)\n");
		n = getInput();
		printf("��������ݵ����Χ(ע���������Ҳ�����int)\n");
		range = getInput();
		int *a = (int *)malloc(sizeof(int) * n); // �洢�����������
    	randomarray(a, n, range);
		char filename[1000];
		int *b = NULL;
		while (1){
			printf("\n�Ѿ������������\n"); 
			printf("1. ��������\n");
        	printf("2. �鲢����\n");
        	printf("3. ����\n");
        	printf("4. ��������\n");
        	printf("5. ��������\n");
       		printf("6. ���Դ���������ʱ\n");
       		printf("7. ���Դ���С��������ʱ\n");
       		printf("8. ����\n");
       		printf("9. ��ȡ\n");
       		printf("10. ��ӡ\n");
       		printf("11. �˳�\n"); 
        	printf("��ѡ�������");
        	choice = getInput();
        	
        	switch (choice) {
            	case 1:
                	if (b != NULL) {
                		insertionSort(b, n); 
					}
					else {
						insertionSort(a, n); 
					}
                	break;
            	case 2:
                	if (b != NULL) {
                		mergeSort(b, 0, n - 1); 
					}
					else {
						mergeSort(a, 0, n - 1); 
					}
                	break;
            	case 3:
                	if (b != NULL) {
                		quickSort(b, 0, n - 1); 
					}
					else {
						quickSort(a, 0, n - 1); 
					}
                	break;
            	case 4:
                	if (b != NULL) {
                		countSort(b, n);
					}
					else {
						countSort(a, n);
					}
                	break;
            	case 5:
                	if (b != NULL) {
                		radixCountSort(b, n);
					}
					else {
						radixCountSort(a, n);
					}
                	break;
                case 6:
                	testSortingFunctions();
                	break;
                case 7:
                	testSortingFunctionsSmallData();
                	break;
                case 8:
                	printf("������Ҫ������ļ���:\n");
                	scanf("%s", filename);
                	if (b != NULL){
                		save(b, n, filename);
					}
                	else {
                		save(a, n, filename);
					}
                	break;
                case 9:
                	if (b != NULL) {
                		printf("�Ѿ���ȡ���ˣ������ٴζ�ȡ����������");
                		break;
					}
                	printf("�����ȡ����Ĵ�С\n"); 
                	n = getInput();
                	printf("�����ȡ���ļ���(��exe��ͬĿ¼)\n");
                	scanf("%s", filename);
                	b = (int *)malloc(sizeof(int) * n);
                	readfile(b, n, filename);
                	break;
                case 10:
                	if (b != NULL){
                		printArray(b, n);
					}
                	else{
                		printArray(a, n);
					}
                	break;
            	case 11:
            		free(a);
            		if (b != NULL) {
            			free(b); 
					}
                	exit(1);
            	default:
                	printf("��ѡ����ȷ�Ĳ���\n");
        	}
   		}
	}
	return 0;
}
