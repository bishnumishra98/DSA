// Example:
// Input: nums = [3,2,1,5,6,4], k = 3
// Output: 3

// These type of questions can be solved in 3 mthods:
// 1. Brute force approach (using sort() function)
// 2. Using min heap
// 3. Using max heap

#include <iostream>
#include <vector>
#include <algorithm>   // for sort()
#include <queue>   // for priority_queue
using namespace std;

// T.C: O(NlogN)
// S.C: O(logN);   due to the recursive stack space used by the sorting algorithm of sort()
int findKthSmallest_bruteForce(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());   // sorts array in ascending order
    return nums[k-1];
}

//-----------------------------------------------------------------------------

// T.C: O(N);
// S.C: O(1)
int findKthSmallest_minHeap(vector<int>& nums, int k) {
    // Use a min-heap to store the elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Extract the minimum element (k-1) times
    for (int i = 0; i < k - 1; i++) {
        minHeap.pop();
    }

    // The top element of the heap is now the k-th smallest element
    return minHeap.top();
}

//-----------------------------------------------------------------------------

// T.C: 
// S.C: 
int findKthSmallest_maxHeap(vector<int>& nums, int k) {
    
}

//-----------------------------------------------------------------------------

int main() {
    vector <int> v = {3,2,1,5,6,4};
    int k = 3;

    cout << "Brute force: " << findKthSmallest_bruteForce(v, k) << endl;
    cout << "Min heap: " << findKthSmallest_minHeap(v, k) << endl;


    return 0;
}
