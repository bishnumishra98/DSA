// Leetcode: 134. Gas Station   --->   There are n gas stations along a circular route,
// where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the
// ith station to its next (i + 1)th station. You begin the journey with an empty tank at
// one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can
// travel around the circuit once in the clockwise direction, otherwise return -1. If there
// exists a solution, it is guaranteed to be unique.

// Example 1:
// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.

// Example 2:
// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
// Therefore, you can't travel around the circuit once no matter where you start.


// Algorithm:
// 1. Initialize 3 variables: start = 0, totalFuelBalance = 0 and currentFuelBalance = 0.
//    -> start: The starting index of the gas station. Every time we start from a new
//              gas station, currentFuelBalance will reset back to 0.
//    -> totalFuelBalance(tFb): Tracks the overall fuel balance throughout the entire trip.
//       In simple terms, tFB = sum of all gas elements - sum of all cost elements. But we
//       will be calculating cumulative tFB throughout each iteration, so our formula will be
//       tFB = tFB + gas[i] - cost[i]. If tFB >= 0 at the end of the loop, then only the trip
//       is possible for the given pair of gas[] and cost[] arrays. Thus, tFB only tells
//       whether trip is possible for the given input array sets or not. To find the index from
//       where trip should start to get completed, we have to take help of 'cFB' and 'start'.
//    -> currentFuelBalance(cFB): Tracks the fuel balance at the current station. The trip
//       can only start if cFB is found positive for any station. If cFB < 0, for ith station,
//       then we have to start from the next station, i.e., 'start' will point to
//       (i+1)th station and 'cFB' shall be reset back to 0 for that station.

//       EXTRA NOTE :-
//       Q) Why not we check 'start' of trip from each gas station, i.e., start = 0, 1, 2, ...
//          Why 'start' directly jumps to 'i+1' if cFB is negative for ith station ?
//       A) We have to agree that if we reach from an index(lets say i=0) to an
//          index(lets say i=3), it means fuel was enough to reach from station i=0 to i=3,
//          it means cFB for i=0,1,2 was definitely >= 0.
//          Now lets say, we are still not able to reach station 4, it means total gas we have
//          accumulated uptil station 3 is not enough for us to reach station 4. It can only
//          happen if gas[3] - cost[3] is such a huge negative, that it made cFB for i=3 less
//          less than 0.
//          Thus the thing to observe here is, if sum of 3 +ve and 1 -ve number is not >= 0,
//          how will the sum of 2 +ve and 1 -ve number be ever >= 0 ? Thus, without wasting
//          time by checking from each station, we directly jump to i+1th station, reset back
//          cFB to 0, and check if cFB is >=0 for this new station or not.

// 2) At the end of loop that runs from i=0 to i=gas.size(), if tFB >= 0, return the index of
//    gas station marked by 'start'; or else if trip was not possible, return -1.
//    In this way, we go to a station only once and successfully find out the station from
//    which the trip could be completed.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;   // potential start index
        int totalFuelBalance = 0;   // total fuel balance across all stations
        int currentFuelBalance = 0;   // current fuel balance for the ongoing trip

        for(int i = 0; i < gas.size(); i++) {
            totalFuelBalance += gas[i] - cost[i];   // total fuel balance at station i

            // If running out of fuel at the current station, reset the start index to
            // the next station, and currentFuelBalance to 0.
            currentFuelBalance += gas[i] - cost[i];
            if(currentFuelBalance < 0) {
                start = i + 1;   // consider moving to the next station to find next potential start index 
                currentFuelBalance = 0;
            }
        }

        // If the total fuel balance is negative, it means the trip is not possible.
        // Otherwise, return the start index
        return (totalFuelBalance < 0) ? -1 : start;
    }
};


int main() {
    Solution obj;
    vector <int> gas{1, 2, 3, 4, 5};
    vector <int> cost{3, 4, 5, 1, 2};

    cout << obj.canCompleteCircuit(gas, cost);

    return 0;
}
