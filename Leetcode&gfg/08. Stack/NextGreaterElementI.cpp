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

// This problem is already solved in 'BaseBuildingPrograms\14. Stack\S10_NextGreaterElement.cpp',
// the only addition here is that we have an extra drama of an extra array.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // T.C: O(n2 + n1*n2);  note that time complexity is dominated by the nested loop in the
    //                      second part of the code, and it can be optimized further using hashmap.
    // S.C: O(n2 + n1)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector <int> ans(n2);
        stack <int> st;
        st.push(-1);

        for(int i=n2-1; i>=0; i--) {
            int currElement = nums2[i];

            while(!st.empty() && currElement >= st.top()) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            } else {
                ans[i] = -1;
            }

            st.push(currElement);
        }

        // nextGreaterElement for the array nums2 have been created in 'ans'.
        // Now the extra drama begins.
        int n1 = nums1.size();
        vector <int> v;

        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                if(nums1[i] == nums2[j]) {
                    // finding that nums1 element in nums2, and pushing
                    // corresponding same 'j' indexed element from 'ans' into 'v'.
                    v.push_back(ans[j]);
                }     
            }
        }

        return v;
    }
};

int main() {
    Solution obj;
    vector <int> nums1{2, 4};
    vector <int> nums2{1, 2, 3, 4};

    vector <int> ans = obj.nextGreaterElement(nums1, nums2);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}


// More optimized solution using hashmap:
#include <unordered_map>
// T.C: O(n1 + n2)
// S.C: O(n2)
vector<int> nextGreaterElement_hashmap(vector<int>& nums1, vector<int>& nums2) {
    int n2 = nums2.size();
    vector<int> ans(n2);
    stack<int> st;
    unordered_map<int, int> nextGreater;

    // Calculate next greater element for each element in nums2
    for (int i = n2 - 1; i >= 0; i--) {
        int currElement = nums2[i];

        while (!st.empty() && currElement >= nums2[st.top()]) {
            st.pop();
        }

        if (!st.empty()) {
            nextGreater[nums2[i]] = nums2[st.top()];
        } else {
            nextGreater[nums2[i]] = -1;
        }

        st.push(i);
    }

    // Populate the result for nums1 using the hashmap
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater[num]);
    }

    return result;
}
