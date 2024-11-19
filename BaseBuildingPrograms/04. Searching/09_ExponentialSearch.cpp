// Exponential search also known as galloping search / doubling search is popular search algorithm
// to search an element in unbounded or infinite sorted array. It is particularly useful in scenarios
// involving large sorted datasets or streams where you can't determine the total size beforehand.

#include <iostream>
#include <vector>
using namespace std;

// Algorithm: It is very simple and straight forward.
// 1. If first element of array is the target, return it.
// 2. Initialize a variable say 'i' with 1, increment it exponentially in powers of step you want,
//    usually the step is 2 in most cases. Keep incrementing 'i' until arr[i] crosses the target.
//    The value of 'i' for which arr[i] crosses the target is the upper bound and the lower bound
//    will be the last value of 'i', i.e., 'i/2'. Hence, we have found out a search space within
//    which the target element would lie. Thus, pass the array, target, lower and upper bound
//    values to the binary search function to find the index of the target element.
//    But note that the upper bound value may exceed the size of array, thus always ensure the
//    upper bound value passed to binary search function is the minimum of 'i' and size of array.


int binarySearch(vector<int>& arr, int target, int start, int end) {
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(target > arr[mid]) start = mid + 1;
        else if(target < arr[mid]) end = mid - 1;
        else return mid;   // if(target == arr[mid])
    }
    return -1;   // if element not found
}

// T.C: O(logN);   where N = arr.size()
// S.C: O(1)
int exponentialSearch(vector<int>& arr, int target) {
    if(arr.empty() || target < arr[0]) return -1;   // edge case
    if(target == arr[0]) return 0;

    int i = 1;
    while(i < arr.size() && arr[i] <= target) i = i << 1;   // i = i * 2;

    int start = i >> 1;   // i / 2;
    int end = min(i, (int)arr.size() - 1);   // ensure the range doesn't exceeds array bounds
    return binarySearch(arr, target, start, end);
}


int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int target = 60;

    cout << target << " is present at index: " << exponentialSearch(arr, target);

    return 0;
}


// Deduction of time complexity:
// The no.of steps to exceed target in exponentialSearch() function is log(target) = k(let).
// After k steps, the search space passed to binary search is 2^(k-1) and 2^k. Thus, binary search
// is applied on range of 2^k - 2^(k-1) = 2^(k-1). Thus, time complexity of binary search function
// would be O(log(2^(k-1))) = O(k-1) = O(k).
// Combining both, the overall time complexity would be O(k) + O(k) = O(k), and k in the worst
// case will be log(n), where n is the size of array. Thus, overall time complexity is O(log(n)).

// EXTRA FACT: The above algorithm is applicable for large finite dataset in this module. For
//             truly infinite the dataset, the algorithm remians the same, only the implementation
//             of bounds and data access differs. 
//             If the dataset is truly unbounded (e.g., an infinite stream or large unknown data
//             source), you cannot rely on arr.size(). Instead, you would modify the algorithm to:    
//             • Access elements one at a time (e.g., through an API or generator).
//             • Handle out-of-bound conditions dynamically by catching exceptions or checking
//               for a "sentinel" value (e.g., None, -1, or an invalid value).

