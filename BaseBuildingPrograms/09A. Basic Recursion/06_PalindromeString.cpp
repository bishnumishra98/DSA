#include <iostream>
using namespace std;

// T.C: O(n/2);   where n = str.size()
// S.C: O(n/2)
bool isPalindrome_twoPointer(string& str, int i, int j) {
    if(i >= j) return true;   // Base case: When i reaches j, return true
    if(str[i] != str[j]) return false;
    isPalindrome_twoPointer(str, i+1, j-1);
}

// T.C: O(n/2)
// S.C: O(n/2)
bool isPalindrome_onePointer(string& str, int i) {
    if(i >= str.size()/2) return true;   // Base case: When i reaches str.size()/2, return true
    if(str[i] != str[str.size()-i-1]) return false;
    isPalindrome_onePointer(str, i+1);
}

int main() {
    string str = "racecar";
    int i = 0;
    int j = str.size() - 1;

    cout << isPalindrome_twoPointer(str, i, j) << endl;
    cout << isPalindrome_onePointer(str, i) << endl;

    return 0;
}
