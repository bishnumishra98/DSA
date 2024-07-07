// Leetcode: 131. Palindrome Partitioning   --->   Given a string s, partition s such that every substring of the
// partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// Input: s = "a"
// Output: [["a"]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(int index, string s, vector<string>& path, vector<vector<string>>& ans) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                solve(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    // T.C: 
    // S.C: 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, path, ans);
        return ans;
    }
};

int main() {
    string s = "aab";

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
