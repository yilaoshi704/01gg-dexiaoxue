#include "head.h"
void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


// 归并排序
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
        l[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

// 快速排序
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pi = partition(a, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}


// 计数排序
void countSort(int a[], int n) {
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    int range = max - min + 1;
    int count[range];
    for (int i = 0; i < range; ++i)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[a[i] - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// 基数计数排序
void radixCountSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(a, n);
}


double calculateTime1(void (*sort)(int[], int), int a[], int n) {
    clock_t start, end;
    start = clock();
    sort(a, n);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

double calculateTime2(void (*sort)(int[], int, int), int a[], int low, int high) {
    clock_t start, end;
    start = clock();
    sort(a, low, high);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}




// 打印数组
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// 生成随机数组
void randomarray(int a[], int n, int range) {
    srand(time(NULL)); // 使用当前时间作为随机数种子
    for (int i = 0; i < n; i++) {
        a[i] = rand() % range; 
    }
}


// 测试排序函数在不同数据量下的运行时间
void testSortingFunctions() {
	
	int *a1 = (int *)malloc(sizeof(int) * SIZE1);
    randomarray(a1, SIZE1, SIZE1 * 10);
    printf("\n当前测试数据量：%d\n", SIZE1);
    printf("插入排序: %.6f 秒\n", calculateTime1(insertionSort, a1, SIZE1));
    printf("归并排序: %.6f 秒\n", calculateTime2(mergeSort, a1, 0, SIZE1 - 1));
    printf("快排: %.6f 秒\n", calculateTime2(quickSort, a1, 0, SIZE1 - 1));
    printf("计数排序: %.6f 秒\n", calculateTime1(countSort, a1, SIZE1));
    printf("基数排序: %.6f 秒\n", calculateTime1(radixCountSort, a1, SIZE1));
    free(a1);
    
    int *a2 = (int *)malloc(sizeof(int) * SIZE2);
	randomarray(a2, SIZE2, SIZE2 * 10);
    printf("\n当前测试数据量：%d\n", SIZE2);
    printf("插入排序: %.6f 秒\n", calculateTime1(insertionSort, a2, SIZE2));
    printf("归并排序: %.6f 秒\n", calculateTime2(mergeSort, a2, 0, SIZE2 - 1));
    printf("快排: %.6f 秒\n", calculateTime2(quickSort, a2, 0, SIZE2 - 1));
    printf("计数排序: %.6f 秒\n", calculateTime1(countSort, a2, SIZE2));
    printf("基数排序: %.6f 秒\n", calculateTime1(radixCountSort, a2, SIZE2));
    free(a2);
    
    int *a3 = (int *)malloc(sizeof(int) * SIZE3);
    randomarray(a3, SIZE3, SIZE3 * 10);
    printf("\n当前测试数据量：%d\n", SIZE3);
    printf("插入排序: %.6f 秒\n", calculateTime1(insertionSort, a3, SIZE3));
    printf("归并排序: %.6f 秒\n", calculateTime2(mergeSort, a3, 0, SIZE3 - 1));
    printf("快排: %.6f 秒\n", calculateTime2(quickSort, a3, 0, SIZE3 - 1));
    printf("计数排序: %.6f 秒\n", calculateTime1(countSort, a3, SIZE3));
    printf("基数排序: %.6f 秒\n", calculateTime1(radixCountSort, a3, SIZE3));
    free(a3);
}

// 测试排序函数在大量小数据量下的排序用时
void testSortingFunctionsSmallData() {
    int a[100];
    double insertionTime = 0.0, mergeTime = 0.0, quickTime = 0.0, countTime = 0.0, radixTime = 0.0;

    for (int i = 0; i < SIZE4; ++i) {
        randomarray(a, 100, 1000);
        insertionTime += calculateTime1(insertionSort, a, 100);
        randomarray(a, 100, 1000);
        mergeTime += calculateTime2(mergeSort, a, 0, 99);
        randomarray(a, 100, 1000);
        quickTime += calculateTime2(quickSort, a, 0, 99);
        randomarray(a, 100, 1000);
        countTime += calculateTime1(countSort, a, 100);
        randomarray(a, 100, 1000);
        radixTime += calculateTime1(radixCountSort, a, 100);
    }

    printf("100个元素的排序平均时间，重复%d次:\n", SIZE4);
    printf("插入排序: %.6f 秒\n", insertionTime / SIZE4);
    printf("归并排序: %.6f 秒\n", mergeTime / SIZE4);
    printf("快排: %.6f 秒\n", quickTime / SIZE4);
    printf("计数排序: %.6f 秒\n", countTime / SIZE4);
    printf("基数排序: %.6f 秒\n", radixTime / SIZE4);
}

// 将数组保存到文件
void save(int a[], int n, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fprintf(file, "%d ", a[i]);
        }
        fclose(file);
    } else {
        printf("打开错误！！！\n");
    }
}

// 从文件中读取数组
void readfile(int a[], int n, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fscanf(file, "%d", &a[i]);
        }
        fclose(file);
    } else {
        printf("错误的文件名称\n");
    }
}

int getInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            // 清空输入缓冲区
            while (getchar() != '\n');
            printf("输入错误，请输入一个整数\n");
        } else {
            // 检查输入缓冲区是否为空
            if (getchar() != '\n') {
                // 清空输入缓冲区
                while (getchar() != '\n');
                printf("输入错误，请输入一个整数\n");
            } else {
                // 输入正确，退出循环
                break;
            }
        }
    }
    return input;
}
