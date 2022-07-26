//
// Created by atomfjf on 2022/6/9.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void bubbleSort(vector<T> &vec)
{
    int len = vec.size();
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
                swap(vec[j + 1], vec[j]);
        }
    }
}

//使用flag标志改进
void bubbleSort(vector<T> vec)
{
    int i, j, temp;
    int flag = 1;
    for (i = 1; i < vec.size() && flag == 1; i++)//帮助确定j需要遍历多少数据
    {
        flag=0;//如果有一次没有发生逆序，则flag=0,跳出外层循环
        for(j=0;j<n-i;j++){
            if(vec[j]>vec[j+1]){
                swap(vec[j],vec[j+1]);
                flag=1;
            }
        }
    }
}


 