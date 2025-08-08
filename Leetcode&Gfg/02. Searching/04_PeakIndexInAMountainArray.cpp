// Leetcode: 852. Peak Index in a Mountain Array   --->   You are given an integer mountain array arr of length n
// where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

// Algorithm:
// The algorithm is simple. The array has a peak, thus it has two slopes on both sides. Let the left side slope be
// called slope A, and the right side slope be called slope B.
// 1. As usual, initialize start = 0, mid = (start + end) / 2, end = n - 1, where n = arr.size(), and compare arr[mid]:
// 2. While start is less than end, check for two cases:
//    Case 1: If arr[mid] is on slope A, i.e., arr[mid] < arr[mid + 1]:
//            If we are on slope A, the peak is somewhere on the right. Thus, shift rightwards, i.e., start = mid + 1.
//    Case 2: If arr[mid] is on slope B, i.e., arr[mid] > arr[mid + 1]:
//            If we are on slope B, the peak is somewhere on the left or arr[mid] coud itslef be the peak element.
//            Hence, while shifting leftwards, never do 'end = mid - 1'. Instead, do 'end = mid'.
// 3. When the loop (start < end) terminates, all pointers start, mid and end point to the peak element's index.
//    So return any one of them.
// MOST IMPORTANT POINT OF THIS ALGORITHM: Note that the while loop must end as soon as start reaches end. Thus,
// never write 'while(start <= end)' in this problem as it will cause a huge blunder. Lets say if we allowed the
// last iteration to happen when start == end, then by this time, all the 3 pointers (start, mid and end) would
// already reach the peak elements index. So, the condition if(arr[mid] < arr[mid + 1]) would be false, and
// the program would execute else block which states that end = mid. So technically, there is no change in
// positions of start and end, which would cause our program to indefinitely always execute else block,
// resulting in an infinite loop. To avoid this error, always write 'while(start < end)'.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(logn)
    // S.C: O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start)/2;

        while(start < end) {   // never write while(start <= end) {}
            if(arr[mid] < arr[mid + 1]) start = mid + 1;
            else end = mid;   // if(arr[mid] >= arr[mid + 1])
            mid = start + (end - start) / 2;
        }

        return start;   // we can even return end or mid
    }
};

int main() {
    vector <int> v = {0, 2, 3, 4, 1, 0};
    cout << Solution().peakIndexInMountainArray(v);

    return 0;
}
