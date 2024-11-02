// Leetcode: 2643. Row With Maximum Ones   --->   Given a m x n binary matrix mat, find the 0-indexed position of the
// row that contains the maximum count of ones, and the number of ones in that row.
// In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should
// be selected.
// Return an array containing the index of the row, and the number of ones in it.

// Example 1:
// Input: mat = [[0,1],[1,0]]
// Output: [0,1]
// Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 

// Example 2:
// Input: mat = [[0,0,0],[0,1,1]]
// Output: [1,2]
// Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].

// Example 3:
// Input: mat = [[0,0],[1,1],[0,0]]
// Output: [1,2]
// Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m*n)
    // S.C: O(1)
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2, 0);   // Initializing a vector of size 2; by default lets assume row 0 has maximum ones.

        for(int i = 0; i < mat.size(); i++) {
            int ones = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) ones++;
            }
            // If no.of ones found is greater than no.of ones present in 'ans', update the row with no.of ones in 'ans'
            if(ones > ans[1]) {
                ans[0] = i;
                ans[1] = ones;
            }
        }

        return ans;
    }
};


int main() {
    vector <vector<int>> mat = {{0, 0, 0}, {0, 1, 1}};
    vector<int> ans = Solution().rowAndMaximumOnes(mat);
    for(auto it: ans) cout << it << " ";

    return 0;
}
