#include <string.h>
#include<iostream>
#include <vector>
#include "�㷨/bubbleSort.h"
#include "�㷨/selectionSort.h"
#include "�㷨/insertionSort.h"
#include "�㷨/shellSort.h"
#include "���Ͷ�����/huffmanTree.h"
#include "ͼ/AMGraph.h"
#include "ͼ/ATGraph.h"

using namespace std;

int main() {
    //������������
//    HuffmanTree HT;
//    float weight[7] = {0.4, 0.3, 0.15, 0.05, 0.04, 0.03, 0.03};
//    int n = 7;
//    HT.CreateHuffmanTree(weight, n);
//    HT.CreateHuffmanCode(weight, n);

    vector<int> ivec = {7, 9, 3, 21, 4, 6, 5};

//    cout << "bubbleSort" << endl;
//    bubbleSort(ivec);

//    cout << "selectionSort" << endl;
//    selectionSort(ivec);

//    cout << "insertionSort" << endl;
//    insertionSort(ivec);

//    cout << "shellSort" << endl;
//    shellSort(ivec);

//    for (auto e: ivec)
//        cout << e << " ";

    ATGraph G=ATGraph(3,3);
    G.CreateATGraph();
    return 0;
}

