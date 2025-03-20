// GFG: N Meetings In One Room   --->   You are given timings of n meetings in the form of (start[i], end[i]) where start[i]
// is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can
// be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Example 1:
// Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

// Example 2:
// Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
// Output: 1
// Explanation: Only one meetings can be held with given start and end timings.

// Example 3:
// Input: start[] = [1, 2], end[] = [100, 99]
// Output: 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
    }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution obj;
    cout << obj.maxMeetings(start, end);

    return 0;
}
