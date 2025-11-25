// Leetcode: 496. Next Greater Element I   --->   The next greater element of some element x in an
// array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset
// of nums2. For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and
// determine the next greater element of nums2[j] in nums2. If there is no next greater element,
// then the answer for this query is -1. Return an array ans of length nums1.length such that
// ans[i] is the next greater element as described above.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

// Algorithm:
// Same as 'BaseBuildingPrograms\14. Stack\S10_NextGreaterElement.cpp'. It is just an easy variant of that problem.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n1 + n2)
    // S.C: O(n1 + n2)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // This map will store: an element from nums2  -> its next greater element in nums2
        unordered_map<int, int> nextGreater;

        // CHEAT CODE: Decreasing stack + RL traversal of nums2
        stack<int> st;

        // Step 1: Process nums2 from RIGHT to LEFT and fill "nextGreater" map
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int currElement = nums2[i];

            // Continuously pop out top element of stack if current array element is greater than or equal to top element of stack
            while (!st.empty() && currElement >= st.top()) {
                st.pop();
            }

            /// Store top element of stack in nextGreater map, i.e., store {currElement -> its next greater element}
            if(!st.empty()) nextGreater[currElement] = st.top();
            else nextGreater[currElement] = -1;

            // Push the smaller array element into stack now
            st.push(currElement);
        }

        // Step 2: Build answer for nums1 using the map
        vector<int> ans;
        for(int x : nums1) ans.push_back(nextGreater[x]);

        return ans;
    }
};

int main() {
    Solution obj;
    vector <int> nums1{2, 4};
    vector <int> nums2{1, 2, 3, 4};

    vector <int> ans = obj.nextGreaterElement(nums1, nums2);

    for(auto i: ans) {
        cout << i << " ";   // o/p: 3 -1
    }

    return 0;
}
