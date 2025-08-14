// Leetcode: 875. Koko Eating Bananas   --->   Koko loves to eat bananas. There are n piles of bananas, the ith pile
// has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas
// from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas
// during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

// Understand problem: More the rate of eating bananas, less will be the time taken to finish all piles of bananas.
//                     We have to find the minimum rate of eating bananas for which time taken to finish all piles
//                     of bananas is less than or equal to 'h'.  Note that time taken to finish a pile of banana is
//                     the ceiling value of time.
//                     Illustration: For the piles = [3, 6, 7, 11], h = 8.
//                     If koko has a rate of eating bananas as 3 bananas/h, then her time taken to finish all
//                     piles will be (3 / 3) + (6 / 3) + (7 / 3) + (11 / 3) = 1 + 2 + 3 + 4 = 10h, which is more
//                     than expected time h = 8.
//                     Thus, increase the rate of eating bananas to 4 bananas/h, then time taken to finish all
//                     piles will be (3 / 4) + (6 / 4) + (7 / 4) + (11 / 4) = 1 + 2 + 2 + 3 = 8h, which is under
//                     the expected time limit of h = 8. Thus, return 4.
// Algorithm: Extremely easy problem. One thing we know for sure is the least rate of eating bananas can be
//            1 banana/h, and the maximum rate of eating bananas can be x/h, where x = largest element of the
//            'piles' array; because no matter how bigger the rate is from the largest element of the piles,
//            the time taken to finish up all piles of bananas will always come out to be 'piles.size()'.
//            Thus, the search space lies from 1 to the x, and we have to return the minimum possible answer
//            in this range, i.e., minimum rate from 1 to x for which time <= h.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findTimeToEat(vector<int>& piles, int rate) {
        int time = 0;
        for(int i = 0; i < piles.size(); i++) {
            time += ceil((double)piles[i] / rate);   // or, time += (piles[i] + rate - 1) / rate;
        }
        return time;
    }

public:
    // T.C: O(x * n);   where x = largest element of piles, n = piles.size()
    // S.C: O(1)
    int minEatingSpeed_bruteforce(vector<int>& piles, int h) {
        int end = *max_element(piles.begin(), piles.end());

        for(int rate = 1; rate <= end; rate++) {
            int time = findTimeToEat(piles, rate);
            if(time <= h) return rate;
        }

        return end;   // this will never be reached, but just to avoid compilation error.
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(logx * n);   where x = largest element of piles, n = piles.size()
    // S.C: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int time = findTimeToEat(piles, mid);   // 'mid' is the rate here
            if(time <= h) {   // if time taken to finish all piles is less than or equal to h, store the answer and
                             // try to find a smaller rate
                ans = mid;
                end = mid - 1;
            } else start = mid + 1;   // if time taken to finish all piles is more than h, then increase the rate
        }

        return ans;
    }
};


int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << Solution().minEatingSpeed_bruteforce(piles, h) << endl;
    cout << Solution().minEatingSpeed(piles, h) << endl;

    return 0;
}
