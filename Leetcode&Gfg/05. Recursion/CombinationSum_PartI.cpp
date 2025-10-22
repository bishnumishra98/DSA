// Leetcode: 39. Combination Sum    --->   Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the
// combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than
// 150 combinations for the given input.

// Algorithm: This type of problem follows PICK/NOT PICK pattern, that we learnt in
//           'BaseBuildingPrograms/09. Recursion_I/08_AllSubsequenceTargetSum.cpp'.
//           The only difference being we can pick an element multiple times to make the target.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:
// Input: candidates = [2], target = 1
// Output: []

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Calling recursive function if needed
    void findCombination(int index, vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& ds) {
        // Base case: When we reach beyond the end of the candidates list
        if(index == candidates.size()) {
            if(target == 0) ans.push_back(ds);   // If target becomes zero, add the current combination to 'ans'
            return;
        }

        // Case 1: Include the current element only if subtracting it from target doesn't make target negative
        if(target >= candidates[index]) {   // This condition is mandatory to avoid stack overflow error due to infinite recursive calls
            ds.push_back(candidates[index]);
            // Call the function recursively with the same index (since the same element can be chosen multiple times)
            findCombination(index, candidates, ans, target - candidates[index], ds);
            ds.pop_back();   // Backtracking, i.e., remove current element from 'ds' while coming back from the above recursive call
        }

        // Case 2: Exclude the current element and just go to next element
        findCombination(index + 1, candidates, ans, target, ds);
    }

    // // Method 2: Calling recursive function everytime, but handling the stack overflow error in base case
    // void findCombination(int index, vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& ds) {
    //     // Base cases: When target is negative or we reach beyond the end of the candidates list
    //     if(target < 0) return;
    //     if(index == candidates.size()) {
    //         if(target == 0) ans.push_back(ds);   // If target becomes zero, add the current combination to 'ans'
    //         return;
    //     }

    //     // Case 1: Include the current element
    //     ds.push_back(candidates[index]);
    //     // Call the function recursively with the same index (since the same element can be chosen multiple times)
    //     findCombination(index, candidates, ans, target - candidates[index], ds);
    //     ds.pop_back();   // Backtracking, i.e., remove current element from 'ds' while coming back from the above recursive call

    //     // Case 2: Exclude the current element and just go to next element
    //     findCombination(index + 1, candidates, ans, target, ds);
    // }

    // EXTRA NOTE: Method 1 is faster because you don’t recurse into invalid branches (target < 0 never happens).


    // T.C: O((n^t) * k);   where n = no.of elements in candidates[], t = target value, k = average length of each combination in 'ans'
    // S.C: O(t + m * k);   where m = no.of combinations in 'ans'
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;   // This will be our final answer
        vector<int> ds;   // This is going to store elements temporary, while traversing
        int index = 0;   // starting index
        findCombination(index, candidates, ans, target, ds);
        return ans;
    }
};

int main() {
    vector<int> candidates = {2, 3};
    int target = 6;

    Solution sol;
    vector<vector<int>> v = sol.combinationSum(candidates, target);
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
