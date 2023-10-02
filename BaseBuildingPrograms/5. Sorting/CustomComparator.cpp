#include <iostream>
#include <algorithm>   // for sort()
#include <vector>
using namespace std;

void print1Dvector(vector <int>& v) {
    for(auto i: v) {
        cout << i << " ";
    }
}

void print2Dvector(vector <vector<int>>& v) {
    for(auto i: v) {
        cout << i[0] << " " << i[1] << endl;
    }
}

// comparator function returns a boolean value
// comparator functions instructs the sort() function how to sort an array or 2d array

// this function sorts array in descending order
bool myComp1D(int a, int b) {
    // return a < b;   // sorts array in ascending order, i.e default sort() function
    return a > b;
}

// this function sorts array by sorting second element of each vector in descending order
bool myComp2D(vector <int>& a, vector <int>& b) {
    // return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);   // default sort() function
    return a[1] > b[1];
}

int main() {
    vector <int> v = {55, 35, 45, 15, 25};

    vector <vector<int>> v2 = { {1, 45}, {0, 55}, {0, 25}, {0, 15}, {2, 33} };
    
    // Internally, the sort() function in C++ uses a hybrid sorting algorithm called IntroSort.
    // IntroSort is a combination of three sorting algorithms: Quicksort, Heapsort, and Insertion Sort.
    // It starts by using Quicksort, which is one of the most efficient sorting algorithms. However,
    // if Quicksort is taking too long to sort the data, IntroSort will switch to Heapsort or Insertion
    // Sort. Insertion Sort is the most efficient sorting algorithm for small arrays, so IntroSort will
    // switch to it if the array size is below a certain threshold.

    // int arr[] is sorted like this: sort(arr, arr + n);   where arr denotes base address of the array
    // and n is size of array

    // sort(v.begin(), v.end(), myComp1D);
    // print1Dvector(v);

    sort(v2.begin(), v2.end(), myComp2D);
    print2Dvector(v2);

    return 0;
}