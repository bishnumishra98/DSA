// If we were to merge two or three sorted arrays, we could have used two-pointer or three-pointer approach.
// But if no.of sorted arrays are many, this approach is not feasible. Thus, we will use concept of min-heap.
// Algorithm:
// 1. Create a blank array say 'ans', where the merged array will be constructed.
// 2. Create a min-heap from the first element of all k arrays.
// 3. Pop the top element of min-heap, i.e., the smallest first element amongst all k arrays,
//    and store it inside the 'ans' array.
// 4. After popping the top element from min-heap, push the next element from that array from where
//    the previous element was popped, into the min-heap.
// 5. Repeat the process until all elements of all k arrays have been pushed into the min-heap. Also,
//    keep popping out elements from min-heap and store then in 'ans' array until the min-heap is over.

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// A comparator function for the priority queue
struct compare {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);  // Compare the first elements (values) of the tuples
    }
};

// Merges k sorted arrays into a single sorted array
void mergeKSortedArrays(vector<vector<int>>& arr, vector<int>& ans) {
    // Min-heap (priority queue) to store (element, row index, column index)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> minHeap;

    // Initialize the heap with the first element of each array
    for (int i = 0; i < arr.size(); ++i) {
        if (!arr[i].empty()) {
            minHeap.push(make_tuple(arr[i][0], i, 0));
        }
    }

    // Extract elements from the heap and keep adding new elements from the arrays
    while (!minHeap.empty()) {
        tuple<int, int, int> current = minHeap.top();
        minHeap.pop();

        int val = get<0>(current);
        int row = get<1>(current);
        int col = get<2>(current);

        ans.push_back(val);

        // If there is another element in the same row, add it to the heap
        if (col + 1 < arr[row].size()) {
            minHeap.push(make_tuple(arr[row][col + 1], row, col + 1));
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {5, 10, 15, 20},
        {3, 6},
        {2, 4, 6, 8}
    };

    vector<int> ans;
    mergeKSortedArrays(arr, ans);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
