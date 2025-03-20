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

// Algorithm: This is a greedy approach. We want to maximize the profit, so we would like to consider the jobs with
// higher profit first. Also, we want to complete as many jobs as possible, so that profits can be further maximized,
// Thus we will try to complete the jobs with the nearest deadline first, i.e., delay the jobs to be executed as late as
// possible so that other jobs with shorter deadlines could be completed in initial days. Keeping these two points in mind,
// the algorithm is as follows:
// 1. Create a vector of {profit, {deadline, id}} to store the profit, deadline, and id of each job.
//    Sort the jobs in decreasing order of profit, i.e., jobs with higher profit will be considered first.
// 2. Create a vector of size n to keep track of the jobs that are already scheduled on ith days. '-1' means no job
//    is scheduled on that day yet. Note that we are following 1-based indexing as the deadline is in days ranging from 1 to n.
// 3. Initialize two variables 'maxJobs' and 'maxProfit' to keep track of the maximum number of jobs and maximum profit. One
//    interesting fact to note here is that the maximum number of jobs that can be completed is always equal to the number
//    of jobs that are completed while maximizing the profit.
// 4. Iterate through all the jobs and assign them to the last possible day, i.e., the day of the deadline. If the last
//    possible day is already occupied, then assign the job to the nearest empty slot from the deadline. Also, update the
//    maximum number of jobs and maximum profit.
// 5. Return the maximum number of jobs and maximum profit.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n*logn) + O(n) = O(n*logn);   where n = id.size()
    // S.C: O(n)
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        vector<pair<int, pair<int, int>>> jobs(n);   // {profit, {deadline, id}}
        for(int i = 0; i < n; i++)
            jobs[i] = {profit[i], {deadline[i], id[i]}};
        
        // Sort the jobs in decreasing order of profit, i.e., jobs with higher profit will be considered first.
        sort(jobs.begin(), jobs.end(), greater<pair<int, pair<int, int>>>());
        
        vector<int> slot(n + 1, -1);   // to keep track of job ids that are already scheduled on ith days
        vector<int> result(2);
        int maxJobs = 0, maxProfit = 0;
        
        // Iterate through all the jobs and assign them to the last possible day, i.e., the day of the deadline.
        // If the last possible day is already occupied, then assign the job to nearest day from the deadline.
        for(int i = 0; i < n; i++) {
            for(int j = jobs[i].second.first; j >= 1; j--) {
                // If the 'j'th day slot is empty, then assign the job to that day.
                // Also, update the maximum number of jobs and maximum profit.
                if(slot[j] == -1) {
                    slot[j] = jobs[i].second.second;
                    maxJobs++;
                    maxProfit += jobs[i].first;
                    break;
                }
            }
        }

        result[0] = maxJobs;
        result[1] = maxProfit;
        return result;
        // Note: If sequence of jobs scheduled on each day is asked, then return the 'slot' vector.
    }
};

int main() {
    vector<int> id = {1, 2, 3, 4}, deadline = {4, 1, 1, 1}, profit = {20, 1, 40, 30};

    Solution obj;
    vector<int> ans = obj.JobSequencing(id, deadline, profit);
    cout << ans[0] << " " << ans[1];

    return 0;
}
