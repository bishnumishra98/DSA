// GFG: Minimum Platforms   --->   You are given the arrival times arr[] and departure times dep[] of all trains that
// arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at
// the station to ensure that no train is kept waiting.
// At any given time, the same platform cannot be used for both the arrival of one train and the departure of another.
// Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms
// are required to accommodate both trains.

// Example 1
// Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3
// Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.

// Example 2:
// Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
// Output: 1
// Explanation: All train times are mutually exclusive. So we need only one platform

// Example 3:
// Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
// Output: 3
// Explanation: All 3 trains have to be there from 11:00 to 11:30

// Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23)
// and the last two characters represent minutes (this will be <= 59 and >= 0).

// Problem link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Intuition: It is a very simple problem. The idea is to keep track of the number of maximum number of platforms
//            needed at any time.
// Input:   arr[] = [900, 940, 950, 1100, 1500, 1800],   dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// If we monitor what happens at each time, we get the following:
// (900, A), (910, D), (940, A), (950, A), (1100, A), (1120, D), (1130, D), (1200, D), (1500, A), (1800, A), (1900, D), (2000, D)
// At time 900, a train arrives and we need a platform. So, platform = 1.
// At time 910, a train departs and we don't need a platform. So, platform = 0.
// At time 940, a train arrives and we need a platform. So, platform = 1.
// At time 950, a train arrives and we need a platform. So, platform = 2.
// At time 1100, a train arrives and we need a platform. So, platform = 3.
// At time 1120, a train departs and we don't need a platform. So, platform = 2.
// At time 1130, a train departs and we don't need a platform. So, platform = 1.
// At time 1200, a train departs and we don't need a platform. So, platform = 0.
// At time 1500, a train arrives and we need a platform. So, platform = 1.
// At time 1800, a train arrives and we need a platform. So, platform = 2.
// At time 1900, a train departs and we don't need a platform. So, platform = 1.
// At time 2000, a train departs and we don't need a platform. So, platform = 0.
// So, the maximum number of platforms needed at any time is 3.
// The arrival array is already sorted, so if we sort the departure array, we can easily monitor the number of platforms
// needed at any time. Just initialize two pointers i and j to 0. i will point to the arrival time and j will point to the
// departure time. If the time pointed by i is less than or equal to time pointed by j, it means a train has arrived before
// another train has departed. So, we need a platform. Hence, increment the platform and move the i pointer ahead.
// Else if the time pointed by i is greater than the time pointed by j, it means a train has arrived after another train
// has departed. So, we don't need a platform. We can use the same platform from where the previous train has departed.
// Hence, decrement the platform and move the j pointer ahead. In this way, we can monitor the number of platforms needed
// at any time and find out the maximum number of platforms needed at any time.

// Algorithm:
// 1. Sort the arrival and departure times of the trains. In this problem, arrival time array is already sorted, so
//    no need to sort it again. In order to not manipulate the given departure array, we will create a copy of it
//    and sort it.
// 2. Initialize two pointers i and j to 0. i will point to the arrival time and j will point to the departure time.
// 3. Initialize a variable platform to 0 and maxPlatform to 0.
// 4. While i < n and j < n, do the following:
//    i.  Case I:  If the time pointed by i is less than or equal to time pointed by j, then increment the platform and
//                 move the i pointer ahead. Platform is incremented because a train has arrived and it needs a platform.
//        Case II: Else if the time pointed by i is greater than the time pointed by j, then decrement the platform and
//                 move the j pointer ahead. Platform is decremented because a train has departed and it has freed a platform.
//    ii. Update the maxPlatform with the maximum of maxPlatform and platform.
// 5. Return the maxPlatform.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn) + O(2n) = O(nlogn)
    // S.C: O(n)
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<int> sortedDep = dep;
        sort(sortedDep.begin(), sortedDep.end());

        int i = 0, j = 0, platform = 0, maxPlatform = 0;
        while (i < n && j < n) {
            if (arr[i] <= sortedDep[j]) {
                platform++;
                i++;
            } else {
                platform--;
                j++;
            }
            maxPlatform = max(maxPlatform, platform);
        }

        return maxPlatform;
    }
};

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    Solution obj;
    cout << obj.findPlatform(arr, dep);

    return 0;
}
