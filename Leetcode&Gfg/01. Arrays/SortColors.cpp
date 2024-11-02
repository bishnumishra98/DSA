// leetcode: 75. Sort Colors (also known as Dutch National Flag problem)   --->   Given an array nums with n objects
// colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]
 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute force algorithm: Count the number of zeroes, ones and twos in the given input array, and then insert
    // those many zeroes, ones and twos in the array in sequence.
    // T.C: O(2n)
    // S.C: O(1)
    void sortColors_bruteForce(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0, oneCount = 0, twoCount = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) zeroCount++;
            else if(nums[i] == 1) oneCount++;
            else twoCount++;
        }

        int index = 0;
        while(zeroCount--) {
            nums[index] = 0;
            index++;
        }
        while(oneCount--) {
            nums[index] = 1;
            index++;
        }
        while(twoCount--) {
            nums[index] = 2;
            index++;
        }
    }

// -----------------------------------------------------------------------

    // Optimal approach algorithm(3 pointer approach):
    // There will be 3 rules based on which the algorithm is based:
    // [0 to low-1]    -> contains 0
    // [low to mid-1]  -> contains 1
    // [mid to high]   -> contains random numbers
    // [high+1 to n-1] -> contains 2
    // 1. Initialize low, mid and high with 0, 0 and n-1 respectively.
    // 2. Our aim is to keep 0, 1, 2 in their given above range. For example, lets take the following unsorted array:

    //           0       0      1      1      0       1       2       0       1       2       0       2       2
    //    Index: 0     low-1   low    mid-1  mid                                             high   high+1   n-1
    //    Observe element at nums[mid] and alter the pointers accordingly.
    //    -> If nums[mid] == 0, then it means 0 is at a wrong position. Its correct position should be inserted right after
    //       the 0 present at position low-1. Thus, swap(nums[mid], nums[low]). As after putting a 0 at next index after low,
    //       the above rules becomes invalid for 1 and 2, thus rectify the indices by shifting low and mid 1 step ahead.

    //           0       0      0      1      1       1       2       0       1       2       0       2       2
    //    Index: 0     low-1          low    mid-1   mid                                     high   high+1   n-1
    //    Observe element at nums[mid] and alter the pointers accordingly.
    //    -> If nums[mid] == 1, then it means 1 is at a wrong position. Its correct position should be from low to mid-1.
    //       Hence, move only mid pointer ahead by 1 step, so that indices for 1 become rectified.

    //           0       0      0      1      1       1       2       0       1       2       0       2       2
    //    Index: 0     low-1          low            mid-1   mid                             high   high+1   n-1
    //    Observe element at nums[mid] and alter the pointers accordingly.
    //    -> If nums[mid] == 1, then it means 1 is at a wrong position. Its correct position should be from low to mid-1.
    //       Hence, no need to any swapping, just move mid pointer ahead by 1 step, so that indices for 1 become rectified.

    //           0       0      0      1      1       1       2       0       1       2       0       2       2
    //    Index: 0     low-1          low            mid-1   mid                             high   high+1   n-1
    //    Observe element at nums[mid] and alter the pointers accordingly.
    //    -> If nums[mid] == 2, then it means 2 is at a wrong position. Its correct position should be from high+1 to n-1.
    //       Thus, swap(nums[mid], nums[high]), so that 2 comes at a position just left of high+1, in order to elongate chain of 2s.
    //       But the again, indices become incorrect for 2, so shift back high towards left in order to rectify indices.

    //           0       0      0      1      1       1       0       0       1       2       2       2       2
    //    Index: 0     low-1          low            mid-1   mid                     high   high+1           n-1
    //    Observe element at nums[mid] and alter the pointers accordingly.
    //    -> If nums[mid] == 2, then it means 2 is at a wrong position. Its correct position should be from high+1 to n-1.
    //       Thus, swap(nums[mid], nums[high]), so that 2 comes at a position just left of high+1, in order to elongate chain of 2s.
    //       But the again, indices become incorrect for 2, so shift back high towards left in order to rectify indices.

    //     Repeat the process until mid crosses high, and the array would automatically become sorted.

    // T.C: O(n)
    // S.C: O(1)
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        // 0 to low-1    -> 0
        // low to mid-1  -> 1
        // mid to high   -> random numbers
        // high+1 to n-1 -> 2
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {   // if(nums[mid] == 2)
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    // Solution().sortColors_bruteForce(nums);
    Solution().sortColors(nums);

    for(auto it: nums) cout << it << " ";

    return 0;
}
