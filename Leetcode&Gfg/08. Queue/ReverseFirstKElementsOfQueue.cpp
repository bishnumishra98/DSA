// GFG: Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue,
// leaving the other elements in the same relative order.
// Only following standard operations are allowed on queue.
// ● enqueue(x) : Add an item x to rear of queue
// ● dequeue() : Remove an item from front of queue
// ● size() : Returns number of elements in queue.
// ● front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be
// used to solve the problem.
// "If the size of queue is smaller than the given k , then return the original queue."

// Example 1:
// Input: q = [1, 2, 3, 4, 5], k = 3
// Output: [3, 2, 1, 4, 5]
// Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5

// Example 2:
// Input: q = [4, 3, 2, 1], k = 4
// Output: [1, 2, 3, 4] 
// Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4

// Algorithm: Not required, it is a cakewalk problem.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(k <= 0 || k > n) return q;

        // Move first k elements of 'q' inside a stack
        stack<int> st;
        while(k--) {
            st.push(q.front());
            q.pop();
        }

        // Move elements from stack in 'ans'; the elements automatically get reversed
        queue<int> ans;
        while(!st.empty()) {
            ans.push(st.top());
            st.pop();
        }

        // Move rest of the elements of 'q' in 'ans'
        while(!q.empty()) {
            ans.push(q.front());
            q.pop();
        }

        return ans;
    }
};

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    queue<int> ans = Solution().reverseFirstK(q, k);
    queue<int> temp = ans;
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    return 0;
}
