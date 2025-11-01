// Leetcode: 131. Palindrome Partitioning   --->   Given a string s, partition s such that every substring of the
// partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// Input: s = "a"
// Output: [["a"]]

// Example 3:
// Input: s = "aabb"
// Output: [["a","a","b", "b"], ["a","a", "bb"], ["aa", "b", "b"], ["aa"], "bb"]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // isPalindrome() checks whether the substring of string 's' from index 'start' to 'end is a palindrome or not
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    // solve() function builds partitions temporarily in helper data structure 'ds' and pushes them inside 'ans'
    void solve(int index, string s, vector<string>& ds, vector<vector<string>>& ans) {
        // Base case: If index reaches beyond the last character of string 's', the required
        // palindrome vector is built inside 'ds'. Thus, push it inside 'ans'.
        if(index == s.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));   // push the palindrome from index 'index' to 'i' of 's' inside 'ds'
                solve(i + 1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

    // T.C: O(2^n * n)
    // S.C: O(2^n * n)
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, s, ds, ans);
        return ans;
    }
};

int main() {
    string s = "aabb";

    Solution sol;
    vector<vector<string>> ans = sol.partition(s);
    for(vector<string> i: ans) {
        for(string j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
