// GFG: Assign Cookies   --->   You are given an array greed[], where greed[i] represents the minimum size of cookie
// required to satisfy the i-th child, and an array cookie[], where cookie[j] represents the size of the j-th cookie.
// Each child can receive at most one cookie. A child i will be satisfied if they receive a cookie j such that
// cookie[j] >= greed[i]. Your task is to determine the maximum number of children that can be satisfied.

// Example 1:
// Input : greed[] = [1, 10, 3], cookie = [1, 2, 3]
// Output: 2
// Explanation: We can only assign cookie to the first and third child.

// Example 2:
// Input : greed[] = [10, 100], cookie = [1, 2]
// Output: 0
// Explanation: We can not assign cookies to any child.

// Problem link: https://www.geeksforgeeks.org/problems/assign-cookies/0

// Algorithm: It is a very simple and easy greedy approach.
// 1. Sort the greed and cookie arrays.
// 2. Initialize two pointers i and j to each of the arrays, initially pointing at index 0.
// 3. Traverse the arrays until either of the arrays is exhausted.
//    i.  If greed of ith child is less than or equal to the cookie of jth size, then increment i.
//    ii. Increment j in each iteration.
// 4. Return the value of i, which is the maximum number of children that can be content.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn + mlogm + min(n, m))
    // S.C: O(1)
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        int n = greed.size(), m = cookie.size();
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());

        int i = 0, j = 0;
        while(i < n && j < m) {
            if(greed[i] <= cookie[j]) {
                i++;
            }
            j++;
        }

        return i;
    }
};

int main() {
    vector<int> greed = {1, 2, 3};
    vector<int> cookie = {1, 1};

    Solution obj;
    cout << obj.maxChildren(greed, cookie);

    return 0;
}
