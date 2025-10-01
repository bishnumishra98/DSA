// This type of problem follows PICK/NOT PICK pattern.

// An extension of the previous problem '05_AllSubsequenceTargetSum.cpp', print only 1 subsequence, not all.
// Find any one subsequence whose sum is equal to target.

// Example 1:
// Input:
// {1, 2, 1, 4, 2, 3}, target = 4
// Output:
// {1, 2, 1}

// Example 2:
// Input:
// {1, 2, 1}, target = 3
// Output:
// {1, 2}

#include <iostream>
#include <vector>
using namespace std;

void helper(int index, vector<int>& arr, vector<int>& ds, vector<int>& ans, int target, bool& found) {
    // Base case: If index reaches beyond the last element of 'arr', the subsequence is already built in 'ds'.
    //            If target remaining is 0 at this point, it means the current subsequence equals target.
    //            Thus, change the value of found to true.
    if(index == arr.size()) {
        if(target == 0) {
            ans = ds;
            found = true;
        }
        return;
    }

    // Perform pick, not pick operations only if unique subsequence equals target has not been found yet
    if(!found) {
        // PICK
        ds.push_back(arr[index]);
        helper(index + 1, arr, ds, ans, target - arr[index], found);
        ds.pop_back();

        // NOT PICK
        helper(index + 1, arr, ds, ans, target, found);
    }
}

// T.C: O(2^n)
// S.C: O(n)   recursive stack space
vector<int> findOneSubsequenceEqualsTarget(vector<int>& arr, int target) {
    vector<int> ds;   // helper data-structure to store each subsequence
    vector<int> ans;   // the unique subsequence will be stored here
    int index = 0;
    bool found = false;   // helper data structure to notify whether unique subsequence equals target has been found or not
    helper(index, arr, ds, ans, target, found);
    return ans;
}


int main() {
    vector<int> arr = {1, 2, 1, 4, 2, 3};
    int target = 4;

    vector<int> ans = findOneSubsequenceEqualsTarget(arr, target);
    for(auto it: ans) cout << it << " ";

    return 0;
}
