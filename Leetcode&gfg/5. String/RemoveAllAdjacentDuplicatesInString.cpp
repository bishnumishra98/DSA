// Leetcode: 1047. Remove All Adjacent Duplicates In String. Ex:-
// (1) i/p: "abbaca",   o/p: "ca"           (2) i/p: "azxxzy",   o/p: "ay"


#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n) 
string removeDuplicates(string s) {
    string ans = "";
    int index = 0;
    
    while(index < s.size()) {
        int n = ans.size();

        // if rightmost element in 'ans' is equal to s[index], then pop out rightmost element
       // from 'ans'; else push s[index] as rightmost element in 'ans'
        if((n-1 >= 0) && (ans[n-1] == s[index])) {
            ans.pop_back();
        } else {
            ans.push_back(s[index]);
        }

        index++;
    }

    return ans;
}

int main() {
    string str = "abbaca";
    cout << removeDuplicates(str);

    return 0;
}