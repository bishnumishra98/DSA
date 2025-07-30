// Leetcode: 11. Container With Most Water   --->   You are given an integer array height of length n. There are n vertical
// lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of
// water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1

// Problem link: https://leetcode.com/problems/container-with-most-water/

// Algorithm: Extremely simple. We can apply a 2 pointer greedy approach here.
// 1. Start with two pointers, one at the beginning and one at the end of the array.
// 2. Calculate the volume formed by the lines at these two pointers and the x-axis. Keep a track of maximum volume found so far.
//    The volume is calculated as (j - i) * min(height[i], height[j]) where i and j are the indices of the two pointers.
//    Here, (j - i) is the width of the container and min(height[i], height[j]) is the height of the container which can hold water.
// 3. Move the pointer pointing to the shorter line inward, as moving the shorter line inward may result in occurrence of a
//    taller line, but moving the taller line inward will for sure not increase the volume as the shorter line is the limiting factor.
// 4. Repeat steps 2 and 3 until the two pointers meet.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int maxVol = 0;
        while(i < j) {
            int volume = (j - i) * min(height[i], height[j]);
            maxVol = max(maxVol, volume);

            if(height[i] < height[j]) i++;
            else j--;   // if(height[i] >= height[j])
        }

        return maxVol;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << Solution().maxArea(height);

    return 0;
}
