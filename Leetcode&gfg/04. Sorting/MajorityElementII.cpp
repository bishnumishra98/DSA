// Leetcode: 229. Majority Element II   --->   Given an integer array of size n, find all elements
// that appear more than [n/3] times.
// Example 1:
// Input: nums = [3,2,3]
// Output: [3]

// Example 2:
// Input: nums = [1]
// Output: [1]

// Example 3:
// Input: nums = [1,2]
// Output: [1,2]

// First understand this question present in in Leetcode&gfg\Searching:
// Leetcode: 34. Find First and Last Position of Element in Sorted Array

// (This question is very easy, and it was solved by me in 1st attempt)

// Approach:-
// 1) First sort the given vector.
// 2) Find the first and last occurrence of each unique element in the vector.
// 3) Total occurrence of that element = index of last occurrence - index of first occurrence + 1
// 4) Find total occurrence of each unique element and if total occurrence of any particular element
// is greater than n/3, then push it in a vector 'ans'. In the end, return 'ans'.


#include <iostream>
#include <vector>
#include <algorithm>   // for sort()
using namespace std;

void printVector(vector <int>& v) {
    for(auto element: v) {
        cout << element << " ";
    }
}

// T.C: O(logn)
// S.C: O(1)
int findFirstPosition(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {
        if(target == nums[mid]) {
            ans = mid;
            end = mid - 1;
        } else if(target > nums[mid]) {
            start = mid + 1;
        } else {   // if(target < nums[mid])
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

// T.C: O(logn)
// S.C: O(1)
int findLastPosition(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {
        if(target == nums[mid]) {
            ans = mid;
            start = mid + 1;
        } else if(target > nums[mid]) {
            start = mid + 1;
        } else {   // if(target < nums[mid])
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

// leetcode given function
// T.C: O(nlogn);   as most dominant time taking function is sort() 
// S.C: O(1)
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector <int> ans;

    sort(nums.begin(), nums.end());

    int i = 0;
    while(i<n) {
        int firstOcc = findFirstPosition(nums, nums[i]);
        int lastOcc = findLastPosition(nums, nums[i]);

        if((lastOcc - firstOcc + 1) > n/3) {
            ans.push_back(nums[i]);
        }

        i = lastOcc + 1;   // because in a sorted vector, next unique element will come after
                          // last occurrence of previous element.
    }

    return ans;
}


int main() {
    vector <int> nums = {3,2,3};

    vector <int> v;

    v = majorityElement(nums);

    printVector(v);

    return 0;
}