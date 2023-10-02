// Selection Sort: Select the element at ith index and swap it with the smaller element found in the range
// 'i+1' to 'n-1', where i runs 'n-1', where n = size of array.

// Approach   --->   Consider the following array: int arr[5] = {55, 45, 35, 25, 15};   here n = 5.

// {55, 45, 35, 25, 15}
//  0   1   2   3   4

// For the outer loop i=0, The element at ith index i.e. 0th index is 15 and
// smallest element in ('i+1'-'n-1')th i.e. (1-4)th index is 55. So, 15 and 55 gets swapped.
// {15, 45, 35, 25, 55}
//  0   1   2   3   4

// For the outer loop i=1, swap the element at ith index i.e. 1th index is 45 and
// smallest element in ('i+1'-'n-1')th i.e. (2-4)th index is 25. So, 45 and 25 gets swapped.
// {15, 25, 35, 45, 55}
//  0   1   2   3   4

// For the outer loop i=2, swap the element at ith index i.e. 2nd index is 35 and
// smallest element in ('i+1'-'n-1')th i.e. (3-4)th index is 35. So, no change in array happens.
// {15, 25, 35, 45, 55}
//  0   1   2   3   4

// For the outer loop i=3, swap the element at ith index i.e. 3rd index is 45 and
// smallest element in ('i+1'-'n-1')th i.e. (4)th index is 55. So, no change in array happens.
// {15, 25, 35, 45, 55}
//  0   1   2   3   4

// Hence, outer loop will always run 'n-1' times, thus it ranges from 0 to 'n-2', where n = size of array.


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
    vector <int> v = {55, 45, 35, 25, 15};

    selectionSort(v);

    print(v);

    return 0;
}