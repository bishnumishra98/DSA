// This type of problem follows PICK/NOT PICK pattern.

// Given an array, print all its subsequence. All subsequence must follow the ordering of elements as it is in parent array.
// For example, for the arrat {6, 7, 8}, {8, 6} cannot be a subsequence of it, but {6, 8} is a subsequence.
// Example:
// Input:
// {6, 7, 8}
// Output:
// {6, 7, 8}, {6, 7}, {6, 8}, {6}, {7, 8}, {7}, {8}, {}

#include <iostream>
#include <vector>
using namespace std;

void helper(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    // Base case: If index reaches beyond the last element of 'arr', the subsequence is already built in 'ds'. Thus, return.
    if(index == arr.size()) {
        ans.push_back(ds);
        return;
    }

    // PICK: Pick the element at ith index to be a part of subsequence and proceed to make the subsequence
    ds.push_back(arr[index]);
    helper(index + 1, arr, ds, ans);
    ds.pop_back();   // Backtracking: remove the last element that was added to the 'ds' vector in the previous step.
    // However, note that we do not need to perform this pop operation, if Case 2 was written prior to Case 1.

    // NOT PICK: DO not pick the element at ith index to be a part of subsequence and proceed to make the subsequence
    helper(index + 1, arr, ds, ans);
}

// T.C: O(2^n)
// S.C: O(n)   recursive stack space
vector<vector<int>> findAllSubsequence(vector<int>& arr) {
    vector<int> ds;   // helper data-structure to store each subsequence
    vector<vector<int>> ans;   // all subsequences will be stored here
    int index = 0;
    helper(index, arr, ds, ans);
    return ans;
}


int main() {
    vector<int> arr = {6, 7, 8};
    vector<vector<int>> ans = findAllSubsequence(arr);
    for(auto it1: ans) {
        for(auto it2: it1) cout << it2 << " ";
        cout << ", ";
    }

    return 0;
}
