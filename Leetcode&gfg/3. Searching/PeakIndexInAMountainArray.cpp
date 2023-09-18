// Leetcode: 852. Peak Index in a Mountain Array

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
// This code uses binary search approach
int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start)/2;

    while(start < end) {   // We haven't written (start <= end) in order to avoid infinite
                          // loop when only 1 element is left, i.e. start == end == mid.
        if(arr[mid] < arr[mid+1]) {
            // We are in the ascending part of the mountain (Line A). In this case,
           // peak may be presnt on 'mid+1' itself or on further right of it. Thus,
          // we must move right to find the peak.
            start = mid + 1;
        } else {   // if(arr[mid] > arr[mid+1])
            // We are in the descending part of the mountain (Line B). In this case,
           // peak may be presnt on 'mid' itself or on further left of it. Thus,
          // we must move to left to find the peak. But, if we go to left in the
         // traditional way like 'end = mid - 1', there can be a possibility that
        // we could have missed the peak if it was present at 'mid' index only. So, to
       // ensure we don't miss the peak while moving left, we move like this: (end = mid).
            end = mid;
        }

        mid = start + (end - start)/2;
    }

    return start;   // we can even return end or mid
}

int main() {
    vector <int> v = {0, 2, 1, 0};
    cout << peakIndexInMountainArray(v);

    return 0;
}