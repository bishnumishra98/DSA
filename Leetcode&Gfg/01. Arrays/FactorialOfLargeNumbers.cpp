// GFG: Given an integer N, find its factorial. Return a list of integers denoting the digits that make up the factorial of N.

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

// Problem link: https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// Algorithm: Understand this problem first to get the intuition 'AddTwoNumbersRepresentedByTwoArrays.cpp'.
// The algorithm for factorial i.e., multiplication will be similar to that of addition.
// We will build answer in a vector in reverse order. Thus, reverse the vector and return the answer.
// Dry run the algorithm for better understanding.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(N^2 * logN);   outer loop runs from 2 to N i.e., O(N) iterations. In the inner loop, for each iteration of i,
    //      we multiply the current factorial result stored in ans which can have up to d digits. In general, the number of
    //      digits in the factorial of N grows approximately as O(log(N!)). Uisng Stirling's approximation, log(N!) is
    //      approximately O(N * logN), meaning the no. of digits in N! is roughly N * logN. Combining these factors, the 
    //      overall time complexity is: O(N * N * logN) = O(N^2 * logN)
    // S.C: O(N * logN);   due to no.of digits stored in 'ans' using Stirling's approximation.
    vector<int> factorial(int N) {
        // Initialize a vector to store the digits of the factorial. Starting with 1 because factorial of 1 is 1.
        vector<int> ans;
        ans.push_back(1);

        int carry = 0;
        // Loop from 2 to N to calculate N!
        for(int i = 2; i <= N; i++) {
            // Multiply each digit in 'ans' by i
            for(int j = 0; j < ans.size(); j++) {
                int product = ans[j] * i + carry;   // multiply current digit by i and add carry
                ans[j] = product % 10;   // store the last digit of the product in 'ans' 
                carry = product / 10;   // Update carry with the rest of the product
            }
            // If carry remains after multiplying all digits, add it to the 'ans' vector
            while(carry) { 
                ans.push_back(carry % 10);   // insert the last digit of the carry
                carry = carry / 10;   // update carry with the remaining part
            }
        }

        // The digits in 'ans' are stored in reverse order, so reverse the vector to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int N = 50;
    vector<int> ans = Solution().factorial(N);
    for(auto it: ans) cout << it;

    return 0;
}
