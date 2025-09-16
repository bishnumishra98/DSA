// Leetcode: 345. Reverse Vowels of a String   --->   Given a string s, reverse only all the vowels in the string
// and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:
// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAVowel(char c) {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

public:
    // T.C: O(n);   where n = s.length()
    // S.C: O(1)
    string reverseVowels(string s) {
        string res = s;
        int left = 0, right = s.length() - 1;
        
        while(left < right) {
            // If character at s[left] or s[right] is not a vowel, skip it.
            if(!isAVowel(s[left])) {
                left++;
                continue;
            }
            if(!isAVowel(s[right])) {
                right--;
                continue;
            }
            swap(res[left], res[right]);
            left++;
            right--;
        }

        return res;
    }
};

int main() {
    string s = "IceCreAm";

    cout << Solution().reverseVowels(s);

    return 0;
}
