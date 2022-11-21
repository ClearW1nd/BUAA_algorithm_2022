//
// Created by SQ on 2022-11-21.
//

#include <stdio.h>
#include <string.h>
#define  size 10    // 数组长度
#define  D 5        // 最大位数
#include "global.h"

int n = 0;
//取整数M的第i位数
int GetDigit(int M, int i)
{
    while(i > 1)
    {
        M /= 10;
        i--;
    }
    return M % 10;
}

// 基数排序
void RadixSort(int *num, int len)
{
    int i, j, k, l, digit;
    int allot[10][size];   // 分配数组

    // 初始化分配数组全为0
    memset(allot, 0, sizeof(allot));

    // 遍历
    for (i = 1; i <= D; i++)
    {
        // 将每个数据的第i位数分配到allot数组中
        for (j = 0; j < len; j++)
        {
            // 获取当前数据 num[j] 的 第i位数
            digit = GetDigit(num[j], i);
            k = 0;
            // 查找插入的位置
            while (allot[digit][k])
            {
                k++;
            }
            // 将num[j]添加到分配数组allot的第digit行的末尾
            allot[digit][k] = num[j];
        }
        // 将分配数组的数据收集到原数组中
        l = 0;
        for (j = 0; j < 10; j++)
        {
            k = 0;
            // 获取数组allot的每一行的数据 到 原数组中
            while (allot[j][k])
            {
                num[l++] = allot[j][k++];
            }
        }
        memset(allot, 0, sizeof(allot));
    }
    FILE* output = fopen("../bin/BaseSort.txt","w");

    for(int i=0;i<Max_g_size;i++){
        fprintf(output,"%d\n",num[i]);
    }
    fclose(output);
}

int main()
{
    int i;
    FILE* input = fopen("../bin/origin.txt","r");


    int num[Max_g_size];
    printf("Please input select numbers(n<=15):");
    scanf("%d", &n);
    for(int i=0;i<Max_g_size;i++){
        fscanf(input,"%d",num[i]);
        printf("%d\n",num[i]);
    }
    fclose(input);
    RadixSort(num, size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
