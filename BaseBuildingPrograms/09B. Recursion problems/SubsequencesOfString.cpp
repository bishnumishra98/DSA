// For a string containing 'n' characters, there can be 2^n subsequences of it.
// Note that sequence of characters shouldn't be altered while making subsequences.
// Example: abc -> {" ", "a", "b", "c", "ab", "ac", "bc", "abc"}

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(2^n);   where 'n' is the length of the input string 'str'
// S.c: O(n);   where 'n' is the length of the input string 'str'
void findSubSequences(string str, string output, int index, vector<string>& ans) {
    // base case
    if(index >= str.length()) {
        // if index>=str.length, then one of the subsequences is built inside 'output'
        ans.push_back(output);
        return;
    }

    // processing
    char ch = str[index];

    // Case 1: Excluding the character 'ch' in 'output' building
    findSubSequences(str, output, index+1, ans);   // recursive relation

    // Case 2: Including the character 'ch' in 'output' building
    output.push_back(ch);
    findSubSequences(str, output, index+1, ans);   // recursive relation
}

int main() {
    string str = "abc";
    string output = "";
    int index = 0;
    vector <string> ans;

    findSubSequences(str, output, index, ans);

    for(string s: ans) {
        cout << s << " ";
    }

    return 0;
}