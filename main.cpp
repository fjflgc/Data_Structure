#include <string.h>
#include<iostream>
#include <vector>
#include "�㷨/bubbleSort.h"
#include "�㷨/selectionSort.h"
#include "�㷨/insertionSort.h"

using namespace std;

int main() {
    vector<int> ivec = {7, 9, 3, 21, 4, 6, 5};

//    cout << "bubbleSort" << endl;
//    bubbleSort(ivec);
//    for (auto e: ivec)
//        cout << e << " ";

//    cout << "selectionSort" << endl;
//    selectionSort(ivec);
//    for (auto e: ivec)
//        cout << e << " ";

    cout << "insertionSort" << endl;
    insertionSort(ivec);
    for (auto e: ivec)
        cout << e << " ";

    return 0;
}