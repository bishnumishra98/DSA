// This type of problem follows PICK/NOT PICK pattern.

// Find all subsequence whose sum is equal to target.
// Example 1:
// Input:
// {1, 2, 1, 4, 2, 3}, target = 4
// Output:
// {1, 2, 1}, {1, 1, 2}, {1, 3}, {2, 2}, {1, 3}, {4}

// Example 2:
// Input:
// {1, 2, 1}, target = 3
// Output:
// {1, 2}, {2, 1}

#include <iostream>
#include <vector>
using namespace std;

void helper(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans, int target) {
    // Base case: If index reaches beyond the last element of 'arr', the subsequence is already built in 'ds'.
    //            If target remaining is 0 at this point, it means the current subsequence equals target.
    if(index == arr.size()) {
        if(target == 0) ans.push_back(ds);
        return;
    }

    // PICK: Pick the element at ith index to be a part of subsequence and proceed to make the subsequence. If the
    //       current element is included to be a part of subsequence, then reduce the remaining target by current element.
    ds.push_back(arr[index]);
    helper(index + 1, arr, ds, ans, target - arr[index]);
    ds.pop_back();   // Backtracking: remove the last element that was added to the 'ds' vector in the previous step.
    // However, note that we do not need to perform this pop operation, if Case 2 was written prior to Case 1.

    // NOT PICK: DO not pick the element at ith index to be a part of subsequence and proceed to make the subsequence
    helper(index + 1, arr, ds, ans, target);
}

// T.C: O(2^n)
// S.C: O(n)   recursive stack space
vector<vector<int>> findAllSubsequenceEqualsTarget(vector<int>& arr, int target) {
    vector<int> ds;   // helper data-structure to store each subsequence
    vector<vector<int>> ans;   // all subsequences will be stored here
    int index = 0;
    helper(index, arr, ds, ans, target);
    return ans;
}


int main() {
    vector<int> arr = {1, 2, 1};
    int target = 3;
    vector<vector<int>> ans = findAllSubsequenceEqualsTarget(arr, target);
    for(auto it1: ans) {
        for(auto it2: it1) cout << it2 << " ";
        cout << ", ";
    }

    return 0;
}
