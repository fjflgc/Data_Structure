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
