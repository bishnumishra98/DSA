// GFG: Minimum Multiplications to reach End   --->   Given start, end and an array arr of n numbers. At each step,
// start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.
// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to
// reach end, then return -1.

// Example 1:
// Input:
// arr[] = {2, 5, 7}
// start = 3, end = 30
// Output:
// 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30

// Example 2:
// Input:
// arr[] = {3, 4, 65}
// start = 7, end = 66175
// Output:
// 4
// Explanation:
// Step 1: 7*3 = 21 % 100000 = 21 
// Step 2: 21*3 = 63 % 100000 = 63 
// Step 3: 63*65 = 4095 % 100000 = 4095 
// Step 4: 4095*65 = 266175 % 100000 = 66175

// Your Task:
// You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr,
// an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in
// which end can be achieved starting from start.

// Expected Time Complexity: O(10^5)
// Expected Space Complexity: O(10^5)

// Problem link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0

// Algorithm: It is a simple BFS. We will start from the start node and keep on multiplying it with the numbers in the array
// and then take mod with 100000. We will keep on doing this until we reach the end node.
// 1. i.  Create a queue and push the steps to reach start(0) along with start node in it. We will be following Djiakstra's
//       algorithm, but a priority queue is not required here as we are not dealing with weights. We just need to keep track
//       of the steps taken to reach a node. So a queue will also work fine.
//    ii. Create a vector dist of size 100000 and initialize it with 1e9.
// 2. Initialize dist[start] = 0, as we need 0 steps to reach start from start.
// 3. Run a loop until the queue is not empty.
//    i.  Get the front element of the queue and pop it. Extract the steps and node from it.
//    ii. For each number in the array, calculate the new node by multiplying the node with the number and taking mod with
//        100000. If the steps + 1 is less than dist[num], it means we have found a shorter path to reach num. Update the
//        dist[num] with steps + 1 and push the steps + 1 and num in the queue.
// 4. If we reach the end node, return steps + 1.
// 5. If we are not able to reach the end node, return -1.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(10^5);   but it is hypothetical if all the nodes are visited which is practically never possible. So actual
    //                 time complexity will be much less than this.
    // S.C: O(10^5)
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;   // {steps, node}
        q.push({0, start});
        vector<int> dist(100000, 1e9);

        dist[start] = 0;
        int mod = 100000;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second;

            for(auto it: arr) {
                int num = (node * it) % mod;
                if(steps + 1 < dist[num]) {
                    if(num == end) return steps + 1;
                    dist[num] = steps + 1;
                    q.push({steps + 1, num});
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;

    Solution obj;
    cout << obj.minimumMultiplications(arr, start, end);

    return 0;
}
