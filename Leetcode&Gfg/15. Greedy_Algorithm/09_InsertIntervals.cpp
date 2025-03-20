// Leetcode: 57. Insert Interval   --->   You are given an array of non-overlapping intervals intervals where
// intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in
// ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start
// and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals
// still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// Problem link: https://leetcode.com/problems/insert-interval/description/

// Algorithm: The algortihm is very simple. We will divide the given intervals into 3 parts: left, middle(overlapping) and right.
// 1. Create a vector of vector to store the final result.
// 2. Create an iterator i to traverse the intervals array, initially set to 0.
// 3. Traverse the intervals array and add all the intervals which are less than newInterval[0] to the result.
// 4. Traverse the intervals array and merge all the overlapping intervals with newInterval.
// 5. Traverse the intervals array and add all the intervals which are greater than newInterval[1] to the result.
// 6. Return the result.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;   // to store the final result
        int n = intervals.size();
        int i = 0;

        // Left part: Here no overlapping interval is there. So, we will add all the intervals which are less than newInterval[0].
        while(i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Middle part: Here overlapping interval is there. So, we will merge all the overlapping intervals.
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Right part: Here no overlapping interval is there. So, we will add all the intervals which are greater than newInterval[1].
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};

    Solution sol;
    vector<vector<int>> res = sol.insert(intervals, newInterval);
    for(auto x: res) {
        cout << "(" << x[0] << ", " << x[1] << ")" << endl;
    }

    return 0;
}
