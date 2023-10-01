// Leetcode: 2391. Minimum Amount Of Time to Collect Garbage   --->   You are given a 0-indexed array
// of strings garbage where garbage[i] represents the assortment of garbage at the ith house.
// garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal,
// paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.
// You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed
// to go from house i to house i + 1. There are three garbage trucks in the city, each responsible for
// picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in
// order. Only one garbage truck may be used at any given moment. While one truck is driving or picking
// up garbage, the other two trucks cannot do anything. Return the minimum number of minutes needed to
// pick up all the garbage.

// Example 1:
// Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
// Output: 21

// Example 2:
// Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
// Output: 37


#include <iostream>
#include <vector>
using namespace std;

// T.C: o(n);   where n is garbage.size()
// S.C: O(1)
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int pickM = 0;
    int pickP = 0;
    int pickG = 0;

    int travelM = 0;
    int travelP = 0;
    int travelG = 0;

    int lastTravelIndexM = 0;
    int lastTravelIndexP = 0;
    int lastTravelIndexG = 0;

    // calculating pick time and last travel index
    for(int i=0; i<garbage.size(); i++) {
        // accessing each string of 'garbage' via 'curr'
        string curr = garbage[i];

        // accessing each character of the string 'curr' via 'ch'
        for(int j=0; j<curr.length(); j++) {
            char ch = curr[j];

            if(ch == 'M') {
                pickM++;   // if character 'M' found at ith string, then increment pick time of M by 1
                lastTravelIndexM = i;   // if character 'M' found at ith string, then update lastTravelIndexM to i
            } else if(ch == 'P') {
                pickP++;   // if character 'P' found at ith string, then increment pick time of P by 1
                lastTravelIndexP = i;   // if character 'P' found at ith string, then update lastTravelIndexP to i
            } else {
                pickG++;   // if character 'G' found at ith string, then increment pick time of G by 1
                lastTravelIndexG = i;   // if character 'G' found at ith string, then update lastTravelIndexG to i
            }
        }
    }

    // calculating travel time
    for(int i=0; i<lastTravelIndexM; i++) {
        travelM += travel[i];
    }

    for(int i=0; i<lastTravelIndexP; i++) {
        travelP += travel[i];
    }

    for(int i=0; i<lastTravelIndexG; i++) {
        travelG += travel[i];
    }

    int ans = (pickM + travelM) + (pickP + travelP) + (pickG + travelG);

    return ans;
}


int main() {
    vector <string> garbage = {"G","P","GP","GG"};
    vector <int> travel = {2,4,3};

    cout << garbageCollection(garbage, travel);

    return 0;
}