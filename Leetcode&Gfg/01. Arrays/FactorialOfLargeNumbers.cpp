// GFG: Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

// Example 1:
// Input: N = 5
// Output: [1,2,0]
// Explanation : 5! = 1*2*3*4*5 = 120

// Example 2:
// Input: N = 10
// Output: [3,6,2,8,8,0,0]
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

// Your Task:
// You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter
// and returns a list of integers denoting the digits that make up the factorial of N.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    vector<int> factorial(int N){
        
    }
};

int main() {
    int N = 20;
    vector<int> ans = Solution().factorial(N);
    for(auto it: ans) cout << it << " ";

    return 0;
}
