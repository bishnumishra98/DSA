// Leetcode: 90. Subsets II   --->   Given an integer array nums that may contain duplicates, return all possible
// subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void allSubsequence(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        if(index == nums.size()) {
            ans.push_back(ds);
            return;
        } 

        // Pick current element
        ds.push_back(nums[index]);
        allSubsequence(index+1, nums, ds, ans);
        ds.pop_back();   // Backtrack

        // Not pick the current element
        allSubsequence(index+1, nums, ds, ans);
    }

    void arrangeAndRemoveDuplicateCombinations(vector<vector<int>>& ans) {
        // Sort all elements in each combinations
        for(int i=0; i<ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        // Sort ans based on combinations
        sort(ans.begin(), ans.end());
        // Remove duplicate combinations
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
    }

    // T.C: O(2^n * k);   where n = nums.size(), k = average size of each subset           
    // S.C: O(2^n * k);
    vector<vector<int>> subsetsWithDup_bruteforce(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        allSubsequence(0, nums, ds, ans);
        arrangeAndRemoveDuplicateCombinations(ans);
        return ans;
    }

// -------------------------------------------------------------------------------------------------------

    void findSubsets(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
        ans.push_back(ds);

        for(int i=index; i<nums.size(); i++) {
            // Skip duplicates: If the current element is the same as the previous element,
            // but it is the first time the current element is being considered in this iteration,
            // it should be picked. The only case it shouldn't be picked is when the current element
            // is the same as the previous element, and it is not the first time being considered
            // in this iteration. 'i > index' indicates that the current element is about to get
            // picked up more than once in this iteration, so skip it to avoid duplicates.
            if(i > index && nums[i] == nums[i-1]) continue;

            // Include the current element and move to the next element
            ds.push_back(nums[i]);
            findSubsets(i+1, nums, ans, ds);
            ds.pop_back();   // Backtrack
        }
    }

    // T.C: O(2^n * k);   where n = nums.size(), k = average size of each subset               
    // S.C: O(2^n * k);
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, nums, ans, ds);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};

    Solution sol;

    cout << "Brute force: " << endl;
    vector<vector<int>> ans1 = sol.subsetsWithDup_bruteforce(nums);
    for(int i=0; i<ans1.size(); i++) {
        for(int j=0; j<ans1[i].size(); j++) {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Optimal approach: " << endl;
    vector<vector<int>> ans2 = sol.subsetsWithDup(nums);
    for(int i=0; i<ans2.size(); i++) {
        for(int j=0; j<ans2[i].size(); j++) {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
