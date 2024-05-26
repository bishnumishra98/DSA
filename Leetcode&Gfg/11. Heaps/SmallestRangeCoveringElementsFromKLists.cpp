// Leetcode: 632. Smallest Range Covering Elements from K Lists   --->   You have k lists of sorted integers in
// non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// Example 1:
// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].

// Example 2:
// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogk);   where n = total number of elements across all arrays, and O(logk) time is required
    //                  to push each element into the heap and extract from heap from k arrays. Thus, for
    //                  n elements, total time required to push and extract from heap will be O(nlogk).
    // S.C: O(n+k);   At any given time, the min-heap stores at most k elements (one from each array).
    //                Hence, the space required for the min-heap is O(k). The merged array ans will store
    //                all n elements, thus it will require O(n) space. Thus, overall space complexity is O(n+k).
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store elements as (value, list index, element index)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        // When we specify 'greater<vector<int>>', the priority_queue uses the 'operator>' to order the elements.
        // For a vector, this means it will compare the elements lexicographically, which works if the first element
        // of the vector is what you want to prioritize (the smallest element in our case). Thus, creating a custom comparator
        // is not mandatory here. However, if you want, you can create a custom comparator outside this function like this:
        /*
        struct Compare {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[0] > b[0];
            }
        };
        */

        // Track the maximum element in the current range
        int maxValue = INT_MIN;
        
        // Initialize the heap with the first element of each list, also store the maximum element of them.
        for(int i = 0; i < nums.size(); ++i) {
            if(!nums[i].empty()) {   // Ensure the vector is not empty
                minHeap.push({nums[i][0], i, 0});   // Push (value, list index, element index)
                maxValue = max(maxValue, nums[i][0]);
            }
        }

        // Initialize the result range
        int start = minHeap.top()[0];
        int end = maxValue;
        
        // Process the elements in the heap
        while(true) {
            // Get the smallest element from the heap
            vector<int> current = minHeap.top();
            // auto current = minHeap.top();   // we can even use 'auto' data-type here
            minHeap.pop();
            int minValue = current[0];
            int listIndex = current[1];   // listIndex is nothing but rowIndex
            int elementIndex = current[2];   // elementIndex is nothing but colIndex 

            // Update the range if the current range is smaller
            if(maxValue - minValue < end - start) {
                start = minValue;
                end = maxValue;
            }

            // If the current list is exhausted, break the loop
            if(elementIndex + 1 == nums[listIndex].size()) break;

            // Insert the next element of the current list into the heap
            int nextValue = nums[listIndex][elementIndex + 1];
            minHeap.push({nextValue, listIndex, elementIndex + 1});
            maxValue = max(maxValue, nextValue);
        }

        return {start, end};
    }
};

int main() {
    vector<vector<int>> v = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    Solution sol;
    vector<int> ans = sol.smallestRange(v);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
