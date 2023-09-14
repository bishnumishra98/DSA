// leetcode: 1572. Matrix Diagonal Sum

#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int p_diag_sum = 0;
    int s_diag_sum = 0;
    int subtract_middle_element = 0;

    for(int i=0; i<n; i++) {
        p_diag_sum += mat[i][i];
        s_diag_sum += mat[i][n-i-1];
    }

    // if(n%2 != 0) {   // for odd no.of elements in a row of matrix
    //     subtract_middle_element = mat[n/2][n/2];
    // }
    
    // int ans = p_diag_sum + s_diag_sum - subtract_middle_element;
    // return ans;

    return n%2==0 ? (p_diag_sum + s_diag_sum) : (p_diag_sum + s_diag_sum - mat[n/2][n/2]);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << diagonalSum(matrix);
    
    return 0;
}