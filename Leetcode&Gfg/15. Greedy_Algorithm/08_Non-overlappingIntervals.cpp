// Leetcode: 435. Non-overlapping Intervals   --->   Given an array of intervals intervals where intervals[i] = [starti, endi],
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// Example 2:
// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

// Example 3:
// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Algorithm: It is exactly the same as the previous problem 'Leetcode&Gfg\15. Greedy_Algorithm\07_NMeetingsInOneRoom.cpp'.
// The only difference is that we need to find the minimum number of intervals to remove to make the rest of the intervals
// non-overlapping. So, the total number of intervals less the maximum number of intervals that can be accommodated in a
// single meeting room will be the answer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n*logn) + O(n) = O(n*logn);   where n = intervals.size()
    // S.C: O(n)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 0;

        vector<pair<int, int>> slots(n);
        for(int i = 0; i < n; i++) {
            slots[i] = {intervals[i][1], intervals[i][0]};   // {end, start}
        }

        sort(slots.begin(), slots.end());

        int prevEnd = INT_MIN, maxSlots = 0;   // 'prevEnd = INT_MIN' because start and end can range from -5 * 10^4 to 5 * 10^4.
                                              // So, INT_MIN is a safe value to initialize prevEnd.
        for(int i = 0; i < n; i++) {
            if(slots[i].second >= prevEnd) {   // '>=' because in this problem, if an interval ends at ith second,
                                              // the next interval can start at ith second itself.
                maxSlots++;
                prevEnd = slots[i].first;
            }
        }

        return n - maxSlots;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals);

    return 0;
}
