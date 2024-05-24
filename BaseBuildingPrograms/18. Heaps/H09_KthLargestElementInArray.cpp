// Example:
// Input: nums = [3,2,1,5,6,4], k = 3
// Output: 4

// These type of questions can be solved in 3 mthods:
// 1. Brute force approach (using sort() function)
// 2. Better approach (using max heap)
// 3. Optimal approach (using min heap)

#include <iostream>
#include <vector>
#include <algorithm>   // for sort()
#include <queue>   // for priority_queue
using namespace std;

// T.C: O(NlogN)
// S.C: O(logN);   due to the recursive stack space used by the sorting algorithm of sort()
int findKthLargest_bruteForce(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());   // sorts array in descending order
    return nums[k-1];
}

//-----------------------------------------------------------------------------

// T.C: O(N + (k-1)*logN);   Building the heap from N elements of 'nums' takes O(N) time. Each pop operation from
//                           a heap of size N takes O(logN) time. Therefore, popping k-1 elements will take
//                           O((k-1)*logN) time. Combining these steps, the total time complexity is O(N + (k-1)*logN).
// S.C: O(N);   The priority queue (max-heap) stores all N elements from the 'nums' vector, which requires O(N) space.
int findKthLargest_maxHeap(vector<int>& nums, int k) {
    /*
    // Create a max-heap and then store the elements from 'nums' vector into the max-heap
    priority_queue<int> maxHeap;
    for(int i=0; i<nums.size(); i++) {
        maxHeap.push(nums[i]);
    }
    */
    
    // The above process to use a max-heap and store the elements from 'nums' vector in it, can be done in 1 single line
    priority_queue<int> maxHeap(nums.begin(), nums.end());

    // Pop (k-1) elements, so that kth largest element is on top of priority_queue
    for (int i = 0; i < k-1; i++) {
        maxHeap.pop();
    }

    // The top element of the heap is now the k-th largest element
    return maxHeap.top();
}

//-----------------------------------------------------------------------------

// Algorithm:
// 1. Create a min-heap using the first k elements of the given input array.
// 2. The top element of the min-heap is the smallest among the first k elements. For each remaining element in the array,
//    compare it with the top element of the min-heap and if the current element is larger than the top element of the
//    min-heap, remove the top element from the heap and insert the current element into the heap.
// 3. After processing all elements, the top element of the min-heap is the k-th largest element of the input array.

// T.C: O(k + (N−k)logk);   Building the heap from k elements of 'nums' takes O(k) time. For the remaining 'n−k' elements,
//                          if the if condition is true, the algorithm performs a two heap operations (pop and push) which
//                          takes O(logK) time.e. Since this is done for each of 'n−k' elements, the total time complexity
//                          becomes O((n−k)logk). Combining these steps, the total time complexity is O(k + (N−k)logk).
// S.C: O(K);   The priority queue (min-heap) stores K elements from the 'nums' vector, which requires O(K) space.
int findKthLargest_minHeap(vector<int>& nums, int k) {
    // Step 1: Make a min-heap from the first k elements of the given input array

    /*
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<k; i++) {
        minHeap.push(nums[i]);
    }
    */

    // The above process to use a min-heap and store the first 'k' elements from 'nums', can be done in 1 single line
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + k);

    // Step 2: Compare the rest of the elements with the top element of the min-heap
    for(int i=k; i<nums.size(); i++) {
        if(nums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    // The top element of the min-heap is the k-th Largest element
    return minHeap.top();
}

//-----------------------------------------------------------------------------

int main() {
    vector <int> v = {3,2,1,5,6,4};
    int k = 3;

    cout << "Brute force: " << findKthLargest_bruteForce(v, k) << endl;
    cout << "Max heap: " << findKthLargest_maxHeap(v, k) << endl;
    cout << "Min heap: " << findKthLargest_minHeap(v, k) << endl;
    
    return 0;
}
