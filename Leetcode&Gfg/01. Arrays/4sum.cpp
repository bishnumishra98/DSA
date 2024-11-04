// Leetcode: 18. 4Sum   --->   Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
// ▸ 0 <= a, b, c, d < n
// ▸ a, b, c, and d are distinct.
// ▸ nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^4)
    // S.C: O(2n)
    vector<vector<int>> fourSum_bruteforce(vector<int>& nums, int target) {
        set<vector<int>> st;   // set in order to store only unique vectors
        
        for(int i = 0; i < nums.size() - 3; i++) {
            for(int j = i + 1; j < nums.size() - 2; j++) {
                for(int k = j + 1; k < nums.size() - 1; k++) {
                    for(int l = k + 1; l < nums.size(); l++) {
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

// -----------------------------------------------------------------------------------

    // Algorithm: Similar to '3Sum.cpp'
    // T.C: O(n^3)
    // S.C: O(2n)
    vector<vector<int>> fourSum_threepointer(vector<int>& nums, int target) {
        set<vector<int>> st;

        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                unordered_set<int> hashset;
                for(int k = j + 1; k < nums.size(); k++) {
                    int fourth = target - (nums[i] + nums[j] + nums[k]);
                    // If fourth element is present in hashset, it means a quad can be formed using 'nums[i]', 'nums[j]',
                    // 'nums[k]' and fourth element. Thus, sort and store the quad in a set to store only unique quads.
                    // If the fourth element is not found in hashset, then store the current element 'nums[k]' in hashset.
                    if(hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

// ---------------------------------------------------------------------------------------------------------------

    // Best algorithm: 4 pointer approach (similar to '3Sum.cpp')
    // T.C: O(n^3)
    // S.C: O(n)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};   // edge case
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = nums.size() - 1;

                while(k < l) {
                    // Adding sum like this in order to avoid signed integer overflow
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};


int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // vector<vector<int>> ans = Solution().fourSum_bruteforce(nums, target);
    // vector<vector<int>> ans = Solution().fourSum_threepointer(nums, target);
    vector<vector<int>> ans = Solution().fourSum(nums, target);

    for(auto it1: ans) {
        for(auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
