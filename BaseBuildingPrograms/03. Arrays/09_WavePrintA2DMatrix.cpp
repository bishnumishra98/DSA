// Given a 2D matrix, return the sequence of its wave.

// Example 1:
// Input: {10, 20, 30},
//        {40, 50, 60},
//        {70, 80, 90}
// Output: 10, 40, 70, 80, 50, 20, 30, 60, 90

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(n*m);   where n = no.of rows and m = no. of cols in array respectively
// S.C: O(n)
vector<int> wave(vector<vector<int>> arr) {
    int rows = arr.size();
    int cols = arr[0].size();
    vector<int> ans;

    for(int col = 0; col < cols; col++) {
        if((col & 1) == 0) {   // if its even col, ex: 0, 2, etc; the store from up to bottom
            for(int row = 0; row < rows; row++) ans.push_back(arr[row][col]);
        } else {   // if its odd col, ex: 1, 3, etc; the store from bottom to up
            for(int row = rows - 1; row >= 0; row--) ans.push_back(arr[row][col]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {{10, 20, 30},
                               {40, 50, 60},
                               {70, 80, 90}};
    vector<int> ans = wave(arr);
    for(auto it: ans) cout << it << " ";

    return 0;
}
