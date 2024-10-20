// GFG: Common in 3 Sorted Arrays   --->   You are given three arrays sorted in increasing order. Find the elements
// that are common in all three arrays.
// If there are no such elements return an empty array. In this case, the output will be -1.
// Note: can you handle the duplicates without using any additional Data Structure?

// Example 1:
// Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
// Output: [20, 80]
// Explanation: 20 and 80 are the only common elements in arr, brr and crr.

// Example 2:
// Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
// Output: [-1]
// Explanation: There are no common elements in arr, brr and crr.

// Example 3:
// Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
// Output: [1, 2]
// Explanation: We do not need to consider duplicates

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^3)
    // S.C: O(n)
    vector<int> commonElements_bruteforce(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> commonElements;

        for(int i = 0; i < arr1.size(); i++) {
            for(int j = 0; j < arr2.size(); j++) {
                for(int k = 0; k < arr3.size(); k++) {
                    if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) commonElements.push_back(arr1[i]);
                }
            }
        }

        if(commonElements.size() > 0) return commonElements;
        return {-1};
    }

// ---------------------------------------------------------------------------------------------------------------

    // Optimal algorithm: We shall use 3 pointer approach in this problem and take advantage of the fact that all arrays are sorted.
    
    // T.C: O(n)
    // S.C: O(n)
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> commonElements;

        
    }
};


int main() {
    vector<int> arr1 = {1, 5, 10, 20, 40, 80} , arr2 = {6, 7, 20, 80, 100}, arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> ans = Solution().commonElements_bruteforce(arr1, arr2, arr3);
    for(auto it: ans) cout << it << " ";
    cout << endl;
    vector<int> ans = Solution().commonElements(arr1, arr2, arr3);
    for(auto it: ans) cout << it << " ";

    return 0;
}
