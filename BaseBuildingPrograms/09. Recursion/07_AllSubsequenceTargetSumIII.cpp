// This type of problem follows PICK/NOT PICK pattern.

// An extension of the previous problem '05_AllSubsequenceTargetSum.cpp', return the count of subsequences.

// Example 1:
// Input:
// {1, 2, 1, 4, 2, 3}, target = 4
// Output:
// 6
// Explanation:
// The six subsequences are as follows: {1, 2, 1}, {1, 1, 2}, {1, 3}, {2, 2}, {1, 3}, {4}

// Example 2:
// Input:
// {1, 2, 1}, target = 3
// Output:
// 2
// Explanation:
// The two subsequences are as follows: {1, 2}, {2, 1}

#include <iostream>
#include <vector>
using namespace std;

void helper(int index, vector<int>& arr, int& count, int target) {
    // Base case: If index reaches beyond the last element of 'arr' and target remaining is 0 at this point,
    // it means the current subsequence equals target.
    if(index == arr.size()) {
        if(target == 0) count++;
        return;
    }

    // PICK: Pick the element at ith index to be a part of subsequence and proceed to make the subsequence. If the
    //       current element is included to be a part of subsequence, then reduce the remaining target by current element.
    helper(index + 1, arr, count, target - arr[index]);
    
    // NOT PICK: DO not pick the element at ith index to be a part of subsequence and proceed to make the subsequence
    helper(index + 1, arr, count, target);
}

// T.C: O(2^n)
// S.C: O(n)   recursive stack space
int countSubsequence(vector<int>& arr, int target) {
    int count = 0;   // count of subsequences will be stored here
    int index = 0;
    helper(index, arr, count, target);
    return count;
}


int main() {
    vector<int> arr = {1, 2, 1, 4, 2, 3};
    int target = 4;
    
    cout << countSubsequence(arr, target);

    return 0;
}
