
#include <vector>
using namespace std;

template<typename T>
void selectionSort(vector<T> &vec){
    for(int i=0;i<vec.size()-1;i++){
             int min_pos=i;
        for(int j=i+1;j<vec.size();j++){
           if(vec[min_pos]>vec[j])
               min_pos=j;
        }
        swap(vec[i],vec[min_pos]);
    }
}