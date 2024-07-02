// Leetcode 47. Permutations II   --->   Given a collection of numbers, nums, that might contain duplicates,
// return all possible unique permutations in any order.

// Example 1:
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// Example 2:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void allPermut(int index, vector<int>& candidates, vector<vector<int>>& ans) {
        // Base case: When we reach beyond last element of 'candidates', push the 'candidates' vector in 'ans' and return.
        if(index == candidates.size()) {   // Base case can also be if(index == candidates.size() - 1) {...} as when 'index'
                                          // reaches 'candidates.size() - 1', no change in position of elements occur on further
                                         // recursive call. Thus, the 2nd last level of recursion can also be treated as the base case.
            ans.push_back(candidates);
            return;
        }

        // Swapping current element with itself and elements on its right.
        for(int i=index; i<candidates.size(); i++) {
            swap(candidates[index], candidates[i]);
            allPermut(index+1, candidates, ans);
            swap(candidates[index], candidates[i]);   // backtrack to unswap 'candidates' after coming from the above recursion call
        }
    }

    // T.C: O(n! * logn!);   where n = candidates.size()
    // S.C: O(n! * n);   excluding 'ans' space
    vector<vector<int>> permuteUnique_withSet(vector<int>& nums) {
        vector<vector<int>> ans;
        allPermut(0, nums, ans);

        // Use a set to remove duplicates
        set<vector<int>> st;
        for(auto permutation: ans) {
            st.insert(permutation);
        }
        ans.clear();   // clear the 'ans' vector
        for(auto permutation: st) {
            ans.push_back(permutation);
        }

        return ans;
    }
};

// ---------------------------------------------------------------------------------------------------------

int main() {
    vector<int> nums = {1, 1, 2};

    Solution sol;
    vector<vector<int>> ans = sol.permuteUnique_withSet(nums);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
