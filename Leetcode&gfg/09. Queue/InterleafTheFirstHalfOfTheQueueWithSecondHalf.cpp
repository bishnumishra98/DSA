// gfg: Interleave the First Half of the Queue with Second Half   --->   You are given a queue Q
// of N integers of even length, rearrange the elements by interleaving the first half of the
// queue with the second half of the queue.

// Example 1:
// Input:
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
 
// Example 2:
// Input:
// Q = {3,5}
// Output:
// {3,5}

// Example 3:
// Input:
// Q = {10, 20, 30, 40, 50, 60}
// Output:
// {10, 40, 20, 50, 30, 60}

#include <iostream>
#include <queue>
using namespace std;

class Solution{
public:
    // T.C: O(n); where n is size of queue
    // S.C: O(n);
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();

        // Step 1: initialize a queue, and insert the first n/2 elements of queue in it.
        queue <int> part;

        int x = n/2;
        while(x--) {
            int temp = q.front();
            part.push(temp);
            q.pop();
        }

        // Step 2: Pop one element from 'part' and push it into 'q'. Then pop one element from 'q'
        //         and push that into 'q'. Doing this n/2 times makes an interleaf pattern in 'q'.
        x = n/2;
        while(x--) {
            // Pushing one element from 'part' into 'q'
            int temp = part.front();
            part.pop();
            q.push(temp);

            // Popping one element of 'q' and pushing into 'q'
            int temp_ = q.front();
            q.pop();
            q.push(temp_);
        }

        // Storing elements of queue into a vector and returning it
        vector <int> ans;
        int i = 0;
        while(n--) {
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
        }
        return ans;
    }
};

int main() {
    Solution obj;

    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    vector <int> ans = obj.rearrangeQueue(q);

    for(auto i: ans) {
        cout << i << " ";
    }
    
    return 0;
}
