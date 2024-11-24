// GFG: You are given an array with unique elements of stalls[], which denote the position of a stall. You are also
// given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that
// the minimum distance between any two of them is the maximum possible.

// Example 1:
// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[2] and the third cow
//              can be placed at stalls[3]. The minimum distance between cows, in this case, is 3, which also is the
//              largest among all possible ways.

// Example 2:
// Input: stalls[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[1] and the third cow
//              can be placed at stalls[4]. The minimum distance between cows, in this case, is 4, which also is the
//              largest among all possible ways.

// Example 3:
// Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
// Output: 1
// Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
//              The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.

// Algorithm:
// --- LINEAR SEARCH ---
// 1. Sort the given 'stalls' array.
// 2. Place the first cow on the first stall, i.e., stall[0], because we have to maximize the minimum distance between
//    two cows, so the earlier we allocate a stall to first cow, the higher chances are we will be able to maximize the
//    distance between two cows.
//    Now one thing we know is, assuming 2 cows the minimum distance between them can be 1. Similarly, the maximum
//    distance between them can be if the 1st cow is standing on first stall(stall[0]) and the last cow is standing
//    on the last stall(stall[n-1]). Thus, the maximum distance between 2 cows can be stall[n-1] - stall[0]. So our
//    answer would lie somewhere between 1 to stall[n-1] - stall[0] for k cows.
// 3. So start an iterator 'i' from 1 till stall[n-1] - stall[0], and check whether we distribute the given k cows
//    among all stalls while maintaining a minimum distance of 'i'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canWePlaceCows(vector<int> &stalls, int distance, int k) {
        int cows = 1;
        int last = stalls[0];

        for(int i = 0; i < stalls.size(); i++) {
            if(stalls[i] - last >= distance) {
                cows++;
                last = stalls[i];
            }
        }

        return cows >= k ? true : false;
    }

public:
    // Linear search
    // T.C: O((max - min) * n);   where n = stalls.size()
    // S.C: O(1)
    int aggressiveCows_bruteforce(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int min = stalls[0];
        int max = stalls[stalls.size() - 1] - stalls[0];

        for(int i = 1; i <= max - min; i++) {
            if(canWePlaceCows(stalls, i, k)) continue;   // 'i' is the minimum distance that we have to maintain
            else return i - 1;
        }
    }

// ------------------------------------------------------------------

    // Binary search
    // T.C: O(log(end - start) * n);   where n = stalls.size()
    // S.C: O(1)
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int start = stalls[0];
        int end = stalls[stalls.size() - 1] - stalls[0];

        int ans;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(canWePlaceCows(stalls, mid, k)) {
                ans = mid;
                start = mid + 1;
            } else end = mid - 1;
        }

        return ans;
    }
};


int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << Solution().aggressiveCows_bruteforce(stalls, k) << endl;
    cout << Solution().aggressiveCows(stalls, k);
    
    return 0;
}
