// GFG: Segregate 0s and 1s   --->   Given an array arr consisting of only 0's and 1's in random order.
// Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

// Example 1:
// Input: arr[] = [0, 0, 1, 1, 0]
// Output: [0, 0, 0, 1, 1]
// Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].

// Example 2:
// Input: arr[] = [1, 1, 1, 1]
// Output: [1, 1, 1, 1]
// Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(2n)
    // S.C: O(1)
    void segregate0and1_bruteForce(vector<int> &arr) {
        int zeroCount = 0, oneCount = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) zeroCount++;
            else oneCount++;
        }

        // Inserting 0s and 1s on indexes
        int index = 0;
        while(zeroCount--) {
            arr[index] =  0;
            index++;
        }
        while(oneCount--) {
            arr[index] =  1;
            index++;
        }
    }

// ----------------------------------------------------------

    // Algorithm (Two pointer approach):
    // 1. Initialize low and high on 0 and n-1 index respectively.
    // 2. Maintain the rule that all left elements till low should be 0, all right elements till high should be 1.
    //    Thus, if(arr[low] == 0), move the low pointer ahead towards right, to check the position of next element.
    //    Similarly, if(arr[high] == 1), move the high pointer back towatds left, to check the position of next element.
    //    If both pointers point to wrong elements, swap the elements. Continue the proecess until low reaches high.
    // T.C: O(n)
    // S.C: O(1)
    void segregate0and1(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        while(low < high) {
            if(arr[low] == 0) low++;
            else if(arr[high] == 1) high--;
            else {
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }
    }
};


int main() {
    vector<int> arr = {0, 0, 1, 1, 0};

    // Solution().segregate0and1_bruteForce(arr);
    Solution().segregate0and1(arr);

    for(auto it: arr) cout << it << " ";

    return 0;
}
