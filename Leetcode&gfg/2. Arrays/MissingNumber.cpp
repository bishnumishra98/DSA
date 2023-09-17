// Leetcode: 268. Missing Number

#include <iostream>
#include <vector>
using namespace std;

// Brute force
// S.C: O(n)
// T.C: O(1)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum+= nums[i];
    }

    int total_sum = (n*(n+1))/2;

    return total_sum - sum;     
}


int main() {
    vector <int> v = {3, 0, 1};
    cout << missingNumber(v);

    return 0;
}