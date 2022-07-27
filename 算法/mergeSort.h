//
// Created by atomfjf on 2022/7/27.
//

#ifndef DATA_STRUCTURE_MERGESORT_H
#define DATA_STRUCTURE_MERGESORT_H

#endif //DATA_STRUCTURE_MERGESORT_H

void merge(int arr[], int n)
{
    int temp[n];
    int b = 0;//辅助数组的起始位置
    int mid = n / 2;//中间位
    int first = 0, second = mid;//两个数组的起始位置

    while (first < mid && second < n)
    {
        if (arr[first] < arr[second])
        {
            temp[b++] = arr[first++];
        }
        else
        {
            temp[b++] = arr[second++];
        }
    }

    while (first < mid)
    {
        temp[b++] = arr[first++];
    }
    while (second < n)
    {
        temp[b++] = arr[second++];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int n)
{
    if (n <= 1) return;
    if (n > 1)
    {
        mergeSort(arr, n / 2); //对前半部分进行归并排序
        mergeSort(arr + n / 2, n - n / 2);//对后半部分进行归并排序
        merge(arr, n);//归并
    }

}