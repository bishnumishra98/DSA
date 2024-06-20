// This type of problem follows PICK/NOT PICK pattern.

// An extension of the previous problem '08_AllSubsequenceTargetSum.cpp', print only 1 subsequence, not all.
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

// T.C: O(2^n)
// S.C: O(n)
void printAnySubsequence_approach1(int index, int arr[], int n, int& target, vector<int>& ds, int sum, bool& found) {
    // Base case: If we've considered all elements
    if(index >= n) {
        // If the sum of the current subsequence equals the target, return true
        if(sum == target) {
            for(int i: ds) {
                cout << i << " ";
            }
            cout << endl;
            found = true;
        }
        return;   // Exit the current recursive call
    }

    // Case 1: If subsequence is not found yet, try including the current element and proceed to make the subsequence
    if(!found) {
        ds.push_back(arr[index]);
        printAnySubsequence_approach1(index + 1, arr, n, target, ds, sum + arr[index], found);
        ds.pop_back();
    }
    
    // Case 2: If subsequence is not found yet, try excluding the current element and proceed to make the subsequence
    if(!found) printAnySubsequence_approach1(index + 1, arr, n, target, ds, sum, found);
}

// T.C: O(2^n)
// S.C: O(n)
bool printAnySubsequence_approach2(int index, int arr[], int n, int& target, vector<int>& ds, int sum) {
    // Base case: If we've considered all elements
    if(index >= n) {
        // If the sum of the current subsequence equals the target, return true
        if(sum == target) {
            for(int i: ds) {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;   // If the sum of the current subsequence does not equals the target, return false
    }

    // Case 1: Including the current element and proceed to make the subsequence
    ds.push_back(arr[index]);
    // If this function call returns a true, it means a subsequence has already been found via this path. Thus, return true.
    if(printAnySubsequence_approach2(index + 1, arr, n, target, ds, sum + arr[index]) == true) return true;
    ds.pop_back();

    // Case 2: Excluding the current element and proceed to make the subsequence
    // If this function call returns a true, it means a subsequence has already been found via this path. Thus, return true.
    if(printAnySubsequence_approach2(index + 1, arr, n, target, ds, sum) == true) return true;

    // If program comes here, it means no subsequence has been found in any of the 2 paths yet. Thus, return false.
    return false;
}

int main() {
    int arr[] = {1, 2, 1, 4, 2, 3};
    int n = 6;
    int target = 4;
    int index = 0;   // starting index

    vector<int> ds;   // used as a helper data-structure to store subsequences
    int sum = 0;   // used as a helper data-structure to store sum of elements in the subsequences
    bool found = false;   // used as a helper data-structure to validate if any subsequence found or not

    printAnySubsequence_approach1(index, arr, n, target, ds, sum, found);
    if(!found) cout << -1 << endl;   // Print -1 if no valid subsequence was found
    
    if(!printAnySubsequence_approach2(index, arr, n, target, ds, sum)) {
        cout << -1 << endl;   // Print -1 if no valid subsequence was found
    }

    return 0;
}
