// Leetcode: 239. Sliding Window Maximum   --->   You are given an array of integers nums, there is
//  a sliding window of size k which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window moves right by one
// position. Return the max sliding window.

// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n * k)
    // S.C: O(1)
    vector<int> maxSlidingWindow_bruteForce(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for(int i = 0; i <= n - k; i++) {
            int maxInWindow = nums[i];
            for(int j = i; j < i + k; j++) {
                maxInWindow = max(maxInWindow, nums[j]);
            }
            result.push_back(maxInWindow);
        }

        return result;
    }


    // T.C: O(n)
    // S.C: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 0 || n == 0 || k > n) return {};

        vector<int> ans;
        deque<int> dq;   // will store indexes of elements that are in current window (front
                       // of deque will have index of largest element of current window)

        // Step 1: Find maximum element of first window of size k
        for(int i = 0; i < k; i++) {
            // Remove smaller elements from back (they can't be max if nums[i] is greater than them)
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);   // first window's max

        // Step 2: Slide window from i = k to n - 1
        for(int i = k; i < n; i++) {
            // Remove indexes that are out of this window
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();

            // Remove smaller elements from back (they can't be max if nums[i] is greater than them)
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            // Insert current element's index at the back of deque
            dq.push_back(i);

            // Current window's max
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};


int main() {
    vector <int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution obj;
    vector<int> ans1 = obj.maxSlidingWindow_bruteForce(nums, k);
    for(auto i: ans1) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans2 = obj.maxSlidingWindow(nums, k);
    for(auto i: ans2) {
        cout << i << " ";
    }

    return 0;
}
