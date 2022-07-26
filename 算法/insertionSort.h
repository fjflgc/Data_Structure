#include <vector>

using namespace std;

template<typename T>
void insertionSort(vector<T> &vec){
    for(int i=1;i<vec.size();i++){
        int key=vec[i];
        int j=i-1;
        while((j>=0)&&(key<vec[j])){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;
    }
}


template<typename T>
//使用哨兵,待排序的元素从下标1开始
void insertionSort2(vecotr <T> &vec)
{
    int i, j;
    for (i = 2; i < vec.size(); i++)
    {
        if (vec[i] < vec[i - 1])
        {
            vec[0] = vec[i];
            for (j = i - 1; vec[j] > vec[0]; j--)
            {
                vec[j + 1] = vec[j];
            }
            vec[j + 1] = vec[0];
        }
    }

}