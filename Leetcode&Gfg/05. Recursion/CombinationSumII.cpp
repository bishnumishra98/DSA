// Leetcode 40. Combination Sun II   --->   Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombination(vector<int>& candidates, vector<vector<int>>& ans, int index, int target, vector<int>& ds) {
        // Base case:
        if(index > candidates.size() - 1) {
            if(target == 0) {
                sort(ds.begin(), ds.end());
                ans.push_back(ds);
            }
            return;
        }

        // Case 1: Include the current element
        ds.push_back(candidates[index]);
        findCombination(candidates, ans, index+1, target - candidates[index], ds);
        ds.pop_back();

        // Case 2: Exclude the current element
        findCombination(candidates, ans, index+1, target, ds);
    }

    // T.C:
    // S.C: 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;   // starting index
        findCombination(candidates, ans, index, target, ds);
        return ans;
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution sol;
    vector<vector<int>> v = sol.combinationSum2(candidates, target);
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
