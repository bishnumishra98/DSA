// Buuble Sort: The largest numbers will bubble it's way to the right side of the array.
//              Compare two elements at a time and swap if they are not in order, i.e., swap if left element is greater
//              than the right element as our aim is to bubble the larger element to the right side of the array.
//              In the first pass, the largest element will be at the last index, in the second pass the second largest
//              element will be at the second last index and so on.
//              Hence, to sort an array of size n, we need to do n - 1 passes.

// Illustration:
// Unsorted array: {55, 45, 35, 25, 15}, n = 5

// Pass 1: {45, 35, 25, 15, 55}   // largest element 55 bubbles it's way through comparisions and reaches the last index
// Pass 2: {35, 25, 15, 45, 55}   // second largest element 45 bubbles it's way through comparisions and reaches the second last index
// Pass 3: {25, 15, 35, 45, 55}   // third largest element 35 bubbles it's way through comparisions and reaches the third last index
// Pass 4: {15, 25, 35, 45, 55}   // fourth largest element 25 bubbles it's way through comparisions and reaches the fourth last index
// No need of Pass 5 as the first element will be the smallest element 15.
// Sorted array: {15, 25, 35, 45, 55}

// Video link: https://www.youtube.com/watch?v=xli_FI7CuzA


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
void bubbleSort(vector<int>& v) {
    int n = v.size();

    // After each pass, the largest element will be at the end of the unsorted array, so
    // do not need to check it again. Hence, reduce the range of j by i after each pass.
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}


int main() {
    vector <int> v = {55, 45, 35, 25, 15};

    bubbleSort(v);

    print(v);

    return 0;
}
