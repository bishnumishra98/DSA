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
    void allPermut_withSet(int index, vector<int>& nums, vector<vector<int>>& ans) {
        // Base case: When we reach beyond last element of 'nums', push the 'nums' vector in 'ans' and return.
        if(index == nums.size()) {   // Base case can also be if(index == nums.size() - 1) {...} as when 'index'
                                          // reaches 'nums.size() - 1', no change in position of elements occur on further
                                         // recursive call. Thus, the 2nd last level of recursion can also be treated as the base case.
            ans.push_back(nums);
            return;
        }

        // Swapping current element with itself and elements on its right.
        for(int i=index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);
            allPermut_withSet(index+1, nums, ans);
            swap(nums[index], nums[i]);   // backtrack to unswap 'nums' after coming from the above recursion call
        }
    }

    // T.C: O(n! * logn!);   where n = nums.size()
    // S.C: O(n! * n);   excluding 'ans' space
    vector<vector<int>> permuteUnique_withSet(vector<int>& nums) {
        vector<vector<int>> ans;
        allPermut_withSet(0, nums, ans);

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

// ------------------------------------------------------------------------------------------------------------------------------

    void allPermut(int index, vector<int>& nums, vector<vector<int>>& ans) {
        // Base case: When we reach beyond last element of 'nums', push the 'nums' vector in 'ans' and return.
        if(index == nums.size()) {   // Base case can also be if(index == nums.size() - 1) {...} as when 'index'
                                    // reaches 'nums.size() - 1', no change in position of elements occur on further
                                   // recursive call. Thus, the 2nd last level of recursion can also be treated as the base case.
            ans.push_back(nums);
            return;
        }

        // Creating a map to keep track of visited elements so that we can skip a duplicate element iteration
        unordered_map<int, bool> visited;

        // Swapping current element with itself and elements on its right.
        for(int i=index; i<nums.size(); i++) {
            // If this element is already present in 'visited' map, skip this iteration; else mark this element true, i.e., visited.
            if(visited.find(nums[i]) != visited.end()) continue;
            else visited[nums[i]] = true;
            swap(nums[index], nums[i]);
            allPermut(index+1, nums, ans);
            swap(nums[index], nums[i]);   // backtrack to unswap 'nums' after coming from the above recursion call
        }
    }

    // T.C: O(n! * logn!);   where n = nums.size()
    // S.C: O(n);   excluding 'ans' space. O(n) due to map.
    // Without using set. We will use map to keep a track of visited elements in allPermut() function
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        allPermut(0, nums, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};

    Solution sol;
    vector<vector<int>> ans1 = sol.permuteUnique_withSet(nums);
    for(int i=0; i<ans1.size(); i++) {
        for(int j=0; j<ans1[i].size(); j++) {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> ans2 = sol.permuteUnique(nums);
    for(int i=0; i<ans2.size(); i++) {
        for(int j=0; j<ans2[i].size(); j++) {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
