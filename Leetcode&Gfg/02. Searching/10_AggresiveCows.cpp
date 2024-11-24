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
// 3. So start an iterator 'i' from 1 to stall[n-1] - stall[0], and check whether we distribute the given 'k' cows
//    among all stalls while maintaining a minimum distance of 'i', using a function 'canWePlace()'. If it's possible
//    to place 'k' cows while maintaining a minimum distance of 'i', then continue and check the same for next
//    value of 'i'. Else if its's not possible, return the previous value of 'i', as that is the maximum distance
//    we can maintain between two cows.

// --- BINARY SEARCH ---
// 1. The 'canWePlace()' function the remains the same; only the driver function changes. We already know that the
//    search space lies in the range of 1 to stall[n-1] - stall[0] where stalls are already sorted. Thus, we will
//    apply binary search on this search space.
//    Initialize 'start' and 'end' as usual with the lower and upper limit of the above mentioned search space.
// 2. Find 'mid' by computing 'start + (end - start) / 2' as usual. Here 'mid' denotes the minimum distance
//    that we have to maintain. Send the value of 'mid' to the 'canWePlace()' function and check if it's possible
//    to distribute 'k' cows among stalls while maintaining the minimum distance of 'mid'.
//    If it's possible to distribute the 'k' cows, store this potential answer in any variable say 'ans'
//    and continue the binary search to find some larger value of of 'mid' (start = mid + 1). If not possible,
//    then shorten the search space (end = mid - 1). Continue this process until 'start' crosses 'end'.
// 3. At the end of the loop while(start <= end), the 'ans' will contain the largest value of 'mid' for which
//    'k' cows can be distributed among stalls while maintaining a minimum distance of 'mid'. Thus, return 'ans'.

// 'canWePlace()' function algorithm:
// i.   Initialize two variables 'cows' and 'last' to keep track of no.of cows we can place while maintaining a minimum
//      distance of 'i' (minDistance), and the last index where the cows are allocated, respectively. So initially,
//      start with 1 cow and stall[0] as the last index as the first cow will always be placed on the first stall.
// ii.  Now start iterating over the 'stalls' array from index 1 till n - 1, and check if another cow can be placed at stall[1],
//      i.e., if(stall[i] - last >= minDistance). If it can be placed, increment the count of cows(cows++) and update the last
//      index where cow is kept, i,e., (last = stall[i]).
// iii. At the end of the above loop, if count of 'cows' is greater than or equal to 'k', it means we can distribute 'k' cows
//      among the stalls while maintaining a minimum distance of 'minDistance'. Thus, return true, else false.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canWePlaceCows(vector<int> &stalls, int minDistance, int k) {
        int cows = 1;
        int last = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - last >= minDistance) {
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
        if(k > stalls.size()) return -1;

        sort(stalls.begin(), stalls.end());
        int min = 1;
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
        if(k > stalls.size()) return -1;

        sort(stalls.begin(), stalls.end());
        int start = 1;
        int end = stalls[stalls.size() - 1] - stalls[0];
        int ans = 0;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(canWePlaceCows(stalls, mid, k)) {   // 'mid' is the minimum distance that we have to maintain
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
