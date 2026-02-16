#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper to expand from a center with one allowed skip
    int getMaxFromCenter(const string& s, int l, int r) {
        int n = s.length();
        
        // 1. Expand normally until mismatch or boundary
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--; r++;
        }

        // Current core length (could be 0 if s[l] != s[r] immediately)
        int coreL = l, coreR = r;
        int res = r - l - 1;

        // 2. Try skipping the LEFT character s[l]
        if (l >= 0) {
            int tl = l - 1, tr = r;
            while (tl >= 0 && tr < n && s[tl] == s[tr]) {
                tl--; tr++;
            }
            // Length is (tr - tl - 1). This includes the 'skipped' char s[l]
            res = max(res, tr - tl - 1);
        }

        // 3. Try skipping the RIGHT character s[r]
        if (r < n) {
            int tl = coreL, tr = r + 1;
            while (tl >= 0 && tr < n && s[tl] == s[tr]) {
                tl--; tr++;
            }
            // Length is (tr - tl - 1). This includes the 'skipped' char s[r]
            res = max(res, tr - tl - 1);
        }

        return res;
    }

    int almostPalindromic(string s) {
        int n = s.length();
        if (n <= 1) return n;

        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            // Odd center (e.g., aba)
            maxLen = max(maxLen, getMaxFromCenter(s, i, i));
            // Even center (e.g., abba)
            maxLen = max(maxLen, getMaxFromCenter(s, i, i + 1));
        }
        return maxLen;
    }
};


int main() {
    string s1 = "abca";
    cout << Solution().almostPalindromic(s1) << endl; // 4

    string s2 = "abba";
    cout << Solution().almostPalindromic(s2) << endl; // 4

    string s3 = "zzabba";
    cout << Solution().almostPalindromic(s3) << endl; // 5

    string s4 = "aaaba";
    cout << Solution().almostPalindromic(s3) << endl; // 5

    return 0;
}
