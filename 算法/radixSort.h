#ifndef DATA_STRUCTURE_RADIXSORT_H
#define DATA_STRUCTURE_RADIXSORT_H

#include <iostream>
using namespace std;
//基数排序
void radixSort(int *A, int n)
{
    int imax = 0;//数组中的最大键值
    for (int i = 0; i < n; i++)
    {
        if (A[i] > imax)
            imax = A[i];
    }
    //从个位开始，对数组进行基数排序
    for (int exp = 1; imax / exp > 0; exp *= 10)
    {
        int *result = new int[n];//用于存放排序后的数组
        int bucket[10] = {0};//初始化10个桶
        //遍历数组，将数据出现的次数存储在桶中
        for (int i = 0; i < n; i++)
            bucket[A[i] / exp % 10]++;

        //调整桶bucket各元素的值，调整后的值就是A中元素在result中的位置
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        //将数组中的元素放入result中(从后往前排，先入后出)
        for (int i = n - 1; i >= 0; i--)
        {
            int iexp = A[i] / exp % 10;
            result[--bucket[iexp]] = A[i];
        }
        memcpy(A, result, sizeof(int) * n);
    }
}

#endif //DATA_STRUCTURE_RADIXSORT_H
