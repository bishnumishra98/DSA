// Given an unsorted array arr[ ] having both negative and positive integers. The task is to place all
// negative elements at the end of the array.
// Note: Don't return any array, just in-place on the array.

// Example 1:
// Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
// Output : [1, 6, 3, 2, 11, -5, -7, -1]

// Example 2:
// Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
// Output : [7, 9, 10, 11, -5, -3, -4, -1]


// Brute force algorithm: Just sort the array in reverse order -> sort(arr.begin(), arr.end(), greater<int>());

// Algorithm: We will follow 2 pointer approach here. The algorithm is extremely easy.
// 1. Create and point left and right pointers at index 0 and n-1 respectively. The left pointer is supposed
//    to point on positive numbers, while the right one is supposed to point on negative numbers.
// 2. If the left pointer is already pointing on a positive number, move the pointer ahead towards right, to check
//    whether the next element is also pointing on a positive number or not.
//    Similarly, if the right pointer is already pointing on a negative number, move the pointer back towards left,
//    to check whether the next element is also pointing on a ngative number or not.
//    If the none of the above two cases are true, it means both pointers are pointing to wrong elements.
//    Hence, swap the elements of left and right. Continue the process until left reaches right pointer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    void segregateElements(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while(left < right) {
            if(arr[left] > 0) left++;
            else if(arr[right] < 0) right--;
            else swap(arr[left], arr[right]);
        }
    }
};

int main() {
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    Solution().segregateElements(arr);
    for(auto it: arr) cout << it << " ";

    return 0;
}
