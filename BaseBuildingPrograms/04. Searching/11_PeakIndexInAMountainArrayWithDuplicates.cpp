// This is an extension of the problem 'Leetcode&Gfg\02. Searching\04_PeakIndexInAMountainArray.cpp'.

#include <iostream>
#include <vector>
using namespace std;

// Recursive binary search to find peak index
int binarySearchPeak(vector<int>& nums, int start, int end) {
    if (start == end) return start;

    int mid = start + (end - start) / 2;

    if(nums[mid] > nums[mid + 1]) {
        // We're in the descending part; peak is on left or at mid
        return binarySearchPeak(nums, start, mid);
    } else if(nums[mid] < nums[mid + 1]) {
        // We're in the ascending part; peak is on right
        return binarySearchPeak(nums, mid + 1, end);
    } else {
        // if(nums[mid] == nums[mid + 1]), handle duplicates safely
        // Search both halves and return index of higher value
        int leftPeak = binarySearchPeak(nums, start, mid);
        int rightPeak = binarySearchPeak(nums, mid + 1, end);

        // Return the index with the greater value
        return (nums[leftPeak] >= nums[rightPeak]) ? leftPeak : rightPeak;
    }
}

// T.C: O(log n) on average, O(n) in worst case due to duplicates
// S.C: O(log n) due to recursion stack
int peakElement(vector<int>& nums) {
    return binarySearchPeak(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 3, 3, 3, 3, 7, 2, 1};

    cout << "Peak index: " << peakElement(nums) << endl;
    cout << "Peak value: " << nums[peakElement(nums)] << endl;

    return 0;
}
