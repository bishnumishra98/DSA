// GFG: Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O'
// or a group of 'O' with 'X' that are surrounded by 'X'.
// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below,
//  just above, just left and just right of it.

// Example 1:
// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.

// Example 2:
// Input: 
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // T.C:
    // S.C: 
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        
    }
};

int main() {
    vector<vector<char>> mat = {{'X', 'X', 'X', 'X'}, 
                                {'X', 'O', 'X', 'X'}, 
                                {'X', 'O', 'O', 'X'}, 
                                {'X', 'O', 'X', 'X'}, 
                                {'X', 'X', 'O', 'O'}};
    int n = mat.size();
    int m = mat[0].size();
    
    Solution sol;
    vector<vector<char>> ans = sol.fill(n, m, mat);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
