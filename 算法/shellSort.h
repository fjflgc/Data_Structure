#include <vector>

using namespace std;

template<typename T>
void shellSort(vector<T> &vec) {
    int h = 1;
    while (h < vec.size()/3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < vec.size(); i++) {
            int tmp = vec[i];
            int j = i - h;
            while (j >= 0 && tmp < vec[j]) {
                vec[j + h] = vec[j];
                j-=h;
            }
            vec[j+h]=tmp;
        }
        h = h / 3;
    }
}