// Leetcode: 42. Trapping Rain Water   --->   Given n non-negative integers representing an elevation map where the
// width of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
// 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(3n) ~ O(n)
    // S.C: O(2n) ~ O(n)
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n);   // prefixMax[i] = maximum height of building from 0th to ith index
        vector<int> suffixMax(n);   // suffixMax[i] = maximum height of building from ith to (n - 1)th index

        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        suffixMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int totalWater = 0;
        for(int i = 0; i < n; i++) {
            int leftMax = prefixMax[i];   // leftMax is the height of tallest building towards left of ith building
            int rightMax = suffixMax[i];   // rightMax is the height of tallest building towards right of ith building
            
            int water = min(leftMax, rightMax) - height[i];   // water is the units of water that can be stored on top of ith building
            totalWater += water;
        }

        return totalWater;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << Solution().trap(height);

    return 0;
}
