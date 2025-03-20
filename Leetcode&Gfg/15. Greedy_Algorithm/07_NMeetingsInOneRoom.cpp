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

// Problem link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Algorithm: This is a greedy approach. We want to maximize the number of meetings that can be accommodated in a
// single meeting room. Thus we will try to accommodate the meetings with the earliest end time first. Keeping this
// point in mind, the algorithm is as follows:
// 1. Create a vector of {end, {start, id}} to store the end time, start time, and id of each meeting.
//    Sort the meetings in increasing order of end time, i.e., meetings with earlier end time will be considered first.
// 2. Initialize two variables 'maxMeetings' and 'prevEnd' to keep track of the maximum number of meetings that can be
//    accommodated in a single meeting room and the end time of the last meeting that was accommodated.
// 3. Iterate through all the meetings and check if the start time of the current meeting is greater than the end time of
//    the last meeting that was accommodated. If yes, then accommodate the current meeting and update the maximum number of
//    meetings and the end time of the last meeting that was accommodated.
// 4. Return the maximum number of meetings that can be accommodated in a single meeting room.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n*logn) + O(n) = O(n*logn);   where n = start.size()
    // S.C: O(n)
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        if (n == 0) return 0;   // handle empty input case

        vector<pair<int, int>> meetings(n);   // {end, start}
        for(int i = 0; i < n; i++) {
            meetings[i] = {end[i], start[i]};
        }
        
        // Sort the meetings in increasing order of end time, i.e., meetings with earlier end time will be considered first.
        sort(meetings.begin(), meetings.end());
        
        int maxMeetings = 0;
        int prevEnd = -1;
        
        for (int i = 0; i < n; i++) {
            if (meetings[i].second > prevEnd) {
                maxMeetings++;
                prevEnd = meetings[i].first;
            }
        }
        
        return maxMeetings;
    }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution obj;
    cout << obj.maxMeetings(start, end);

    return 0;
}
