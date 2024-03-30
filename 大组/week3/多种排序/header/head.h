#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define SIZE1 10000
#define SIZE2 50000
#define SIZE3 200000
#define SIZE4 100000


void insertionSort(int a[], int n); // 1
void merge(int a[], int left, int mid, int right); 
void mergeSort(int a[], int left, int right); // 2
void swap(int *a, int *b);
int partition(int a[], int low, int high);
void quickSort(int a[], int low, int high);// 2
void countSort(int a[], int n);// 1
void radixCountSort(int a[], int n);// 1
void printArray(int a[], int n);
// 生成指定数量的随机整数
void randomarray(int a[], int n, int range);
double calculateTime1(void (*sort)(int[], int), int a[], int n);
double calculateTime2(void (*sort)(int[], int, int), int a[], int low, int high);
void testSortingFunctions();
void testSortingFunctionsSmallData();
void save(int a[], int n, const char* filename);
void readfile(int a[], int n, const char* filename);
int getInput(); 

