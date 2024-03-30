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


// �鲢����
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

// ��������
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


// ��������
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

// ������������
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




// ��ӡ����
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// �����������
void randomarray(int a[], int n, int range) {
    srand(time(NULL)); // ʹ�õ�ǰʱ����Ϊ���������
    for (int i = 0; i < n; i++) {
        a[i] = rand() % range; 
    }
}


// �����������ڲ�ͬ�������µ�����ʱ��
void testSortingFunctions() {
	
	int *a1 = (int *)malloc(sizeof(int) * SIZE1);
    randomarray(a1, SIZE1, SIZE1 * 10);
    printf("\n��ǰ������������%d\n", SIZE1);
    printf("��������: %.6f ��\n", calculateTime1(insertionSort, a1, SIZE1));
    printf("�鲢����: %.6f ��\n", calculateTime2(mergeSort, a1, 0, SIZE1 - 1));
    printf("����: %.6f ��\n", calculateTime2(quickSort, a1, 0, SIZE1 - 1));
    printf("��������: %.6f ��\n", calculateTime1(countSort, a1, SIZE1));
    printf("��������: %.6f ��\n", calculateTime1(radixCountSort, a1, SIZE1));
    free(a1);
    
    int *a2 = (int *)malloc(sizeof(int) * SIZE2);
	randomarray(a2, SIZE2, SIZE2 * 10);
    printf("\n��ǰ������������%d\n", SIZE2);
    printf("��������: %.6f ��\n", calculateTime1(insertionSort, a2, SIZE2));
    printf("�鲢����: %.6f ��\n", calculateTime2(mergeSort, a2, 0, SIZE2 - 1));
    printf("����: %.6f ��\n", calculateTime2(quickSort, a2, 0, SIZE2 - 1));
    printf("��������: %.6f ��\n", calculateTime1(countSort, a2, SIZE2));
    printf("��������: %.6f ��\n", calculateTime1(radixCountSort, a2, SIZE2));
    free(a2);
    
    int *a3 = (int *)malloc(sizeof(int) * SIZE3);
    randomarray(a3, SIZE3, SIZE3 * 10);
    printf("\n��ǰ������������%d\n", SIZE3);
    printf("��������: %.6f ��\n", calculateTime1(insertionSort, a3, SIZE3));
    printf("�鲢����: %.6f ��\n", calculateTime2(mergeSort, a3, 0, SIZE3 - 1));
    printf("����: %.6f ��\n", calculateTime2(quickSort, a3, 0, SIZE3 - 1));
    printf("��������: %.6f ��\n", calculateTime1(countSort, a3, SIZE3));
    printf("��������: %.6f ��\n", calculateTime1(radixCountSort, a3, SIZE3));
    free(a3);
}

// �����������ڴ���С�������µ�������ʱ
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

    printf("100��Ԫ�ص�����ƽ��ʱ�䣬�ظ�%d��:\n", SIZE4);
    printf("��������: %.6f ��\n", insertionTime / SIZE4);
    printf("�鲢����: %.6f ��\n", mergeTime / SIZE4);
    printf("����: %.6f ��\n", quickTime / SIZE4);
    printf("��������: %.6f ��\n", countTime / SIZE4);
    printf("��������: %.6f ��\n", radixTime / SIZE4);
}

// �����鱣�浽�ļ�
void save(int a[], int n, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fprintf(file, "%d ", a[i]);
        }
        fclose(file);
    } else {
        printf("�򿪴��󣡣���\n");
    }
}

// ���ļ��ж�ȡ����
void readfile(int a[], int n, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fscanf(file, "%d", &a[i]);
        }
        fclose(file);
    } else {
        printf("������ļ�����\n");
    }
}

int getInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            // ������뻺����
            while (getchar() != '\n');
            printf("�������������һ������\n");
        } else {
            // ������뻺�����Ƿ�Ϊ��
            if (getchar() != '\n') {
                // ������뻺����
                while (getchar() != '\n');
                printf("�������������һ������\n");
            } else {
                // ������ȷ���˳�ѭ��
                break;
            }
        }
    }
    return input;
}
