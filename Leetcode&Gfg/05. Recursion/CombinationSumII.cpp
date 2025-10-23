// Leetcode: 40. Combination Sum II   --->   Given a collection of candidate numbers (candidates) and a target number (target),
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

// Algorithm: Just a simple extension of 'Leetcode&Gfg\05. Recursion\SubsetsII.cpp' problem. Here, we need
//            to find all unique combinations that sum to a given target.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void allSubsequence(int index, vector<int>& candidates, vector<int>& ds, set<vector<int>>& st, int target) {
        // Base case: If index reaches beyond the size of candidates, the subsequence is already made in ds
        if(index == candidates.size()) {
            if(target == 0) {
                vector<int> temp = ds;
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            return;
        }

        // Pick current element
        ds.push_back(candidates[index]);
        allSubsequence(index + 1, candidates, ds, st, target - candidates[index]);
        ds.pop_back();   // Backtrack

        // Not pick the current element
        allSubsequence(index + 1, candidates, ds, st, target);
    }

    // T.C: O(2^n * k.log(k));   where n = candidates.size(), k = average size of each subset               
    // S.C: O(2^n * k);
    vector<vector<int>> combinationSum2_bruteforce(vector<int>& candidates, int target) {
        set<vector<int>> st;   // to store unique subsets
        vector<int> ds;   // to store temporary subsets
        allSubsequence(0, candidates, ds, st, target);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

// ----------------------------------------------------------------------------------------------------------------------

    void findSubsets(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int target) {
        if(target == 0) {
            ans.push_back(ds);
            return;   // No need to explore further once we found a valid combination
        }

        for(int i = index; i < candidates.size(); i++) {
            // Skip duplicates in same recursive level
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            // If the current element exceeds the target, no need to explore further (as the array is sorted).
            // Thus, we can prune the unnecessary branches.
            if(candidates[i] > target) break;

            // Include the current element and move to the next element
            ds.push_back(candidates[i]);
            findSubsets(i + 1, candidates, ans, ds, target - candidates[i]);
            ds.pop_back();   // Backtrack
        }
    }

    // T.C: O(2^n * k);   where n = candidates.size(), k = average size of each subset               
    // S.C: O(2^n * k);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, candidates, ans, ds, target);
        return ans;
    }
};


int main() {
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;

    Solution sol;
    vector<vector<int>> v = sol.combinationSum2_bruteforce(candidates, target);
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> v2 = sol.combinationSum2(candidates, target);
    for(int i=0; i<v2.size(); i++) {
        for(int j=0; j<v2[i].size(); j++) {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
