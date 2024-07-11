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

// Understand 'BaseBuildingPrograms\05. Sorting\MergeSort.cpp' before understand optimal solution of this problem.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // T.C: O(n^2)
    // S.C: O(1)
    long long int inversionCount_bruteForce(long long arr[], int n) {
        long long count = 0;
        for(long long i=0; i<n; i++) {
            for(long long j=i+1; j<n; j++) {
                if(arr[i] > arr[j]) count++;
            }
        }
        return count;
    }

// ---------------------------------------------------------------------------------------

    long long merge(long long *arr, long long start, long long mid, long long end) {
        long long *temp = new long long[end-start+1];
        long long left = start;
        long long right = mid+1;

        long long count = 0;   // Modification 1: count variable to count the pairs

        long long k = 0;
        while(left<=mid && right<=end) {
            if(arr[left] <= arr[right]) {
                temp[k] = arr[left];
                k++;
                left++;
            } else {
                temp[k] = arr[right];
                k++;
                right++;
                count += (mid - left + 1);   // Modification 2
            }
        }

        while(left <= mid) {
            temp[k] = arr[left];
            k++;
            left++;
        }

        while(right <= end) {
            temp[k] = arr[right];
            k++;
            right++;
        }

        for(long long i=start; i<=end; i++) {
            arr[i] = temp[i-start];
        }

        delete[] temp;

        return count;   // Modification 3
    }

    long long mergeSort(long long *arr, long long start, long long end) {
        long long count = 0;
        if(start >= end) return count;

        long long mid = start + (end - start) / 2;
        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid+1, end);
        count += merge(arr, start, mid, end);

        return count;
    }

    // T.C: O(nlogn)
    // S.C: O(n)
    long long int inversionCount(long long arr[], int n) {
        return mergeSort(arr, 0, n - 1);   // return the number of pairs
    }
};

int main() {
    long long arr[] = {2, 4, 1, 3, 5};
    int n = 5;

    Solution sol;
    cout << sol.inversionCount_bruteForce(arr, n);
    cout << endl;
    cout << sol.inversionCount(arr, n);

    return 0;
}
