#include <bits/stdc++.h>
using namespace std;

// File: solution.cpp
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0;
        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < nums.size(); ++right) {
            if (++mp[nums[right]] == 1) {
                sum += nums[right];
            }

            while (sum >= k) {
                ans = min(ans, right - left + 1);
                if (--mp[nums[left]] == 0) {
                    sum -= nums[left];
                }
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};




int main() {
    
    
    return 0;
}
