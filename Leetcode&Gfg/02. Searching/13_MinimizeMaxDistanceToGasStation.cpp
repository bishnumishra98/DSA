// GFG: Minimize Max Distance to Gas Station   --->   We have a horizontal number line. On that number line, we have
// gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d,
// the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d.
// Find the answer exactly to 2 decimal places.
// Note: stations is in a strictly increasing order.

// Example 1:
// Input: stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 9
// Output: 0.50
// Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.

// Example 2:
// Input: stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95], k = 2 
// Output: 14.00 
// Explanation: Construction of gas station at 8th(between 72 and 89) and 6th(between 44 and 67) locations.

// Constraint:
// 10 ≤ stations.size() ≤ 10^5
// 0 ≤ stations[i] ≤ 10^6
// 0 ≤ k ≤ 10^5

// Problem link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

// Brute force approach: The algorithm is not as diificult as you think. We will follow a greedy approach.
// 1. We will maintain an array 'howMany' of size n - 1, where howMany[i] will store the number of gas stations added
//    between stations[i] and stations[i + 1]. Therefore, if there are 'n' gas stations, there will be 'n - 1' sections
//    between them. Now let's say we have added 2 gas stations between station = 3 and station = 6, then the distance
//    between two adjacent gas stations in that section will be (6 - 3) / (2 + 1) = 1, i.e., hypothetically, the gas stations
//    will be at positions 4 and 5; and the final sequence would look like: 3, 4, 5, 6. Note that we are not actually adding
//    the gas stations, we are just keeping track of how many gas stations are added in each section
//    between two adjacent stations using the array 'howMany'.
// 2. We will run a loop from 1 to K (number of gas stations to be added). In each iteration, find the section between
//    two adjacent stations which has the maximum length and add a gas station in that section hypothetically (i.e., increment
//    the count of gas stations in that section in the array 'howMany').
// 3. After adding all k gas stations, calculate the maximum distance between two adjacent gas stations and return it.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(k * n) + O(n);   where n = stations.size() and k = number of gas stations to be added
    // S.C: O(n)
    double findSmallestMaxDist_bruteforce(vector<int> &stations, int K) {
        int n = stations.size();
        if(n <= 1) return 0;   // if there is only one or no gas station, return 0
        vector<int> howMany(n - 1, 0);   // tracks how many gas stations are added in each section between two
                                        // adjacent stations. howMany[i] represents the number of gas stations
                                       // added between stations[i] and stations[i + 1]

        // Greedily add gas stations in the section which has the maximum length
        for(int gasStation = 1; gasStation <= K; gasStation++) {
            double maxSection = -1;   // maximum length of a section between two adjacent stations
            int maxIndex = -1;   // index of the section from the array 'howMany' which has the maximum length
            for(int i = 0; i < n - 1; i++) {
                double diff = stations[i + 1] - stations[i];   // distance between two adjacent stations
                double sectionLength = diff / double(howMany[i] + 1);   // length of each section after adding 'howMany[i]'
                                                                       // gas stations in between 'i' and 'i + 1' stations
                // If current section is the longest one till now, update maxSection and maxIndex
                if(sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxIndex = i;
                }
            }
            // Every new gas station has to be inserted in the longest section which is present between 'maxIndex'
            // and 'maxIndex + 1'. Thus, increment the count of gas stations in that section in the array 'howMany'.
            howMany[maxIndex]++;
        }

        // Calculate the maximum distance between two adjacent gas stations after adding k gas stations
        double maxDistance = -1;
        for(int i = 0; i < n - 1; i++) {
            double diff = stations[i + 1] - stations[i];
            double sectionLength = diff / double(howMany[i] + 1);
            maxDistance = max(maxDistance, sectionLength);
        }

        return maxDistance;
    }
};


int main() {
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int K = 9;

    Solution obj;
    cout << obj.findSmallestMaxDist_bruteforce(stations, K) << endl;
    
    return 0;
}
