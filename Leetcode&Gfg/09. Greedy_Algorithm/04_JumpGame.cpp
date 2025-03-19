// GFG: Jump Game   --->   Given a array of positive integers arr, where each element denotes the maximum length of jump
// you can cover. Find out if you can make it to the last index starting from the first index of the list, return true if
// you can reach the last index.

// Example 1:
// Input: arr = [1, 2, 0, 3, 0, 0] 
// Output: true
// Explanation: Jump 1 step from first index to second index. Then jump 2 steps to reach 4th index, and now jump 2 steps to
//              reach the end.

// Example 2:
// Input: arr = [1, 0, 2]
// Output: false
// Explanation: You can't reach the end of the array.

// Example 3:
// Input: arr = [1, 2, 3, 1, 2, 0, 2, 5]
// Output: true
// Explanation: Path to cross this array is via index 0 -> 1 -> 2 -> 4 -> 6 -> 7.

// Problem link: https://www.geeksforgeeks.org/problems/jump-game/1

// Algorithm: This is a very simple greedy approach.
// 1. We will keep track of the maximum reach we can reach from the current index.
// 2. If at any point, the current index is greater than the maximum reach, then we can't reach the end of the array.
// 3. Otherwise, we will update the maximum reach with the maximum of the current maximum reach and the current index + arr[i].
// 4. If we are able to reach the end of the array, then return true.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n);   where n = arr.size()
    // S.C: O(1)
    bool canReach(vector<int> &arr) {
        int maxReach = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + arr[i]);
            // Optional: If maxReach is already greater than or equal to the last index, then we can easily cross the array.
            // Thus, return true. This optional line may help reduce the number of unnecessary iterations.
            if(maxReach >= arr.size() - 1) return true;   
        }

        return true;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 1, 2, 0, 2, 5};

    Solution obj;
    cout << obj.canReach(arr);

    return 0;
}
