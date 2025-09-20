// Leetcode 1392. Longest Happy Prefix   --->   A string is called a happy prefix if is a non-empty prefix which
// is also a suffix (excluding itself).
// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

// Example 1:
// Input: s = "level"
// Output: "l"
// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel").
// The largest prefix which is also suffix is given by "l".

// Example 2:
// Input: s = "ababab"
// Output: "abab"
// Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

// INFO: Practically, the longest prefix suffix is awlays the full length of given string itself. To create
//       a meaningful problem, the second longest prefix suffix has to be found out. That's why in casual
//       language, the second longest prefix suffix is considered as the longest prefix suffix.
//       Longest prefix suffix means the longest suffix that ends at exactly the 'i'th character ('i'th
//       character being included) which is also a prefix.
//          Example: s = a b a b a b
//               index = 0 1 2 3 4 5
//               lps[] = 0 0 1 2 3 4
//          lps[4] = 3, which means that longest suffix that ends at exactly 4th index of s, which is also a
//          prefix, is of length 3. If it is of length 3, the longest prefix suffix can be obtained by either
//          taking 3 characters towards left of 's' starting from 4th index, or the 3 characters towards right
//          of 's' starting from 0th index. And the outcome will come out to be "aba".

// Algorithm: It is based on Knuth-Morris-Pratt algorithm, popularly know as KMP algorithm. It is a hard
//            algorithm to understand without proper dry run. Steps are not intuitive, only observations
//            on dry run can help to build the solution.
// 1. Create an array lps[] of size n, where n = length of given string 's', and lps[i] indicates the length of
//    longest prefix suffix that ends exactly at the 'i'th character of 's'.
// 2. As the string itself cannot have any longest prefix suffix (LPS), the minimum length of string to have
//    a LPS is 2. Thus, we can safely initialize 'prefix' pointer at index 0, and 'suffix' pointer at index 1.
//    The 'prefix' pointer marks the end index of current prefix starting from 0th index, and 'suffix' pointer
//    marks the end index of current suffix starting from (suffix - length of LPS + 1)th index of string 's'.
// 3. Now, we will iterate the string 's' using 'suffix' pointer, and compare the characters at 'prefix' and
//    'suffix' pointer.
//    CASE I:  If they match, it means a matching character is found 'prefix'th index and 'suffix'th index of 's'.
//             In this case, the length of LPS that ends at 'suffix'th index will be prefix + 1. You may observe
//             this by dry running on any example. Thus, update lps[suffix] = prefix + 1, and increment both
//             'prefix' and 'suffix' pointer by 1 to check for next characters.
//    CASE II: If they don't match, then there can be two cases:
//             i.  If 'prefix' is at 0th index: It means no matching character is found till now, thus
//                 lps[suffix] = 0, and increment 'suffix' by 1 to check for next character.
//             ii. If 'prefix' is not at 0th index: It means some matching characters were found previously,
//                 and now a mismatch is found. Thus, we will not increment 'suffix' pointer, but will
//                 update 'prefix' pointer to lps[prefix - 1], which means we will try to find a smaller
//                 prefix which ends at exactly lps[prefix - 1]th index, which may match with the suffix
//                 ending at 'suffix'th index.
//                 ● Why prefix shifts back to lps[prefix - 1] ?
//                   Because, if a smaller prefix is found which ends at lps[prefix - 1]th index, then
//                   there are chances that it may match with the suffix ending at 'suffix'th index.
//                   Example: s = a b a b a b c
//                        index = 0 1 2 3 4 5 6
//                        lps[] = 0 0 1 2 3 4 0
//                   Here, at index 6, a mismatch is found. Now, the 'prefix' pointer is at index 4,
//                   and 'suffix' pointer is at index 6. Now, if we shift 'prefix' pointer to lps[4 - 1] = lps[3],
//                   i.e., at index 2, then there are chances that the character at index 2 may match with the
//                   character at index 6. And if they match, then lps[6] = 2 + 1 = 3; else, if they don't match,
//                   then we will again check for smaller prefix by shifting 'prefix' to lps[2 - 1] = lps[1],
//                   i.e., at index 0. And if they match, then lps[6] = 0 + 1 = 1; else, if they don't match,
//                   then lps[6] = 0, and increment 'suffix' by 1 to check for next character.
// 4. Finally, after the iteration is over, lps[n - 1] will give the length of longest prefix suffix for the
//    string 's' of length 'n'. Thus, return s.substr(0, lps[n - 1]) as the longest happy prefix of 's'.

// Video link: https://www.youtube.com/watch?v=sODA1BzFvsE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);   // longest prefix-suffix array

        int prefix = 0;
        int suffix = 1;

        while(suffix < n) {
            if(s[prefix] == s[suffix]) {
                lps[suffix] = prefix + 1;
                prefix++;
                suffix++;
            } else {
                if(prefix == 0) {
                    lps[suffix] = 0;
                    suffix++;
                } else {   // if(prefix != 0)
                    prefix = lps[prefix - 1];
                }
            }
        }

        return s.substr(0, lps[n - 1]);   // longest prefix-suffix
    }
};

int main() {
    string s = "ababab";

    cout << Solution().longestPrefix(s);

    return 0;
}
