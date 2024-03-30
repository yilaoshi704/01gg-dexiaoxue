// 颜色排序 
void sortcolors(int* nums, int size) {
    int p0 = 0, p2 = size - 1, i = 0;
    
    while (i <= p2) {
        if (nums[i] == 0) {
            // i与p0交换
            int temp = nums[i];
            nums[i] = nums[p0];
            nums[p0] = temp;
            p0++;
            i++;
        } else if (nums[i] == 2) {
            // i与p2交换 
            int temp = nums[i];
            nums[i] = nums[p2];
            nums[p2] = temp;
            p2--;
        } else {
            i++;
        }
    }
}

//找到指定排序位置的数字 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 划分函数，将数组按照基准值划分为两部分，并返回基准值的位置
int partition(int a[], int low, int high) {
    int p = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&arr[i + 1], &a[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// 找到第k小的元素
int findKthSmallest(int a[], int size, int k) {
    quickSort(a, 0, size - 1);
    return a[k - 1];
}
