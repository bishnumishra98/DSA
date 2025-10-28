// GFG: Count Inversions   --->   Given an array of integers arr[]. You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Example 1:
// Input: n = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Example 2:
// Input: n = 5, arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

// Example 3:
// Input: n = 5, arr[] = {5, 3, 2, 4, 1}
// Output: 8

// Understand 'BaseBuildingPrograms\05. Sorting\04_MergeSort.cpp' before understand optimal solution of this problem.

// Problem: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(1)
    int inversionCount_bruteForce(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] > arr[j]) count++;
            }
        }
        return count;
    }

// ---------------------------------------------------------------------------------------

    int merge(vector<int> &arr, int start, int mid, int end) {
        vector<int> temp(end - start + 1);
        int left = start;   // index of left side of array will range from index 'start' to 'mid'
        int right = mid + 1;   // index of right side of array will range from index 'mid + 1' to 'end'

        int count = 0;   // Addition 1: count variable to count the pairs

        int k = 0;
        while(left <= mid && right <= end) {
            if(arr[left] <= arr[right]) {
                temp[k] = arr[left];
                k++;
                left++;
            } else {
                // If the right array's element is smaller, all elements of left array from this point can form a pair with it.
                // No.of pairs made will be nothing but the no.of elements remaining in left array, that is: mid - left + 1.
                temp[k] = arr[right];
                k++;
                right++;
                count += (mid - left + 1);   // Addition 2   // (mid - left + 1) is the count of pairs
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

        for(int i = start; i <= end; i++) {
            arr[i] = temp[i - start];
        }

        return count;   // Addition 3
    }

    int mergeSort(vector<int> &arr, int start, int end) {
        int count = 0;
        if(start >= end) return count;

        int mid = start + (end - start) / 2;
        count += mergeSort(arr, start, mid);   // left half
        count += mergeSort(arr, mid + 1, end);   // right half
        count += merge(arr, start, mid, end);   // merge the two sorted halves

        return count;
    }

    // T.C: O(nlogn)
    // S.C: O(n)
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);   // return the number of pairs
    }
};

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    Solution sol;

    cout << sol.inversionCount_bruteForce(arr);
    cout << endl;

    arr = {2, 4, 1, 3, 5};
    cout << sol.inversionCount(arr);

    return 0;
}
