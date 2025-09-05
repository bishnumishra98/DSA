// Insertion Sort: The array is sorted from left to right. Take one element at a time from the list (starting from
//                 the second one). This one element will be called key element. Compare the key element with the
//                 elements before it. Insert the key element in the correct position among the sorted part. Repeat
//                 until the whole list is sorted.
//                 For inserting the key element in the correct position, we need to right shift all the elements
//                 that are greater than the key element and fall on the left of the key element.

// Illustration:
// Unsorted array: {45, 35, 55, 15, 25}, n = 5
// Pass 1: {35, 45, 55, 15, 25}   // key element is 35. 45 is right shifted and 35 is placed at index 0
// Pass 2: {35, 45, 55, 15, 25}   // key element is 55. 55 is already at the correct position
// Pass 3: {15, 35, 45, 55, 25}   // key element is 15. 35, 45 and 55 are right shifted and 15 is placed at index 0
// Pass 4: {15, 25, 35, 45, 55}   // key element is 25. 35, 45 and 55 are right shifted and 25 is placed at index 1
// No need of Pass 5 as the last element will be the largest element 55.

// Video link: https://www.youtube.com/watch?v=JU767SDMDvA


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

    for(int i = 1; i < n; i++) {
        int keyElement = v[i];
        int j = i - 1;   // j is the index of the last element in the sorted part

        // Find the correct position to insert the keyElement in the sorted part
        while(j >= 0 && v[j] > keyElement) {
            // Right shift the elements that are greater than the keyElement
            v[j + 1] = v[j];
            j--;
        }

        // Insert the keyElement at its correct position
        v[j + 1] = keyElement;
    }
}


int main() {
    vector <int> v = {45, 35, 55, 15, 25};

    insertionSort(v);

    print(v);

    return 0;
}
