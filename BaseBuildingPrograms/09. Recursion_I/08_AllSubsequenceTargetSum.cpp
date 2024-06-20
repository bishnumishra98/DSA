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

// T.C: O(2^n)
// S.C: O(n)
void printAllSubsequence(int index, int arr[], int n, int& target, vector<int>& ds, int sum) {
    // Base case: If we've considered all elements
    if(index >= n) {
        // Check if the sum of the current subsequence equals the target
        if(sum == target) {
            for(int i: ds) {
                cout << i << " ";
            }
            cout << endl;
        }
        return;   // Exit the current recursive call
    }

    // Case 1: Including the current element and proceed to make the subsequence
    ds.push_back(arr[index]);
    printAllSubsequence(index + 1, arr, n, target, ds, sum + arr[index]);
    ds.pop_back();   // Backtrack to remove the current element

    // Case 2: Excluding the current element and proceed to make the subsequence
    printAllSubsequence(index + 1, arr, n, target, ds, sum);
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int target = 3;
    int index = 0;   // starting index

    vector<int> ds;   // used as a helper data-structure to store subsequences
    int sum = 0;   // used as a helper data-structure to store sum of elements in the subsequences
    printAllSubsequence(index, arr, n, target, ds, sum);

    return 0;
}
