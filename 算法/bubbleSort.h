//
// Created by atomfjf on 2022/6/9.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void bubbleSort(vector<T> &vec) {
    int len = vec.size();
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j + 1])
                swap(vec[j+1], vec[j]);
        }
    }
}


 