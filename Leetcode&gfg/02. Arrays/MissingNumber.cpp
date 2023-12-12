// Leetcode: 268. Missing Number

#include <iostream>
#include <vector>
using namespace std;

// Brute force
// S.C: O(n)
// T.C: O(1)
int missingNumber_bruteForce(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum+= nums[i];
    }

    int total_sum = (n*(n+1))/2;

    return total_sum - sum;     
}

// XOR approach
// T.C: O(n)
// S.C: O(1)
int missingNumber(vector<int>& nums) {
    int missingNumber = 0;

    // XOR all numbers from 0 to n
    for (int i=0; i <= nums.size(); i++) {
        missingNumber ^= i;      
    }
    // missingNumber = 0 ^ 1 ^ 2 ^ 3

    // XOR all numbers in the array
    for (int i=0; i < nums.size(); i++) {
        missingNumber ^= nums[i];
    }
    // missingNumber = 0 ^ 1 ^ 2 ^ 3 ^ 3 ^ 0 ^ 1 = 2

    return missingNumber;
}


int main() {
    vector <int> v = {3, 0, 1};

    // cout << missingNumber_bruteForce(v);

    cout << missingNumber(v);   // This is better approach

    return 0;
}