// Leetcode: 26. Remove Duplicates from Sorted Array   --->   Given an integer array nums sorted in non-decreasing order,
// remove the duplicates in-place such that each unique element appears only once. The relative order of the elements
// should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// -> Change the array nums such that the first k elements of nums contain the unique elements in the order they were
//    present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// -> Return k.

// Example 1:
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Algorithm: The algorithm is simple. We will use two pointer approach.
// 1. Initialize j with 0, and i with 1 index respectively. The idea of this algorithm is all elements till j must be unique.
// 2. Compare nums[j] and nums[i] and if they are equal, a duplicate element is present at index i. Thus, increment i and
//    move it ahead. Else if nums[j] and nums[i] are not equal, it means a different or unique element is present at index i.
//    Thus, place that unique element just next after nums[j]. And then increment j as well, representing the boundary of
//    updated range of unique elements. Continue the process until all elements of nums are iterated, i.e., until i reaches
//    last index of nums.
// 3. As j points to the index of last unique element of nums; the no.of unique elements is j+1. Thus, return j+1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n);   where n = nums.size()
    // S.C: O(1)
    int removeDuplicates(vector<int>& nums) {
        int j = 0, i = 1;
        while(i < nums.size()) {
            if(nums[j] == nums[i]) i++;   // if duplicate element is found at nums[i], go ahead to check next element
            else {   // if(nums[j] != nums[i])
                // If an unique element is found, keep it on (j+1)th index, i.e., just next after nums[j]
                j++;
                nums[j] = nums[i];
                i++;
            }
        }

        return j + 1;
    }

    // T.C: O(n);   where n = nums.size()
    // S.C: O(1)
    int removeDuplicates_shorthand(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++) {
            // If an unique element is found, keep it on (j+1)th index, i.e., just next after nums[j].
            if(nums[j] != nums[i]) nums[++j] = nums[i];
        }

        return j + 1;
    }
};


int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // int k = Solution().removeDuplicates(nums);
    // cout << "k: " << k << endl;
    // for(auto it: nums) cout << it << " ";
    
    int k = Solution().removeDuplicates_shorthand(nums);
    cout << "k: " << k << endl;
    for(auto it: nums) cout << it << " ";

    return 0;
}
