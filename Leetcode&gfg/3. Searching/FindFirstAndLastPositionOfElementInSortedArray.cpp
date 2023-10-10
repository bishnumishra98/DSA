// Leetcode: 34. Find First and Last Position of Element in Sorted Array
// This problem is an implementation of binary search

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
    // Using a range-based for loop with auto
    for (const auto& element : v) {
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
// T.C: O(logn) + O(logn) = O(logn)
// S.C: O(1) + O(1) = O(1)
vector<int> searchRange(vector<int>& nums, int target) {
    int firstPosition = findFirstPosition(nums, target);
    int lastPosition = findLastPosition(nums, target);

    vector <int> v;

    v.push_back(firstPosition);
    v.push_back(lastPosition);

    return v;
}

int main() {
    vector <int> v = {5, 7, 7, 7, 8, 8, 10};
    int target = 7;

    vector <int> ans = searchRange(v, target);

    printVector(ans);

    // Additional info
    cout << "\nTotal no.of occurrences of target: " << (ans.back() - ans.front() + 1);


    return 0;
}

