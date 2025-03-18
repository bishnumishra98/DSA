// GFG: Assign Cookies   --->   Assume you are an awesome parent of some children and want to give your children
// some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor greed[i], which is the minimum size of cookie that the child will be content with
// and each cookie j has a size cookie[j]. If cookie[j] >= greed[i], we can assign the cookie j to the child ith, and
// the child i will be content.
// Find the maximum number of child that can be content.

// Example 1:
// Input : greed[] = [1, 2, 3], cookie = [1, 1]
// Output: 1
// Explanation: You can only assign cookie 0 or 1 to child 0.

// Example 2:
// Input : greed[] = [1, 2], cookie = [1, 2, 3]
// Output: 2
// Explanation: You can assign cookie 0 to child 0 and cookie 1 to child 1.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // Your Code goes here.
    }
};

int main() {
    vector<int> greed = {1, 2, 3};
    vector<int> cookie = {1, 1};

    Solution obj;
    cout << obj.maxChildren(greed, cookie);

    return 0;
}
