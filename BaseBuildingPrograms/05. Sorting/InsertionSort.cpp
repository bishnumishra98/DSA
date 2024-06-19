// Insertion Sort: Starting from 1st to 'n-1' index, pick one element at a time and comparing it with the
// elements on its left, insert it on its correct index.

// Approach   --->   Consider the following array: int arr[5] = {45, 35, 55, 15, 25};   here n = 5.

// {45, 35, 55, 15, 25}
//  0   1   2   3   4

// For outer loop i=1,
// {35, 45, 55, 15, 25}
//  0   1   2   3   4
//  j   i

// For outer loop i=2, no change:
// {35, 45, 55, 15, 25}
//  0   1   2   3   4
//      j   i

// For outer loop i=3,
// {15, 35, 45, 55, 25}
//  0   1   2   3   4
//          j   i

// For outer loop i=4,
// {15, 25, 35, 45, 55}
//  0   1   2   3   4
//              j   i

// Hence, for n = 5, outer loop runs 'n-1' times. i represents outer loop, and j represents inner loop.
// i runs from 1 to 'n-1'; and j runs from 'i-1' to 0. Dry run for better understanding.


#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v) {
    for(auto i: v) {
        cout << i << " ";
    }
}

// T.C: O(n^2)
// S.C: O(1)
void insertionSort(vector<int>& v) {
    int n = v.size();

    for(int i=1; i<n; i++) {
        int keyElement = v[i];
        int j = i-1;

        while(j>=0 && v[j]>keyElement) {
            // right shifting elements by 1 index that are bigger than key and fall on left of key
            v[j+1] = v[j];
            j--;
        }

        // When program comes out of while loop, j is either -1 or v[j] is smaller than keyElement.
        // v[j+1] is the index from where right elements are greater than keyElement and left elements
        // are smaller than keyElement, i.e. it is the accurate index to place keyElement
        v[j+1] = keyElement;
    }
}


int main() {
    vector <int> v = {45, 35, 55, 15, 25};

    insertionSort(v);

    print(v);

    return 0;
}