// GFG: Move all negative elements to end   --->   Given an unsorted array arr[ ] having both negative and positive integers.
// The task is to place all negative elements at the end of the array without changing the order of positive elements and
// negative elements.
// Note: Don't return any array, just in-place on the array.

// Example 1:
// Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
// Output : [1, 3, 2, 11, 6, -1, -7, -5]
// Explanation: By doing operations we separated the integers without changing the order.

// Example 2:
// Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
// Output : [7, 9, 10, 11, -5, -3, -4, -1]

// We have already this type of problem in '08_MoveAllNegativeElementsToEnd.cpp', but the only difference
// here is that order of numbers also matters here. Anyways, the algorithm is extremely simple and easy.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // As order of elements is important, 2 pointer approach will fail here. Hence, follow simple brute force method.
    // T.C: O(2n)
    // S.C: O(n)
    void segregateElements(vector<int>& arr) {
        int n = arr.size();
        
        // Create an auxiliary array to hold positive and negative elements
        vector<int> temp;

        // Store positive numbers first
        for(int i = 0; i < n; i++) {
            if (arr[i] > 0) temp.push_back(arr[i]);
        }

        // Store negative numbers next
        for(int i = 0; i < n; i++) {
            if (arr[i] < 0) temp.push_back(arr[i]);
        }

        // Copy the elements of 'temp' back into the original array
        arr = temp;
    }
};


int main() {
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    Solution().segregateElements(arr);
    for(auto it: arr) cout << it << " ";

    return 0;
}
