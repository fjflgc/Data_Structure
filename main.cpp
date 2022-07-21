#include <string.h>
#include<iostream>
#include <vector>
#include "Ëã·¨/bubbleSort.h"
#include "Ëã·¨/selectionSort.h"
#include "Ëã·¨/insertionSort.h"
#include "Ëã·¨/shellSort.h"
#include "Ê÷ºÍ¶þ²æÊ÷/huffmanTree.h"
#include "Í¼/AMGraph.h"
#include "Í¼/ATGraph.h"

using namespace std;

int main() {
    //¹þ·òÂüÊ÷²âÊÔ
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

