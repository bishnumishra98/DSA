// Given an unsorted array arr[ ] having both negative and positive integers. The task is to place all
// negative elements at the end of the array.
// Note: Don't return any array, just in-place on the array.

// Example 1:
// Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
// Output : [1, 6, 3, 2, 11, -5, -7, -1]

// Example 2:
// Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
// Output : [7, 9, 10, 11, -5, -3, -4, -1]




// Brute force algorithm: Just sort the array in reverse order -> sort(arr.begin(), arr.end(), greater<int>())
//                        OR reverse(arr.begin(), arr.end()).

// Optimal algorithm: Almost same as 'BaseBuildingPrograms\03. Arrays\06_ShiftNegativeToLeft.cpp'.

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(n)
// S.C: O(1)
void segregateElements(vector<int>& arr) {
    int i = 0, j = 0;

    while(i < arr.size()) {
        if(arr[i] > 0) {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
}

int main() {
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    segregateElements(arr);
    for(auto it: arr) cout << it << " ";

    return 0;
}
