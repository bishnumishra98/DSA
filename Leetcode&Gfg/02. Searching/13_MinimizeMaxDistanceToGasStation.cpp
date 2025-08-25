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
//                       1. We will maintain an array 'howMany' of size n - 1, where howMany[i] will store the number of
//                          gas stations added between stations[i] and stations[i + 1]. Therefore, if there are 'n' gas
//                          stations, there will be 'n - 1' sections between them.
//                          Now let's say we have added 2 gas stations between station = 3 and station = 6, then the distance
//                          between two adjacent gas stations in that section will be (6 - 3) / (2 + 1) = 1, i.e.,
//                          hypothetically, the gas stations will be at positions 4 and 5; and the final sequence would
//                          look like: 3, 4, 5, 6. Note that we are not actually adding the gas stations, we are just
//                          keeping track of how many gas stations are added in each section between two adjacent stations
//                          using the array 'howMany'.
//                       2. We will run a loop from 1 to K (number of gas stations to be added). In each iteration, find the
//                          section between two adjacent stations which has the maximum length and add a gas station in that
//                          section hypothetically (i.e., increment the count of gas stations in that section in 'howMany').
//                       3. After adding all K gas stations, calculate the maximum distance between two adjacent gas stations
//                          using another loop and return it.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(K * n) + O(n);   where n = stations.size() and K = number of gas stations to be added
    // S.C: O(n - 1) = O(n)
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
            // Every new gas station has to be inserted in the longest section which is present between 'maxIndex' and
            // 'maxIndex + 1' of 'stations' array which is represented by 'maxIndex' of 'howMany' array. Thus, increment
            // the count of gas stations in the section 'maxIndex' and 'maxIndex + 1' by incrrementing howMany[maxIndex].
            howMany[maxIndex]++;
        }

        // Calculate the maximum distance between two adjacent gas stations after adding K gas stations
        double maxDistance = -1;
        for(int i = 0; i < n - 1; i++) {
            double diff = stations[i + 1] - stations[i];
            double sectionLength = diff / double(howMany[i] + 1);
            maxDistance = max(maxDistance, sectionLength);
        }

        return maxDistance;
    }

// ------------------------------------------------------------------------------------------------------------------

    // Optimized approach: We can optimize the above approach using a max-heap (priority queue).
    //                    1. We will maintain a max-heap (priority queue) to store the lengths of all sections between two
    //                       adjacent stations, with their indexes. The section with the maximum length will be at the top
    //                       of the max-heap. Pushing an element in a max-heap takes O(logn) time.
    //                    2. We will run a loop from 1 to K (number of gas stations to be added). In each iteration, we will
    //                       extract the top element of the max-heap (which has the maximum length) and add a gas station
    //                       in that section hypothetically (i.e., increment the count of gas stations in that section in
    //                       'howMany'). Then, we will calculate the new length of that section after adding the gas station
    //                       and push it back to the max-heap.
    //                    3. After adding all K gas stations, the top element of the max-heap will have the maximum length
    //                       of a section between two adjacent gas stations. We will return that length.

    // T.C: O(n * logn) + O(K * logn);   where n = stations.size() and K = number of gas stations to be added
    // S.C: O(n - 1) + O(n - 1) = O(n)
    double findSmallestMaxDist_optimized_bruteforce(vector<int> &stations, int K) {
        int n = stations.size();
        if(n <= 1) return 0;
        vector<int> howMany(n - 1, 0);
        // Max-heap to store the section with maximum length at the top
        priority_queue<pair<double, int>> pq;   // {section_length, section_index}

        // Push the lengths of all sections between two adjacent stations, with their indexes in the max-heap
        for(int i = 0; i < n - 1; i++) pq.push({stations[i + 1] - stations[i], i});

        // Greedily add gas stations in the section which has the maximum length
        for(int gasStation = 1; gasStation <= K; gasStation++) {
           auto top = pq.top();
           pq.pop();
           int secInd = top.second;   // index of the section which has the maximum length

           howMany[secInd]++;   // increment the count of gas stations in that section
           double iniDiff = stations[secInd + 1] - stations[secInd];   // initial distance between two adjacent stations
           double newSecLen = iniDiff / double(howMany[secInd] + 1);   // new length of each section after adding
                                                                      // 'howMany[secInd]' gas stations in between
                                                                     // 'secInd' and 'secInd + 1' of 'stations' array
                                                                    // which is represented by 'secInd' of 'howMany' array
           pq.push({newSecLen, secInd});   // push the new section length with its index in the max-heap
        }

        // The top element of the max-heap will have the maximum length of a section between two adjacent gas stations
        return pq.top().first;
    }

// ------------------------------------------------------------------------------------------------------------------

    double numberOfGasStationsRequired(double dist, vector<int> &stations) {
        int cnt = 0;
        for(int i = 1; i < stations.size(); i++) {
            int numberInBetween = (stations[i] - stations[i - 1]) / dist;
            if((stations[i] - stations[i - 1]) / dist == numberInBetween * dist) numberInBetween--;
            cnt += numberInBetween;
        }
        return cnt;
    }

    // T.C: O(n * logm);   where n = stations.size() and m = maximum distance between two adjacent gas stations
    // S.C: O(1)
    double findSmallestMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        double start = 0;
        double end = 0;
        for(int i = 0; i < n - 1; i++) end = max(end, double(stations[i + 1] - stations[i]));

        double diff = 1e-6;   // 10^-6
        while(end - start > diff) {
            double mid = start + (end - start) / 2;
            int cnt = numberOfGasStationsRequired(mid, stations);
            if(cnt > K) start = mid;
            else end = mid;
        }

        return end;
    }
};


int main() {
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int K = 9;

    Solution obj;
    cout << obj.findSmallestMaxDist_bruteforce(stations, K) << endl;
    cout << obj.findSmallestMaxDist_optimized_bruteforce(stations, K) << endl;
    cout << obj.findSmallestMaxDist(stations, K);
    
    return 0;
}
