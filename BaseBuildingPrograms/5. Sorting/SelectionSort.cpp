// Selection Sort: Keep finding and inserting smallest element at ith index, where i runs 'n-1' times,
// where n = size of array.

// Approach   --->   Consider the following array: int arr[5] = {45, 35, 55, 25, 15};   here n = 5.

// {45, 35, 55, 25, 15}
//  0   1   2   3   4

// For the outer loop i=0, swap element at 0th index, i.e. 45 and smallest element at (1-4)th index, i.e. 15.
// {15, 35, 55, 25, 45}
//  0   1   2   3   4

// For the outer loop i=1, swap element at 1st index, i.e. 35 and smallest element at (2-4)th index, i.e. 25.
// {15, 25, 55, 35, 45}
//  0   1   2   3   4

// For the outer loop i=2, swap element at 2nd index, i.e. 55 and smallest element at (3-4)th index, i.e. 35.
// {15, 25, 35, 55, 45}
//  0   1   2   3   4

// For the outer loop i=3, swap element at 3rd index, i.e. 55 and smallest element,
// aka the only element at 4th index, i.e. 45.
// {15, 25, 35, 45, 55}
//  0   1   2   3   4


#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v) {
    for(auto i: v) {
        cout << i << " ";
    }
}

// T.C: O(n2)
// S.C: O(1)
void selectionSort(vector<int>& v) {
    int n = v.size();

    for(int i=0; i<n-1; i++) {
        // let index of smallest element be 'minIndex'. Consider 'minIndex=i' initially.
        int minIndex = i;

        // If any element at (i+1 to n-1)th index is found to be smaller than that at 'minIndex'th,
       // we shall update 'minIndex' as 'index of that element'.
        for(int j=i+1; j<n; j++) {
            if(v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

       // swapping element at ith index with element at minIndexth index.
        swap(v[i], v[minIndex]);
    }
}


int main() {
    vector <int> v = {45, 35, 55, 25, 15};

    selectionSort(v);

    print(v);

    return 0;
}