// GFG: Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board
// is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter
// takes 1 unit time to paint 1 unit of the board.
// Return the minimum time to get this job done if all painters start together with the constraint that any painter
// will only paint continuous boards, say boards numbered [2,3,4] or only board [1] or nothing but not boards [2,4,5].

// Example 1:
// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30],
// Painter 3 allocation : [20,15], Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35

// Example 2:
// Input: arr[] = [10, 20, 30, 40], k = 2
// Output: 60
// Explanation: The most optimal way to paint: Painter 1 allocation : [10,20,30], Painter 2 allocation : [40],
// Job will be complete at time = 60

// Example 3:
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 1000
// Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken
// will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    long long minTime(vector<int>& arr, int k) {
        
    }
};

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;
    cout << Solution().minTime(arr, k);

    return 0;
}
