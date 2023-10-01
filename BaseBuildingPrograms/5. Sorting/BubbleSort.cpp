// Buuble Sort: Compare two adjacent elements at index i and i+1, if element 
//  at ith index is greater than that present at (i+1)th index, then swap them.

// Approach   --->    Consider worst case scenario : Let arr[5] = {55, 45, 35, 25, 15};  here n = 5.

// For the outer loop i=0, inner loop takes (n-i-1) iterations,
// i.e 4 iterations to position the highest element at last index.
// {45, 55, 35, 25, 15}
// {45, 35, 55, 25, 15}
// {45, 35, 25, 55, 15}
// {45, 35, 25, 15, 55}

// Similarly for i=1, it takes (n-i-1) iterations,
// i.e 3 iterations to position the 2nd highest element at 2nd last index.
// {35, 45, 25, 15, 55}
// {35, 25, 45, 15, 55}
// {35, 25, 15, 45, 55}

// Similarly for i=2, it takes (n-i-1) iterations,
// i.e 2 iterations to position the 3rd highest element at 3rd last index.
// {25, 35, 15, 45, 55}
// {25, 15, 35, 45, 55}

// Similarly for i=3, it takes (n-i-1) iterations,
// i.e 1 iteration to position the 4th highest element at 4th last index.
// {15, 25, 35, 45, 55}

// The 5th highest element, i.e the smallest element is automatically sorted, so no more iterations required.

// Thus, to sort a strictly unsorted array of 5 elements, outer loop should run 4 times, i.e. (n-1) times,
// i.e. i goes from 0 to 3; and inner loop runs (n-i-1) times. Inner loop will be represented by j.
// j is nothing, but indexes of elements in array. Dry run for better understanding.

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
void bubbleSort(vector<int>& v) {
    int n = v.size();

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}


int main() {
    vector <int> v = {55, 45, 35, 25, 15};

    bubbleSort(v);

    print(v);

    return 0;
}