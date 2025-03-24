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

// Example 3:
// Input: ratings = [0,2,4,7,6,5,4,3,2,1,1,1,2,3,4,2,1,1,1]
// Output: 50
// Explanation: The candy allocation will be: [1,2,,3,7,6,5,4,3,2,1,1,1,2,3,4,2,1,1,1]

// Brute force algorithm: Extremely simple and easy.
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

// --------------------------------------------------------------------------------------------------------------------------

    // Optimised algorithm: This is based on a slope approach. Imagine the ratings array as a graph, where the ratings are the
    // y-coordinates and the children are the x-coordinates. We can see that the ratings array can be divided into several
    // ascending or descending slopes. The children in the ascending slope must get 1 more candy than the previous child,
    // and the children in the descending slope must get 1 less candy than the previous child.
    // But the problem is while iterating the ratings array, we don't know how many children are there in the descending slope,
    // so we can't just easily assign 1 candy less to the children in the descending slope, otherwise if the descending slope
    // is longer than ascending slope, some children will get negative candies in the descending slope which is invalid.
    // So, we assign candies in the increasing order to the children in the ascending slope and as well as in the descending slope,
    // as we are not interested in the distribution of candies, we are just interested in the sum of candies.
    // Side by side, we will also keep a track of length of ascending slope and descending slope, and if the descending slope is
    // greater than the ascending slope, then we need to add the extra candies to the sum which is nothing but difference
    // between length of ascending slope and descending slope.
    // For better understanding, go through the image diagram in the same folder.

    // T.C: O(n)
    //S.C: O(1)
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;

        while(i < n) {
            // If its a straight line: We can assign 1 candy to all the children.
            while(i < n && ratings[i] == ratings[i - 1]) {
                sum++;
                i++;
            }

            // If its a ascending slope: We can assign candies in the increasing order to each children.
            int peak = 1;
            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;   // if ratings[i] > ratings[i - 1], it means the previous child would have got 1 candy, so the current child,
                         // i.e., ith child should get 1 more candy than the previous child. That's why peak++ first, them add it to sum.
                sum += peak;
                i++;
            }

            // If its a descending slope: We can assign candies in the decreasing order to each children.
            int down = 1;
            while(i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                down++;
                i++;
            }
            
            // If the descending slope is greater than the peak, then we need to add the extra candies to the sum.
            if(down > peak) sum += down - peak;
        }

        return sum;
    }
};

int main() {
    vector<int> ratings = {0, 2, 4, 7, 6, 5, 4, 3, 2, 1, 1, 1, 2, 3, 4, 2, 1, 1, 1};

    Solution sol;
    cout << sol.candy_bruteforce(ratings) << endl;
    cout << sol.candy(ratings);

    return 0;
}
