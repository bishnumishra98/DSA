// GFG: Count Inversions   --->   Given an array of integers. Find the Inversion Count in the array.
// Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
// If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.

// Example 1:
// Input: n = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Example 2:
// Input: n = 5, arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // T.C: 
    // S.C: 
    long long int inversionCount(long long arr[], int n) {
        
    }
};

int main() {
    long long arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    
    Solution sol;
    cout << sol.inversionCount(arr, n);

    return 0;
}
