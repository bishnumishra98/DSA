// Exact same problem as previous one. Just difference being, here string is present instead of array.
// PATTERN: PICK/NOT PICK

// For a string containing 'n' characters, there can be 2^n subsequences of it.
// Note that sequence of characters shouldn't be altered while making subsequences.
// Example: abc -> {" ", "a", "b", "c", "ab", "ac", "bc", "abc"}

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(2^n);   where 'n' is the length of the input string 'str'
// S.c: O(n);   where 'n' is the length of the input string 'str'
void findSubsequences(string str, vector<string>& ans, string ds, int index) {
    // Base case: If we reach beyond the last element of 'str', the Subsequence is already built in 'ds'. Push it in 'ans'.
    if(index == str.length()) {
        ans.push_back(ds);
        return;
    }

    char ch = str[index];

    // Case 1: Including the character 'ch' in 'ds' building
    ds.push_back(ch);
    findSubsequences(str, ans, ds, index+1);
    ds.pop_back();   // Backtrack

    // Case 2: Excluding the character 'ch' in 'ds' building
    findSubsequences(str, ans, ds, index+1);
}

int main() {
    string str = "abc";
    string ds = "";
    vector <string> ans;

    findSubsequences(str, ans, ds, 0);

    for(string s: ans) {
        cout << s << endl;
    }

    return 0;
}
