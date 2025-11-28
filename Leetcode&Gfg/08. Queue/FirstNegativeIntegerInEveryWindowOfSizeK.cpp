// GFG: Given an array arr[]  and a positive integer k, find the first negative integer for each and every
// window(contiguous subarray) of size k.
// Note: If a window does not contain a negative integer, then return 0 for that window.

// Example 1:
// Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
// Output: [-8, 0, -6, -6]
// Explanation:
// Window [-8, 2] First negative integer is -8.
// Window [2, 3] No negative integers, output is 0.
// Window [3, -6] First negative integer is -6.
// Window [-6, 10] First negative integer is -6.

// Example 2:
// Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
// Output: [-1, -1, -7, -15, -15, 0] 
// Explanation:
// Window [12, -1, -7] First negative integer is -1.
// Window [-1, -7, 8] First negative integer is -1.
// Window [-7, 8, -15] First negative integer is -7.
// Window [8, -15, 30] First negative integer is -15.
// Window [-15, 30, 16] First negative integer is -15.
// Window [30, 16, 28] No negative integers, output is 0.

// Example 3:
// Input: arr[] = [12, 1, 3, 5] , k = 3
// Output: [0, 0] 
// Explanation:
// Window [12, 1, 3] No negative integers, output is 0.
// Window [1, 3, 5] No negative integers, output is 0.

// Problem link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// Bruteforce Algorithm:
// For each window, scan k elements to find the first negative and push the first negative in the 'ans' vector.

// Optimal algorithm:


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // T.C: O(n * k)
    // S.C: O(n - k + 1)
    vector<int> firstNegInt_bruteforce(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        for(int i = 0; i <= n - k; i++) {
            int firstNeg = 0;   // let first negative be 0 initially

            // Scan k elements of the window and store the first negative element in 'firstNeg'
            for(int j = i; j < i + k; j++) {
                if(arr[j] < 0) {
                    firstNeg = arr[j];
                    break;
                } 
            }
            ans.push_back(firstNeg);   // push the first negtaive element in 'ans'
        }

        return ans;
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n - k + 1)
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        queue<int> q;   // will store the indexes of negative numbers

        // Step 1: Store the index of the first negative element of the first window, i.e., of the first k elements
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) q.push(i);
        }

        // Add answer for the first window
        if(!q.empty()) ans.push_back(arr[q.front()]);
        else ans.push_back(0);

        // Step 2: Slide the window from i = k to n - 1
        for(int i = k; i < n; i++) {
            // Remove the element that is out of this window (front of queue should be inside window)
            if(!q.empty() && q.front() == i - k) q.pop();

            // Add new element's index in queue if it is negative
            if(arr[i] < 0) q.push(i);

            // Add the first negative number of current window
            if(!q.empty()) ans.push_back(arr[q.front()]);
            else ans.push_back(0);
        }

        return ans;
    }
};


int main() {
    vector<int> arr = {-5, -6, -7, 10, 11};
    int k = 1;

    vector<int> ans1 = Solution().firstNegInt_bruteforce(arr, k);
    for(auto it: ans1) {
        cout << it << " ";
    }
    cout << endl;
    vector<int> ans2 = Solution().firstNegInt(arr, k);
    for(auto it: ans2) {
        cout << it << " ";
    }

    return 0;
}
