// Example:
// Input: nums = [3,2,1,5,6,4], k = 3
// Output: 4

// These type of questions can be solved in 3 mthods:
// 1. Brute force approach (using sort() function)
// 2. Using min heap
// 3. Using max heap

#include <iostream>
#include <vector>
#include <algorithm>   // for sort()
using namespace std;

// T.C: 
// S.C: 
int findKthLargest_bruteForce(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());   // sorts array in descending order
    return nums[k-1];
}

int main() {
    vector <int> v = {3,2,1,5,6,4};
    int k = 3;


    return 0;
}
