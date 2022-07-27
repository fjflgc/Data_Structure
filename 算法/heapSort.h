
#ifndef DATA_STRUCTURE_HEAPSORT_H
#define DATA_STRUCTURE_HEAPSORT_H

#include <algorithm>

using namespace std;

void max_heapify(int *arr, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)//子节不能超出范围
    {
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大于子节点则代表调整完毕，直接跳出函数
            return;
        else //如果父节点小于子节点，则交换父节点和子节点的值，并继续调整
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }

    }
}

void heapSort(int *arr, int len)
{
    //初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, i, len - 1);
    }
    //使顶堆根最后一个元素交换，这里--i达到弹出的效果，也就是i+1到len-1的范围内的元素都是有序的，再重新调整使符合大根堆
    for(int i=len-1;i>0;--i){
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i-1);
    }
}


#endif //DATA_STRUCTURE_HEAPSORT_H
