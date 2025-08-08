// What is a pivot index ?
// The pivot index is the position in a rotated sorted array where the largest element transitions to the smallest element.
// Hence, in a rotated sorted array, the largest element is considered the pivot.

#include <iostream>
#include <vector>
using namespace std;

// Algorithm: Algo is very simple. Lets consider the array: {40, 50, 60, 70, 10, 20, 30}. There are two monotonic
//            functions formed here. One is line A (40, 50, 60, 70) and other one is line B (10, 20, 30). Line A
//            is higher than line B in graphical representation, i.e., all elements of line A > all elements of line B.
//            Although binary search cannot be applied direct on the whole array, but can be applied separately on
//            line A and line B elements respectively, as they are sorted; and the two elements that are unsorted
//            with respect to each other(pivot and element next to pivot) shall be handled separately.
//            Keep in mind, that pivot element will always lie on line A and it will be the greatest element of line A.
//            All total there can be 4 cases combined, and as usual start = 0, mid = (start + end) / 2 and end = last
//            element of array, and we will be comparing arr[mid] with other elements until 'start' crosses 'end'.

// Case 1: If element is on line A and pivot index, i.e., largest element, i.e., on 70.
//         If element is on pivot index, the next element has to be smaller than it. Thus, it is the
//         only case when arr[mid] > arr[mid + 1]. Thus, return the pivot index(mid) in this case.

// Case 2: If element is on line B and first element of line B, i.e., smallest element, i.e., on 10.
//         If it is the smallest one, it is the only case when arr[mid] < arr[mid - 1]. Thus, in this
//         case return the pivot index which lies just behind it, i.e., on 'mid - 1' position.

// Case 3: If element is on line B, other than smallest element.
//         If element is on line B, other than smallest element, it means arr[mid] < arr[start], because altitude of all
//         elements of line A is more than altitude of all elements of line B. Thus, in this case the pivot will be not
//         present on this line, it will lie on the above line, i.e., A. Thus, shift the search space towards left,
//         i.e., end = mid - 1.

// Case 4: If element is on line A, other than pivot index.
//         If element is on line A, other than pivot index, it means arr[mid] >= arr[start]. Thus, in this case
//         the pivot will be somewhere on the right. Hence, shift the search space towards right, i.e., start = mid + 1.


// T.C: O(logn)
// S.C: O(1)
int findPivotIndex(vector<int>& nums) {
    int n =  nums.size();
    int start = 0, end = n - 1, mid = start + (end - start) / 2;

    while(start <= end) {
        if(start == end) return start;   // if only one element is left, it itself is the pivot element
        if((mid + 1 < n) && (nums[mid] > nums[mid + 1])) return mid;
        else if((mid - 1 >= 0) && (nums[mid] < nums[mid - 1])) return mid - 1;
        else if(nums[mid] < nums[start]) end = mid - 1;
        else start = mid + 1;   // if(nums[mid] >= nums[start])

        mid = start + (end - start) / 2;
    }

    return -1;   // to avoid error 'function does not return a value in all control paths'
}


int main() {
    vector <int> v = {40, 50, 60, 70, 10, 20, 30};

    cout << "Pivot element is at index: " << findPivotIndex(v);

    return 0;
}
