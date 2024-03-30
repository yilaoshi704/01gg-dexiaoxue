#include "head.h"
int main() {
	int n = 0;
	int range = 0;
	int choice = -1;
	while (1){
		printf("请输入数据量(注意正整数且不超过int)\n");
		n = getInput();
		printf("请随机数据的最大范围(注意正整数且不超过int)\n");
		range = getInput();
		int *a = (int *)malloc(sizeof(int) * n); // 存储随机数的数组
    	randomarray(a, n, range);
		char filename[1000];
		int *b = NULL;
		while (1){
			printf("\n已经生成随机序列\n"); 
			printf("1. 插入排序\n");
        	printf("2. 归并排序\n");
        	printf("3. 快排\n");
        	printf("4. 计数排序\n");
        	printf("5. 基数排序\n");
       		printf("6. 测试大数据量用时\n");
       		printf("7. 测试大量小数据量用时\n");
       		printf("8. 保存\n");
       		printf("9. 读取\n");
       		printf("10. 打印\n");
       		printf("11. 退出\n"); 
        	printf("请选择操作：");
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
                	printf("输入你要保存的文件名:\n");
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
                		printf("已经读取过了，若想再次读取请重启程序");
                		break;
					}
                	printf("输入读取数组的大小\n"); 
                	n = getInput();
                	printf("输入读取的文件名(与exe相同目录)\n");
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
                	printf("请选择正确的操作\n");
        	}
   		}
	}
	return 0;
}
