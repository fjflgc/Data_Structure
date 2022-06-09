#include <string.h>
#include<iostream>
#include <vector>
#include "Ëã·¨/bubbleSort.h"
#include "Ëã·¨/selectionSort.h"
#include "Ëã·¨/insertionSort.h"

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