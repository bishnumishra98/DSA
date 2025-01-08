// Leetcode: 658. Find K Closest Elements   --->   Given a sorted integer array arr, two integers k and x, return
// the k closest integers to x in the array. The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:
// • |a - x| < |b - x|, or
// • |a - x| == |b - x| and a < b
 
// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// Input: arr = [1,1,2,3,4,5], k = 4, x = -1
// Output: [1,1,2,3]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Algorithm: It is very simple two pointer approach.
    // 1. Initialize low and high on 0 and n - 1, respectively. As array is sorted and x lies between low and high,
    //    the distance of ith elements towards left of x from x is 'x - arr[i]'. Similarly, distance of ith elements
    //    towards right of x from x is 'arr[i] - x'. The aim of low and high pointers is to indicate a range of
    //    'k' elements which are closest to x.
    // 2. There can be 3 cases for moving low and high pointers:
    //    Case 1: arr[low] is nearer to x than arr[high]:
    //            If 'x - arr[low] < arr[high] - x', move high towards left to find a shorter distance of arr[high] from x.
    //    Case 2: arr[low] and arr[high] are equidistant from x:
    //            If 'x - arr[low] == arr[high] - x', still move high towards left to find a shorter distance of arr[high] from x,
    //            because its given that in case of a tie, choose the smaller element, and smaller elements are pointer by low.
    //    Case 3: arr[low] is more distant to x than arr[high]:
    //            If 'x - arr[low] > arr[high] - x', move low towards right to find a shorter distance of arr[low] from x.
    //    Continue the process until no.of elements left between low and high are exactly k, i.e., while(high - low >= k) {}.

    // T.C: O(n - k)
    // S.C: O(k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - 1;

        while(high - low >= k) {
            if(x - arr[low] <= arr[high] - x) high--;
            else low++;   // if(x - arr[low] > arr[high] - x)
        }

        vector<int> ans;
        for(int i = low; i <= high; i++) ans.push_back(arr[i]);
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> ans = Solution().findClosestElements(arr, k, x);
    for(auto it: ans) cout << it << " ";

    return 0;
}
