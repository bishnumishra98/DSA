// GFG: Longest String Chain   --->   You are given an array of words where each word consists of lowercase
// English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without
// changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor
// of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor
// of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k = 1.
// Return the length of the longest possible word chain with words chosen from the given list of words in any order.

// Example 1:
// Input: words[] = ["ba", "b", "a", "bca", "bda", "bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a", "ba", "bda", "bdca"].

// Example 2:
// Input: words[] = ["abc", "a", "ab"]
// Output: 3
// Explanation: The longest chain is {"a", "ab" "abc"}

// Example 3:
// Input: words[] = ["abcd", "dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.

// Constraint:
// 1 <= words.length <= 10^4
// 1 <= words[i].length <= 10
// words[i] only consists of lowercase English letters.

// Algorithm: Again a simple variation of 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_FindLongestIncreasingSubsequence.cpp'.
//            You just have to perform the same two changes on the LIS problem, as you did in 'Leetcode&Gfg\13. Dynamic_Programming\44_LargestDivisibleSubset.cpp'.
// 1. Sort the given array of strings according their lengths.
// 2. Follow the same code as you wrote for LIS, just instead of checking if(nums[i] > nums[j]), check
//    if(checkPossibile(words[i], words[j])), where checkPossible returns a true if 'word[i]' can be made by adding
//    just one character anywhere in 'word[j]', otherwise returns false.

// ● Working of checkPossibile(s1, s2):
//   1. As we know that words is sorted, so length of s1 will always be longer than or equal to s2. We are looking
//      for if a character can be added anywhere to word[j] to make it word[i]. Thus, if s1.length() is not 1 more
//      than s2.length(), return false stating that s2 cannot be a predecessor of s1.
//   2. Initialize two pointers 'i' and 'j' on each of the words 's1' and 's2' respectively. As s1 is 1 greater in
//      length than s2, run a while loop until 'i' goes beyond s1.length():
//      I.  if(s1[i] == s2[j]): If characters pointer by 'i' on s1 and 'j' on s2 matches, then move ahead both the
//                              pointers to compare the next character.
//      II. if(s1[i] != s2[j]): If characters pointer by 'i' on s1 and 'j' on s2 matches, then move ahead the 'i'
//                              pointer and keep the 'j' pointer at its place for next comparison.
//      At the end of the while loop, 'i' will anyhow reach beyond the last index of s1 as it's getting increment
//      in either of the cases. But if 'j' also reached beyond the last index of s2, it means s2 is a valid
//      predecessor of s1. Thus, return true.
//      True will be returned in cases: {s1 = "abcd", s2 = "abc"}, {s1 = "abcd", s2 = "abd"}, etc.
//      If 'j' did not reach beyond the last index of s2, it means you cannot just add 1 character to s2 and make
//      it s1. Thus s2 is not a predecessor of s1. Thus, return false.
//      False will be returned in cases: {s1 = "abcd", s2 = "bac"}, {s1 = "abcd", s2 = "abe"}, etc.

// ● Intuition behind sorting the array and applying LIS logic:
//   One thing we know is that problem is asking for subset, not subsequence; hence order of words doesn't matters.
//   Thus, we can sort the given input array in creasing order of lengths, so that the next word is always greater
//   than or equal to the previous word in length.
//   This will help in identifying the if words[j] is a predecessor words[i] in a straightforward manner, where 'j'
//   are the indexes of the elements on the left of 'i'.
//   Now in LIS problem, we were finding the longest increasing subsequence on the condition that nums[i] > nums[j].
//   We can do the same here to find longest string chain (LCS). Find the longest increasing subsequence on the
//   sorted words array on the condition that words[j] is a predecessor words[i] using a separate function
//   lets say named 'checkPossible()'.
//   Hence here, an element of dp array, dp[i] will tell the length of longest string chain till the index 'i'
//   of 'words'. And the hash array as usual will tell the parent of a word, which will be later useful in backtracking
//   and building up the LCS. Example:- If hash[3] = 1, it means the word at index 3 of 'words' was computed from
//   word at index 1 of 'words'.
//   Thus, follow the same code as you wrote for LIS, just instead of checking if(nums[i] > nums[j]), check
//   if(checkPossible(words[i], words[j])).

// ● Illustration:
//   Input Words arr =  ["ba", "b", "a", "bca", "bda", "bdca"]
//   Sorted words arr = ["b", "a", "ba", "bca", "bda", "bdca"]
//   dp array =         [ 1,   1,   2,    3,     3,     4 ]   // initially all words are initialized to 1 as they are LCS in themselves
//   hash array =       [ 0,   1,   0,    2,     2,     3 ]   // those who did not came from anywhere are parent of themselves
//   LCS =              ["b", "ba", "bca", "bdca"]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if s2 is a predecessor of s1
    bool checkPossible(string& s1, string& s2) {
        if(s1.length() != s2.length() + 1) return false;

        int i = 0;
        int j = 0;
        while(i < s1.length()) {
            if(j < s2.length() && s1[i] == s2[j]) {   // additional 'j < s2.length()' condition for a valid s2 index
                i++;
                j++;
            } else {
                i++;
            }
        }

        if(j == s2.length()) return true;
        return false;
    }

    // T.C: O(n^2)
    // S.C: O(n)
    int longestStringChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        
        // CHANGE 1 (it is actually an addition on the LIS code): Sort the words array based on length of words
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.length() < s2.length();
        });

        int maxi = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(checkPossible(words[i], words[j])) {   // CHANGE 2 (previously it was 'if(words[i] > words[j])' in LIS code)
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                    }
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }

        return maxi;
    }

// ---------------------------------------------------------------------------------------------------

    // Just a followup problem. If asked to print the elements of the Longest String Chain :-   
    // T.C: O(n^2)
    // S.C: O(n)
    vector<string> longestStringChain_elements(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        
        // CHANGE 1 (it is actually an addition on the LIS code): Sort the words array based on length of words
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.length() < s2.length();
        });

        vector<int> hash(n);
        for(int i = 0; i < n; i++) hash[i] = i;

        int maxi = 1;
        int lastIndex = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(checkPossible(words[i], words[j])) {   // CHANGE 2 (previously it was 'if(words[i] > words[j])' in LIS code)
                    if(1 + dp[j] > dp[i]) {
                        hash[i] = j;
                        dp[i] = 1 + dp[j];
                    }
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Starting from element of 'words' at index of the largest dp element, start backtracking and build the LDS in 'ans'.
        vector<string> ans;
        ans.push_back(words[lastIndex]);

        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(words[lastIndex]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    vector<string> words = {"ba", "b", "a", "bca", "bda", "bdca"};

    cout << Solution().longestStringChain(words) << endl;

    vector<string> lcs = Solution().longestStringChain_elements(words);
    for(auto it: lcs) cout << it << " ";

    return 0;
}
