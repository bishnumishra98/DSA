// Leetcode 40. Combination Sum II   --->   Given a collection of candidate numbers (candidates) and a target number (target),
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
    void findAllCombinations(vector<int>& candidates, vector<vector<int>>& ans, int index, int target, vector<int>& ds) {
        // Base case: If index goes beyond last element of candidates
        if(index > candidates.size() - 1) {
            if(target == 0) ans.push_back(ds);
            return;
        }

        // Case 1: Include the current element
        ds.push_back(candidates[index]);
        findAllCombinations(candidates, ans, index+1, target - candidates[index], ds);
        ds.pop_back();

        // Case 2: Exclude the current element
        findAllCombinations(candidates, ans, index+1, target, ds);
    }

    void arrangeAndRemoveDuplicateCombinations(vector<vector<int>>& ans) {
        // Sort all elements in each combinations
        for(int i=0; i<ans.size(); i++) {
            for(int j=0; j<ans[i].size(); j++) {
                sort(ans[i].begin(), ans[i].end());
            }
        }
        // Sort ans based on combinations
        sort(ans.begin(), ans.end());
        // Remove duplicate combinations
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
    }

    // T.C: O(nlogn + 2^n) 
    // S.C: O(n)
    vector<vector<int>> combinationSum2_bruteForce(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;   // starting index
        findAllCombinations(candidates, ans, index, target, ds);
        arrangeAndRemoveDuplicateCombinations(ans);
        return ans;
    }

// ----------------------------------------------------------------------------------------------------------------------
    // The above code can be more optimized by leveraging the sorted order during the recursive
    // combination generation itself, which can avoid the need for post-processing.

    void findCombination(vector<int>& candidates, vector<vector<int>>& ans, int index, int target, vector<int>& ds) {
        // Base case: If target becomes zero, add the current combination to ans
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Iterate over the candidates starting from the current index
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            // If the current candidate is greater than the target, no need to proceed further
            if (candidates[i] > target) break;

            // Include the current element and move to the next element
            ds.push_back(candidates[i]);
            findCombination(candidates, ans, i + 1, target - candidates[i], ds);
            ds.pop_back();   // Backtrack
        }
    }

    // T.C: O(2^n * k);   where n is the number of candidates and k is the average length of a combination
    // S.C: O(k * x);   x is the number of combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());   // Sort the candidates to handle duplicates easily
        findCombination(candidates, ans, 0, target, ds);
        return ans;
    }
};


int main() {
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;

    Solution sol;
    vector<vector<int>> v = sol.combinationSum2_bruteForce(candidates, target);
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
