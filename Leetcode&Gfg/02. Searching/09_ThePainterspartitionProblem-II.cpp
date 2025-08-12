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

// Problem link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

// Algorithm: As it's almost same problem as '08_AllocateMinimumPages.cpp', we will directly write Binary search approach.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Returns true if it's possible to paint all boards with 'k' painters in 'maxTimeAllowed' time, else false.
    bool isPossible(vector<int>& arr, long long maxTimeAllowed, int k) {
        int painters = 1;   // no.of painters (start with one painter initially)
        long long timePainter = 0;   // 'timePainter' is the time taken by current painter
        for(int i = 0; i < arr.size(); i++) {
            if(timePainter + arr[i] <= maxTimeAllowed) timePainter += arr[i];
            else {
                painters++;
                timePainter = arr[i];
            }
        }

        // If the number of painters exceeds 'k', then it's not possible to paint all boards in 'maxTimeAllowed' time.
        return painters > k ? false : true;
    }

public:
    // T.C: O(log(end - start + 1) * n);   where end = sum of all elements of 'arr', start = maximum element of 'arr', and n = arr.size()
    // S.C: O(1)
    long long minTime(vector<int>& arr, int k) {
        // ONLY CHANGE IN CODE: If there are more painters than boards, return the largest board length
        if (k >= arr.size()) return *max_element(arr.begin(), arr.end());

        long long start = *max_element(arr.begin(), arr.end());
        long long end = accumulate(arr.begin(), arr.end(), 0);

        long long ans = -1;
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            if(isPossible(arr, mid, k)) {   // if it's possible to paint all boards with 'k' painters in 'mid' time
                ans = mid;
                end = mid - 1;
            } else start = mid + 1;
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;
    cout << Solution().minTime(arr, k);

    return 0;
}
