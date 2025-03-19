// GFG: Shortest Job First   --->   Geek is a software engineer. He is assigned with the task of calculating average waiting
// time of all the processes by following shortest job first policy.
// The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the
// smallest execution time to execute next.
// Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting
// time of all the processes and return the nearest integer which is smaller or equal to the output.
// Note: Consider all process are available at time 0.

// Example 1:
// Input:
// n = 5
// bt = [4,3,7,1,2]
// Output: 4
// Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.

// Example 2:
// Input:
// n = 4
// arr = [1,2,3,4]
// Output: 2
// Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function solve() which takes bt[] as input
// parameter and returns the average waiting time of all the processes.

// Expected Time Complexity: O(nlog(n))
// Expected Auxiliary Space: O(1)

// Algorithm: It is a very simple and easy greedy approach.
// 1. Sort the burst time array.
// 2. Initialize two variables waitTime and time to 0.
// 3. Traverse the array.
//    i.  Add time to waitTime.
//    ii. Increment time by the burst time of the current process.
// 4. Return the average waiting time by dividing waitTime by the size of the array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn);   where n = bt.size()
    // S.C: O(1)
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long waitTime = 0, time = 0;

        for(int i = 0; i < bt.size(); i++) {
            waitTime += time;
            time += bt[i];
        }

        return waitTime / bt.size();
    }
};

int main() {
    int n = 5;
    vector<int> bt = {4, 3, 7, 1, 2};

    Solution obj;
    cout << obj.solve(bt);

    return 0;
}
