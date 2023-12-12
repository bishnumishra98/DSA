// Leetcode: 153. Find Minimum in Rotated Sorted Array
// This problem is an implementation of binary search.

// This question is very simple:- Find the pivot element and return the element just after pivot.
// But return the first element if pivot element in at index 'nums.size()-1'.

#include <iostream>
#include <vector>
using namespace std;

// Refer: 'FindPivotIndexInRotatedSortedArray.cpp' in '4. Searching' in 'BaseBuildingPrograms'
int findPivotIndex(vector<int>& nums) {
    int n =  nums.size();
    int start = 0, end = n - 1, mid = start + (end - start)/2;

    while(start <= end) {
        if(start == end) {   // if only 1 element is present in array
            return start;
        }

        if((mid+1 < n) && (nums[mid] > nums[mid+1])) {   // on pivot element
            return mid;
        } else if((mid-1 >= 0) && (nums[mid] < nums[mid-1])) {   // on element just next to pivot
            return mid-1;
        } else if(nums[mid] < nums[start]) {   // on line B, i.e shorter ascending slope
            end = mid - 1;
        } else {   // on line A, i.e ascending taller slope
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    // Returning a default value if none of the conditions are met
    return -1;
}


// Leetcode given function
// T.C: O(logn)
// S.C: O(1)
int findMin(vector<int>& nums) {
    int pivotIndex = findPivotIndex(nums);   // T.C: O(logn), S.C: O(1)
    if(pivotIndex == nums.size()-1) {   // if array rotated is rotated as many times as no.of elements in array, then it becomes back a perfectly sorted array
        return nums[0];
    }
    return nums[pivotIndex+1];
}

int main() {
    vector <int> v = {11, 13, 15, 17};

    cout << "Minimum element is: " << findMin(v);

    return 0;
}