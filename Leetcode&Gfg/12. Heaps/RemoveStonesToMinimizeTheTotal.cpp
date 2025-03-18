// Leetcode. 1962. Remove Stones to Minimize the Total   --->   You are given a 0-indexed integer array piles,
// where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following
// operation exactly k times:
// Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
// Notice that you can apply the operation on the same pile more than once.
// Return the minimum possible total number of stones remaining after applying the k operations.

// Example 1:
// Input: piles = [5,4,9], k = 2
// Output: 12
// Explanation: Steps of a possible scenario are:
// - Apply the operation on pile 2. The resulting piles are [5,4,5].
// - Apply the operation on pile 0. The resulting piles are [3,4,5].
// The total number of stones in [3,4,5] is 12.

// Example 2:
// Input: piles = [4,3,6,7], k = 3
// Output: 12
// Explanation: Steps of a possible scenario are:
// - Apply the operation on pile 2. The resulting piles are [4,3,3,7].
// - Apply the operation on pile 3. The resulting piles are [4,3,3,4].
// - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
// The total number of stones in [2,3,3,4] is 12.

// Algorithm: To create the minimum possible total number of stones, we have reduce the largest elements of piles array. To do so:
// 1. Create a max-heap with all elements of piles. Hence, top element of max-heap will be largest element of piles array.
// 2. Perform the following operations k no.of times:
//    i.  Pop the top element of max-heap and reduce it as instructed: (piles[i] = piles[i] - floor(piles[i]/2)).
//    ii. After reduction, push it back into the max-heap.
// 3. Finally after k operations have been completed, find the sum of all elements of max-heap and return it.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n) + O(klogn) + O(nlogn) = O((n+k)logn);   O(n) time is required to construct the max-heap. O(logn) time is required
    //      to remove top element from heap; thus doing this operation k times needs O(klogn) time. Finally, removing each element
    //      from heap takes O(logn) time, thus removing all elements will take O(nlogn) time.
    // S.C: O(n);   space required by max-heap
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        // Inserting all elements of piles, into maxHeap.
        for(int i=0; i<piles.size(); i++) {
            maxHeap.push(piles[i]);
        }

        // Do the following k no.of times
        while(k--) {
            int largest = maxHeap.top();
            maxHeap.pop();
            largest = largest - largest/2;   // 'floor(largest/2)' means 'largest/2' only
            maxHeap.push(largest);
        }

        // Return the sum of all elements of maxHeap
        int sum = 0;
        while(!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};

int main() {
    vector<int> piles = {4, 3, 6, 7};
    int k = 3;

    Solution sol;
    cout << sol.minStoneSum(piles, k);

    return 0;
}
