#include <string.h>
#include<iostream>
#include <vector>
#include "Ëã·¨/bubbleSort.h"
using namespace std;

int main(){
    vector<int> ivec={7,9,3,21,4,6,3};
    bubbleSort(ivec);
    for(auto e:ivec)
        cout<<e<<" ";
    return 0;
}