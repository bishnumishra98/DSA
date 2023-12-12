// Leetcode: 74. Search a 2D Matrix   ---> Given an integer target, return true if
// target is in matrix or false otherwise.

// 2D -> 1D formula: c*i+j
// 1D -> 2D formula: i = index/c,  j = index%c

// This problem is an implementation of binary search.

#include<iostream>
#include <vector>
using namespace std;

// T.C: O(log(m*n))
// S.C: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int numberOfRowsIn2DArray = matrix.size();
    int numberOfColumnsIn2DArray = matrix[0].size();
    int numberOfElementsIn2DArray = numberOfRowsIn2DArray * numberOfColumnsIn2DArray;

    int start = 0;
    int end = numberOfElementsIn2DArray - 1;
    int mid = start + (end - start)/2;

    while(start <= end) {
        int row_no = mid / numberOfColumnsIn2DArray;
        int col_no = mid % numberOfColumnsIn2DArray;
        int currentElementIn2DArray = matrix[row_no][col_no];

        if(target == currentElementIn2DArray) {
            return true;
        } else if(target > currentElementIn2DArray) {   // go to right
            start = mid + 1;
        } else {   // go to left
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return false;   // if target not found
}

int main() {
    vector<vector <int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;
    
    cout << searchMatrix(matrix, target);

    return 0;
}