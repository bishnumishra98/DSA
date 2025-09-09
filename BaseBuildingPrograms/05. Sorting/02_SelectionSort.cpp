// Selection Sort: During each pass, the smallest element from the unsorted part of the array is selected and
//                 moved to the sorted part of the array. The sorted part is built from left to right.
//                 After the first pass, the smallest element will be at the first index, after the second
//                 pass the second smallest element will be at the second index and so on.
//                 Hence, to sort an array of size n, we need to do n - 1 passes. Depending upon the sorting
//                 order, the same logic can be applied to sort the array in descending order too.

// Illustration: 
// Unsorted array: {55, 45, 35, 25, 15}, n = 5
// Pass 1: {15, 45, 35, 25, 55}   // smallest element 15 is selected from the unsorted part and swapped with the first element
// Pass 2: {15, 25, 35, 45, 55}   // second smallest element 25 is selected from the unsorted part and swapped with the second element
// Pass 3: {15, 25, 35, 45, 55}   // third smallest element 35 is selected from the unsorted part and swapped with the third element
// Pass 4: {15, 25, 35, 45, 55}   // fourth smallest element 45 is selected from the unsorted part and swapped with the fourth element
// No need of Pass 5 as the last element will be the largest element 55.

// Video link: https://www.youtube.com/watch?v=g-PGLbMth_g

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
void selectionSort(vector<int>& v) {
    int n = v.size();

    for(int i = 0; i < n - 1; i++) {
        // 'minIndex' points to the index of the smallest element from ith index to the second last index.
        int minIndex = i;   // assuming the element at ith index is the smallest element

        // Update the 'minIndex' with the smallest element found in the unsorted part, i.e.,
        // smallest element on the right of ith index.
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[minIndex]) minIndex = j;
        }

        // Swap the ith element with the smallest element found in the unsorted part.
        swap(v[i], v[minIndex]);
    }
}


int main() {
    vector <int> v = {55, 45, 35, 25, 15};

    selectionSort(v);

    print(v);

    return 0;
}
