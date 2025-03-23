// Leetcode 135. Candy   --->   There are n children standing in a line. Each child is assigned a rating value given
// in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// • Each child must have at least one candy.
// • Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:
// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

// Brute force algorithm: Extremely simple and easy to understand.
// 1. Create two arrays left and right of size n.
// 2. left[i] stores the number of candies given to the ith child considering only the left neighbour.
// 3. right[i] stores the number of candies given to the ith child considering only the right neighbour.
// 4. Finally, the maximum of left[i] and right[i] is the number of candies given that can be given to the ith child to
//    satisfy the neighbours from both sides.
// 5. Finally calculate the sum of all the max element of left[i] and right[i], and return the sum.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(3n)
    // S.C: O(2n)
    int candy_bruteforce(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        vector<int> right(n);

        // Considering only left neighbours initially, left[0] has no neighbour towards its left, so it will get 1 candy.
        // Considering only right neighbours initially, right[n - 1] has no neighbour towards its right, so it will get 1 candy.
        left[0] = 1;   
        right[n - 1] = 1;

        // Filling the left array, considering only left neighbours.
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
            else left[i] = 1;
        }

        // Filling the right array, considering only right neighbours.
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
            else right[i] = 1;
        }

        int sum = 0;
        for(int i = 0; i < n; i++) sum += max(left[i], right[i]);

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << sol.candy_bruteforce(ratings);
    return 0;
}
