// This problem is an implementation of binary search

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int findPivotIndex(vector<int>& nums) {
    int n =  nums.size();
    int start = 0, end = n - 1, mid = start + (end - start)/2;

    while(start <= end) {
        if(start == end) {
            // if only 1 element is present in the array, then it itself is the pivot element
            return start;
        }

        if((mid+1 < n) && (nums[mid] > nums[mid+1])) {   // if mid is on element 70, i.e.
               // pivot element itself. '(mid+1 < n)' ensures we do not move out of index.
              // Make sure to write the condition '(mid+1 < n)' as first operand of &&, or else some compilers may throw compile error.
            return mid;
        } else if((mid-1 >= 0) && (nums[mid] < nums[mid-1])) {   // if mid is on element 10, i.e.
          // element just after pivot element. '(mid-1 >= 0)' ensures we do not move out of index.
         // Make sure to write the condition '(mid-1 >= 0)' as first operand of &&, or else some compilers may throw compile error.
            return mid-1;
        } else if(nums[mid] < nums[start]) {   // if mid is on line B, i.e. shorter ascending slope.
                                              // In this case, move to left.
            end = mid - 1;
        } else {   // if(nums[mid] > nums[start]), i.e. mid is on line A, i.e. taller ascending
                  // slope. In this case, move to right.
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }
}


int main() {
    vector <int> v = {40, 50, 60, 70, 10, 20, 30};

    cout << "Pivot element is at index: " << findPivotIndex(v);

    return 0;
}