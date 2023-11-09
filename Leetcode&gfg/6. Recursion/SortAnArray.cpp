// leetcode: 912. Sort an Array   --->   Given an array of integers nums, sort the array in ascending
// order and return it within O(nlogn) complexity.

// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

// In this question, we will apply mergeSort to sort array.

#include <iostream>
#include <vector>
using namespace std;



void mergeSort(vector<int>& nums, int start, int end) {
}

vector<int> sortArray(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    mergeSort(nums, start, end);
}

int main() {
    vector <int> nums = {5,2,3,1};
    sortArray(nums);

    for(int element: nums) {
        cout << element << " ";
    }

    return 0;
}