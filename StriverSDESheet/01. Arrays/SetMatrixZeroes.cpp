// Leetcode 73. Set Matrix Zeroes   --->   Given an m x n integer matrix matrix, if
// an element is 0, set its entire row and column to 0's. You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++) {
            
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution obj;
    obj.setZeroes(matrix);
    
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
