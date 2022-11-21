#include <stdio.h>
#include <malloc.h>
#include "global.h"

void shellSort(int *a, int len); // 函数声明
int n = 0;

int main(void) {
    void read_file(int R[]);
    void print_data(int R[]);
    void ShellSort(int R[]);
    void write_file(int R[], char file[]);
    int R[Max_g_size];
    read_file(R);
    print_data(R);
    ShellSort(R);
    write_file(R, ".//after_shellsort.txt");
    printf("希尔排序后:\n");
//    print_data(R);
    getchar();
}

void print_data(int R[]) {
    int i;
    //printf("\nSorted datas is:\n");
    printf("初始值\n");
    for (i = 1; i <= n; i++) {
        printf("%5d\n", R[i]);
    }
    printf("\n");
}

void write_file(int R[], char file[]) {
    int i;
    FILE *fp2;
    if ((fp2 = fopen(file, "w")) == NULL) {
        fprintf(stderr, "文件new.txt关闭失败!\n");
        exit(1);
    }
    for (i = 1; i < n; i++) {
        fprintf(fp2, "%d\n", R[i]);
    }
    fclose(fp2);
}


void read_file(int R[]) {

    FILE *fp1;
    int i;
    fp1 = fopen("origin.txt", "r");
    printf("Please input select numbers(n<=15):");
    scanf("%d", &n);
    //fscanf(fp1,"%ld,%s,%d");



    for (i = 1; i <= n; i++) {
        fscanf(fp1, "%d", R+i);
        printf("i+%d\n",R[i]);
    }
    fclose(fp1);
}


void shellSort(int *a, int len) {
    int i, j, k, tmp, gap;  // gap 为步长
    for (gap = len / 2; gap > 0; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半,
        for (i = 0; i < gap; ++i) { // 变量 i 为每次分组的第一个元素下标
            for (j = i + gap; j < len; j += gap) { //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
                tmp = a[j];  // 备份a[j]的值
                k = j - gap;  // j初始化为i的前一个元素（与i相差gap长度）
                while (k >= 0 && a[k] > tmp) {
                    a[k + gap] = a[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
                    k -= gap;
                }
                a[k + gap] = tmp;
            }
        }
    }
}

void ShellSort(int R[]) {
    int gap = n / 2;
    int i, j;
    while (gap != 0) {
        for (i = gap + 1; i <= n; i++) {
            if (R[i] < R[i - gap]) {
                R[0] = R[i];
                for (j = i - gap; (R[0] < R[j]) && (j > 0); j = j - gap) {
                    R[j + gap] = R[j];
                }
                R[j + gap] = R[0];
            }
        }
        gap /= 2;
    }
}

