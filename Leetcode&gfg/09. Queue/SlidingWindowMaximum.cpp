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

// Algorithm:

// 1) Initialize a vector where we will built the answer, and a deque where we will keep a track of
//    index of largest element of each window in the given array. The index of largest element shall
//    reside at the front of deque followed by indexes of smaller elements of a window. And yeah
//    that's obvious that at any given time frame, the deque can contain at max k no.of elements.

// 2) Iterate each element of given array in a loop and follow the 4 step process:
//    i)   Remove the index of element from deque that is out of range for the current window, i.e.,
//         pop the front index of deque if its corresponding element is not in the window.
//    ii)  Pop back indexes of deque if its corresponding elements are smaller than element at ith
//         index. This will ensure that indexes residing in deque are arranged in fashion of largest
//         to smallest element on seeing from Left to Right of deque.
//    iii) Push the ith index on back of deque. Obviously, this ith index corresponds to the smallest
//         element of current window, as we popped out all smaller elements than this in the above step.
//         We are even storing the smallest element of the window at back of deque, because there is a
//         possibility that it may come out to be the largest element for any future window.
//    iv)  Push the element corresponding to front index of deque in the 'ans'. This is the largest
//         element of the current window. Note that, push elements in 'ans' only after we have reached
//         'k-1'th index of 'nums', as because we cannot predict the maximum element of 1st window
//          before reaching 'k-1'th index.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // T.C: O(n*k)
    // S.C: O(1)
    vector<int> maxSlidingWindow_bruteForce(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> result;

        for(int i = 0; i <= n - k; i++) {
            int maxInWindow = nums[i];   // first element of window is initially stored in 'maxInWindow'.
            for (int j = i; j < i + k; j++) {   // Then we compare value inside 'maxInWindow' with
            // the rest 'k-1' elements of the window. Thus, we want inner loop to run only 'k-1' times.
                maxInWindow = max(maxInWindow, nums[j]);
            }
            result.push_back(maxInWindow);
        }

        return result;
    }


    // T.C: O(n + n) = O(n)
    // S.C: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans;
        deque <int> q;

        for(int i = 0; i < n; i++) {
            // Step 1: Remove the index from queue that is out of window.
            if(!q.empty() && q.front() == i-k) q.pop_front();

            // Step 2: Pop out elements from queue that are smaller than ith element.
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();

            // Step 3: Push the index of ith element in queue
            q.push_back(i);

            // Step 4: Push the max element of each window in 'ans'. Note that push elements in 'ans'
            //         only after we have reached 'k-1'th index of 'nums', as because we cannot predict
            //         the maximum element of 1st window before checking or reaching 'k-1'th index.
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};

int main() {
    vector <int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution obj;
    vector <int> ans = obj.maxSlidingWindow_bruteForce(nums, k);
    // vector <int> ans = obj.maxSlidingWindow(nums, k);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
