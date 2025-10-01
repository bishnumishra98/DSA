// This type of problem follows PICK/NOT PICK pattern.

// An extension of the previous problem '08_AllSubsequenceTargetSum.cpp', return the count of subsequences.

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

// T.C: O(2^n)
// S.C: O(n)
void countSubsequence_approach1(int index, int arr[], int n, int target, int& count) {
    // Base case: If we've considered all elements
    if(index >= n) {
        // If the sum of the current subsequence equals the target, increment count
        if(target == 0) {
            count++;
        }
        return;   // Exit the current recursive call
    }

    // Case 1: Including the current element and proceed to make the subsequence
    countSubsequence_approach1(index + 1, arr, n, target - arr[index], count);

    // Case 2: Excluding the current element and proceed to make the subsequence
    countSubsequence_approach1(index + 1, arr, n, target, count);
}

// T.C: O(2^n)
// S.C: O(n)
int countSubsequence_approach2(int index, int arr[], int n, int target) {
    // Base case: If we've considered all elements
    if(index >= n) {
        // If the sum of the current subsequence equals the target, return 1 indicating a subsequence found.
        if(target == 0) {
            return 1;
        }
        return 0;   // If the sum of the current subsequence does not equals the target, return 0 indicating no subsequence found.
    }

    // Case 1: Including the current element and proceed to make the subsequence
    int include = countSubsequence_approach2(index + 1, arr, n, target - arr[index]);

    // Case 2: Excluding the current element and proceed to make the subsequence
    int exclude = countSubsequence_approach2(index + 1, arr, n, target);

    // return the sum of number of subsequences found from include and exclude paths
    return include + exclude;
}

int main() {
    int arr[] = {1, 2, 1, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    int index = 0;   // starting index

    int count = 0;   // it will be used to store no.of subsequences
    countSubsequence_approach1(index, arr, n, target, count);
    cout << count << endl;

    cout << countSubsequence_approach2(index, arr, n, target);

    return 0;
}
