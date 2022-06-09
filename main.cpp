#include <string.h>
#include<iostream>
#include <vector>
#include "算法/bubbleSort.h"
#include "算法/selectionSort.h"
#include "算法/insertionSort.h"
#include "算法/shellSort.h"

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

//    cout << "insertionSort" << endl;
//    insertionSort(ivec);
//    for (auto e: ivec)
//        cout << e << " ";

    cout << "shellSort" << endl;
    shellSort(ivec);
    for (auto e: ivec)
        cout << e << " ";

    return 0;
}