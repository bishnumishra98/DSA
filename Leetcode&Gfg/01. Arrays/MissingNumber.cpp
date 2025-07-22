// Leetcode: 268. Missing Number   --->   Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.

// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number
// in the range since it does not appear in nums.

// Example 2:
// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number
// in the range since it does not appear in nums.

// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number
// in the range since it does not appear in nums.

#include <bits/stdc++.h>
using namespace std;

// Mathematical approach
// S.C: O(n)
// T.C: O(1)
int missingNumber_technique1(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }

    int total_sum = (n * (n + 1)) / 2;

    return total_sum - sum;
}

// XOR approach
// T.C: O(n)
// S.C: O(1)
int missingNumber_technique2(vector<int>& nums) {
    int missingNumber = 0;

    // XOR all numbers from 0 to n
    for(int i = 0; i <= nums.size(); i++) {
        missingNumber ^= i;      
    }
    // missingNumber = 0 ^ 1 ^ 2 ^ 3

    // XOR all numbers in the array
    for(int i = 0; i < nums.size(); i++) {
        missingNumber ^= nums[i];
    }
    // missingNumber = 0 ^ 1 ^ 2 ^ 3 ^ 3 ^ 0 ^ 1 = 2

    return missingNumber;
}


int main() {
    vector <int> v = {3, 0, 1};

    cout << missingNumber_technique1(v) << endl;
    cout << missingNumber_technique2(v);

    return 0;
}
