// Leetcode: 1094. Car Pooling   --->   There is a car with capacity empty seats. The vehicle only drives east
// (i.e., it cannot turn around and drive west).
// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that
// the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi
// respectively. The locations are given as the number of kilometers due east from the car's initial location.
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

// Example 1:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

// Example 2:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true


// Algorithm: We will follow line sweep algorithm. The problem is almost exactly same as previous problem.
// The idea is to maintain a timeline of events (passengers getting in and out) and keep track of how many passengers are in
// the car at any given time. We can use an ordered map to store the changes in the number of passengers at each location.
// Line sweep requires events to be processed in sorted order of time, so we use an ordered map.
// When we try to book a new trip, we will update the timeline with the start and end events of the new trip. Specifically, we
// will increment the count at fromi by numPassengersi (indicating passengers get in) and decrement the count at toi by
// numPassengersi (indicating passengers get out). This way, we can keep track of how many passengers are in the car at any point
// in time by calculating the prefix sum of the timeline.
// After updating, we will check if at any point in the timeline we have more passengers than the capacity of the car. If we
// detect that the number of passengers exceeds the capacity, we will return false. If no such point is detected, we will return true.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Ordered map: {location -> change in number of passengers}
    map<int, int> timeline;   // timeline[x] = how many passengers get IN (+) or OUT (-) at location x

public:
    // T.C: O(n*logn) + O(n) ≈ O(nlogn)
    //      For each trip, we update the timeline with two events (passengers getting in and out). This takes O(logn) time
    //      due to map insertions. After updating the timeline for all trips, we need to check if at any point the number
    //      of passengers exceeds capacity by iterating through the timeline, which takes O(n) time in the worst case
    //      (if there are n events).
    // S.C: O(n)   for storing the timeline of events. In the worst case, if all trips are non-overlapping, we could have
    //             up to 2n entries in the timeline (each trip contributes a start and an end entry). Therefore, the space
    //             complexity is O(n).
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // STEP 1: Apply sweep-line updates for all trips
        for(auto &t: trips) {
            int passengers = t[0];
            int from = t[1];
            int to = t[2];

            timeline[from] += passengers;   // passengers get in
            timeline[to] -= passengers;   // passengers get out
        }

        // STEP 2: Check prefix sum to ensure capacity is never exceeded
        int currentPassengers = 0;

        for(auto &p: timeline) {   // map ensures sorted order of locations
            currentPassengers += p.second;

            if(currentPassengers > capacity) {
                return false;   // capacity exceeded
            }
        }

        return true;   // safe to pick all passengers
    }
};


int main() {
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;

    cout << Solution().carPooling(trips, capacity) << endl;   // o/p: false

    return 0;
}
