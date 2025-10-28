// Leetcode: 17. Letter Combinations of a Phone Number   --->   Given a string containing digits
// from 2-9 inclusive, return all possible letter combinations that the number could represent.
// Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that
// 1 does not map to any letters.

// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = ""
// Output: []

// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"]

// Problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombination(int index, vector<string>& ans, string ds, vector<string>& mapping, string digits) {
        // Base case: When index reaches beyond the last element of digits, store the answer made in 'ds' and return
        if(index == digits.size()) {
            ans.push_back(ds);
            return;
        }

        int mapIndex = digits[index] - '0';   // if digits[index] is '2'(char), we will get 2(int) in mapIndex.
        string s = mapping[mapIndex];   // s will store "abc" as mapping[2] contains "abc".

        // Iterating over each element of string 's' and making recursive calls to find further combinations
        for(int i = 0; i < s.length(); i++) {
            ds.push_back(s[i]);
            findCombination(index + 1, ans, ds, mapping, digits);
            ds.pop_back();   // Backtrack
        }
    }

    // T.C: O(n * 4^n);   where n = digits.length()
    //                    For each digit, there are 3 or 4 possible letters. In the worst case, each digit could map
    //                    to 4 letters. The total number of combinations is the product of the number of letters for
    //                    each digit. For n digits, the worst-case scenario is 4^n combinations. Constructing each
    //                    combination involves concatenating characters, which takes O(n) time because each combination
    //                    is of length n. Therefore, the total time complexity is the number of combinations multiplied
    //                    by the time to construct each combination: O(n * 4^n)
    // S.C: O(n * 4^n)    The depth of the recursion is equal to the number of digits n, leading to a space complexity
    //                    of O(n) for the recursion stack. Each combination is stored in a vector. There are
    //                    4^n combinations, and each combination is of length n. Therefore, the space required to store
    //                    the combinations is O(n * 4^n).
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;   // for empty string input, return blank vector of strings
        string ds;   // will be used as helper data structure to store temporary answers
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        findCombination(0, ans, ds, mapping, digits);
        return ans;
    }
};

int main() {
    string digits = "23";

    Solution sol;
    vector<string> ans = sol.letterCombinations(digits);
    for(string s: ans) {
        cout << s << " ";
    }

    return 0;
}
