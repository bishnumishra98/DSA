// GFG: Given a queue q[] of even size. Your task is to rearrange the queue by interleaving its first half with
// the second half.
// Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
// In other words, Interleaving means place the first element from the first half and then first element from the 2nd half
// and again second element from the first half and then second element from the 2nd half and so on....

// Example 1:
// Input: q[] = [2, 4, 3, 1]
// Output: [2, 3, 4, 1]
// Explanation: We place the first element of the first half 2 and after that 
// place the first element of second half 3 and after that repeat
// the same process one more time so the resulting queue will be [2, 3, 4, 1]

// Example 2:
// Input: q[] = [3, 5]
// Output: [3, 5]
// Explanation: We place the first element of the first half 3 and first element
// of the second half 5 so the resulting queue is [3, 5]

// Example 3:
// Input: q[] = [10, 20, 30, 40, 50, 60]
// Output: [10, 40, 20, 50, 30, 60]

// Algorithm: It is a cakewalk kindergartener problem.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // T.C: O(n)
    // S.C: O(n)
    void rearrangeQueue(queue<int> &q) {
        int x = q.size() / 2;

        vector<int> firstPart;
        while(x--) {
            firstPart.push_back(q.front());
            q.pop();
        }

        x = q.size();   // as size of queue is already half now, directly assign 'x' to q.size()
        vector<int> secondPart;
        while(x--) {
            secondPart.push_back(q.front());
            q.pop();
        }

        for(int i = 0; i < firstPart.size(); i++) {
            q.push(firstPart[i]);
            q.push(secondPart[i]);
        }
    }
};

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    Solution().rearrangeQueue(q);

    queue<int> temp = q;
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    
    return 0;
}
