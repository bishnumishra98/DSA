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
void printAllSubsequence_approach1(int index, int arr[], int n, int& target, int sum, int& count) {
    // Base case: If we've considered all elements
    if(index >= n) {
        // Check if the sum of the current subsequence equals the target
        if(sum == target) {
            count++;
        }
        return;   // Exit the current recursive call
    }

    // Case 1: Including the current element and proceed to make the subsequence
    printAllSubsequence_approach1(index + 1, arr, n, target, sum + arr[index], count);

    // Case 2: Excluding the current element and proceed to make the subsequence
    printAllSubsequence_approach1(index + 1, arr, n, target, sum, count);
}

int main() {
    int arr[] = {1, 2, 1, 4, 2, 3};
    int n = 6;
    int target = 4;
    int index = 0;   // starting index

    int sum = 0;   // used as a helper data-structure to store sum of elements in the subsequences
    int count = 0;   // it will store no.of subsequences
    printAllSubsequence_approach1(index, arr, n, target, sum, count);
    cout << count << endl;

    return 0;
}
