// Leetcode: 74. Search a 2D Matrix   --->   You are given an m x n integer matrix matrix with the following two properties:
// • Each row is sorted in non-decreasing order.
// • The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// 2D -> 1D formula: c * row + col
// 1D -> 2D formula: row = index / c,  col = index % c


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(log(m*n))
    // S.C: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows * cols;

        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;

        while(start <= end) {
            int row = mid / cols;   // 'mid' is the element's index in 1D array
            int col = mid % cols;
            int curr = matrix[row][col];

            if(target > curr) start = mid + 1;
            else if(target < curr) end = mid - 1;
            else return true;   // if(target == curr)

            mid = start + (end - start) / 2;
        }

        return false;   // if target not found
    }
};


int main() {
    vector<vector <int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    
    cout << Solution().searchMatrix(matrix, target);

    return 0;
}
