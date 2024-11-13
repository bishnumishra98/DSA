// Leetcode: 540. Single Element in a Sorted Array   --->   You are given a sorted array consisting of only integers
// where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10


// This question is exactly same as 'BaseBuildingPrograms\04. Searching\06_FindOddOccurringElement.cpp'

// Approach ---> Our single element will always be found at even index as numbers are in pairs.
// Case 1: if mid is at even index, we have 3 cases: we may be in left, ans, or right.
// Case 2: if mid is at odd index, we have 2 cases: Either we are in left or right

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    int ans = -1;   // the single element will be stored in it

     //  i/p: [1, 1, 2, 3, 3, 4, 4, 8, 8], o/p: 2
    // Index:  0  1  2  3  4  5  6  7  8

    while(start <= end) {
        // 'mid-1 >= 0' and 'mid+1 < n' conditions are written to avoid runtime error: array index out of bound

        if(mid & 1) {   // 'mid & 1' returns true for odd numbers, i.e. if 'mid'
                                        // is at odd index. We have 2 possible cases here.
            if((mid-1 >= 0) && (nums[mid] == nums[mid-1])) {
                // It means 'mid' is at left of 'ans'. In this case, we move to right.
                start = mid + 1;
            } else {
                // 'mid' is at right of 'ans'. In this case, we move to left.
                end = mid - 1;
            }
        } else {   // 'mid' is at even index. We have 3 possible cases here.
            if(((mid-1 >= 0)) && (nums[mid] == nums[mid-1])) {
                // 'mid' is at right of 'ans'. In this case, we move to left.
               // 'mid-1' is already checked, so there's no point of unnecessarily
              // bringing 'end' to 'mid-1'
                end = mid - 2;
            } else if((mid+1 < n) && (nums[mid] == nums[mid+1])) {
                // 'mid' is at left of 'ans'. In this case, we move to right.
               // 'mid+1' is already checked, so there's no point of unnecessarily
              // bringing 'start' to 'mid+1'
                start = mid + 2;
            } else {
                // 'mid' is on 'ans'
                ans = mid;
                break;   // break the loop as 'ans' is found
            }
        }

        mid = start + (end - start)/2;
    }

    return nums[ans];
}


int main() {
    vector <int> v = {3,3,7,7,10,11,11};

    cout << singleNonDuplicate(v);

    return 0;
}