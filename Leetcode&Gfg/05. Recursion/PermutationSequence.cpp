// Leetcode: 60. Permutation Sequence   --->   The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

// Example 3:
// Input: n = 3, k = 1
// Output: "123"

// Brute force:
// 1. Create a vector from 1 to n.
// 2. Write a function that returns all permutations of a vector. Refer: 'BaseBuildingPrograms\09. Recursion_I\13_AllPermutationsOfArray.cpp'
// 3. Follow up this code:

// string convertIntVectorToString(vector<int> v) {
//     string s = "";
//     for(int i=0; i<v.size(); i++) {
//         s = s + to_string(v[i]);
//     }
//     return s;
// }

// T.C: O((n!*n)log(n!*n))
// string getPermutation(int n, int k) {
//     vector<int> candidates;
//     for(int i=1; i<=n; i++) {
//         candidates.push_back(i);
//     }
    
//     vector<vector<int>> ans = findPermutations(candidates);
//     sort(ans.begin(), ans.end());

//     vector<int> v = ans[k-1];
//     string s = convertIntVectorToString(v);
//     return s;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    string getPermutation(int n, int k) {
        
    }
};

int main() {
    int n = 3, k = 3;
    Solution sol;
    cout << sol.getPermutation(n, k);

    return 0;
}
