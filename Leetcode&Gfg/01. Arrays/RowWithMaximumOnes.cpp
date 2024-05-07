// Leetcode: 2643. Row With Maximum Ones

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
    for (const auto& element : v) {
        cout << element << " ";
    }
}

// Brute force
// T.C: O(m*n)
// S.C: O(1)
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector <int> ans;
    int n = mat.size();   // no.of rows in mat
    int maxOneCount = -1;
    int highestOneIndexRow = -1;

    for(int i=0; i<n; i++) {
        int oneCount = 0;
        for(int j=0; j<mat[i].size(); j++) {
            if(mat[i][j] == 1) {
                oneCount++;
            }
            if(oneCount > maxOneCount) {
                maxOneCount = oneCount;
                highestOneIndexRow = i;
            }
        }
    }

    ans.push_back(highestOneIndexRow);
    ans.push_back(maxOneCount);

    return ans;
}

int main() {
    vector <vector<int>> v = {{0, 0, 0}, {0, 1, 1}};
    vector <int> ans;

    ans = rowAndMaximumOnes(v);
    printVector(ans);

    return 0;
}