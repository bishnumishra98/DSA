// GFG: Job Sequencing Problem   --->   You are given three arrays: id, deadline, and profit, where each job is
// associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job
// can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.
// Your task is to find:
// 1. The maximum number of jobs that can be completed within their deadlines.
// 2. The total maximum profit earned by completing those jobs.

// Example 1:
// Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

// Example 2:
// Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

// Example 3:
// Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
// Output: [3, 100]
// Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        // code here
    }
};

int main() {
    vector<int> id = {1, 2, 3, 4}, deadline = {4, 1, 1, 1}, profit = {20, 1, 40, 30};

    Solution obj;
    vector<int> ans = obj.JobSequencing(id, deadline, profit);
    cout << ans[0] << " " << ans[1];

    return 0;
}
