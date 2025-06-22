// Leetcode: 115. Distinct Subsequences   --->   Given two strings s and t, return the number of distinct
// subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// .... .. dot represents which characters are being considered in building the string

// rabbbit
// .. ....

// rabbbit
// ... ...

// Example 2:
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// .. .   

// babgbag
// ..    .

// babgbag
// .    ..

// babgbag
//   .  ..

// babgbag
//     ...

// Algorithm:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        
    }
};

int main() {
    string s = "rabbbit", t = "rabbit";

    cout << Solution().numDistinct(s, t);

    return 0;
}
