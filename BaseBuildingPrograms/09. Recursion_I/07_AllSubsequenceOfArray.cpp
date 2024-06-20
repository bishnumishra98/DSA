// This type of problem follows PICK/NOT PICK pattern.

// Given an array, print all its subsequence. All subsequence must follow the ordering of elements as it is in parent array.
// For example, {8, 6} cannot be a subsequence, but {6, 8} is a subsequence.
// Example:
// Input:
// {6, 7, 8}
// Output:
// {6, 7, 8}, {6, 7}, {6, 8}, {6}, {7, 8}, {7}, {8}, {}

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(2^n)
// S.C: O(n);   maximum depth of recursive tree is no.of elements in 'arr'.
void printSubsequence(int index, int arr[], int n, vector<int>& ds) {
    // Base case: if index >= n, print the subsequence formed inside 'ds' and return.
    if(index >= n) {
        for(int i: ds) {
            cout << i << " ";
        }
        if(ds.size() == 0) cout << "{}";   // just to show no element. This is optional.
        cout << endl;
        return;
    }

    // Case 1: Take the current element of 'arr' and proceed to make the subsequence
    ds.push_back(arr[index]);
    printSubsequence(index+1, arr, n, ds);
    ds.pop_back();   // ds.pop_back() is used to remove the last element that was added to the 'ds' vector in the previous
    // step. This is necessary because, after all subsequences that include the current element (at arr[index]) have been
    // printed, you need to backtrack and remove that element from 'ds' to explore subsequences that do not include this element.
    // However, note that we do not need to perform this pop operation, if Case 2 was written prior to Case 1.

    // Case 2: Not take the current element of 'arr' and proceed to make the subsequence
    printSubsequence(index+1, arr, n, ds);
}

int main() {
    int arr[] = {6, 7, 8};
    int start_index = 0;
    int n = 3;
    vector<int> ds;   // used as a helper data-structure to store subsequences

    printSubsequence(start_index, arr, n, ds);

    return 0;
}
