// If we were to merge two or three sorted arrays, we could have used two-pointer or three-pointer approach.
// But if no.of sorted arrays are many, this approach is not feasible. Thus, we will use concept of min-heap.
// Algorithm:
// 1. Create an array say 'ans', where the merged array will be constructed.
// 2. Create a min-heap by pushing the first element from each of the k arrays. Note that not
//    only just push the elements of the arrays, but also push the element's row-index and
//    column-index along with it. This will be useful to keep a track of elements that have been
//    pushed into the min-heap from respective arrays. Thus, each element pushed into the
//    min-heap should be a tuple(value, row_index, col_index).
// 3. Pop the top element of min-heap, i.e., the smallest first element amongst all k arrays,
//    and store it inside the 'ans' array. The smaller element in a heap is resolved on the basis
//    of a functor that determines the ordering of elements in the priority queue. But as we
//    are not pushing any primitive data types like int or float into heap, we have to define
//    our own functor, i.e., a custom comparator which will decide which tuple is smaller.
// 4. After popping the top element from min-heap, push the next element of the array from where
//    the previous element was popped, into the min-heap.
// 5. Repeat the process to push all elements of each array into the min-heap. Also, keep
//    popping and storing the elements from min-heap into 'ans' array until the min-heap is over.

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// A comparator function for the priority queue
struct Compare {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);   // If the first element of tuple 'a' is greater than that of tuple 'b', return true, else false.
    }
};

// T.C: O(nlogk);   where n = total number of elements across all arrays, and O(logk) time is required
//                  to push each element into the heap and extract from heap from k arrays. Thus, for
//                  n elements, total time required to push and extract from heap will be O(nlogk).
// S.C: O(n+k);   At any given time, the min-heap stores at most k elements (one from each array).
//                Hence, the space required for the min-heap is O(k). The merged array ans will store
//                all n elements, thus it will require O(n) space. Thus, overall space complexity is O(n+k).
void mergeKSortedArrays(vector<vector<int>>& arr, vector<int>& ans) {
    // Min-heap (priority queue) to store (element, row index, column index)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;

    // Initialize the heap with the first element of each array
    for(int i = 0; i < arr.size(); ++i) {
        if (!arr[i].empty()) {
            minHeap.push(make_tuple(arr[i][0], i, 0));
        }
    }

    // Extract elements from the heap and keep adding new elements from the arrays
    while(!minHeap.empty()) {
        tuple<int, int, int> current = minHeap.top();
        minHeap.pop();

        int val = get<0>(current);
        int row = get<1>(current);
        int col = get<2>(current);

        ans.push_back(val);

        // If there is another element in the same row, add it to the heap
        if(col + 1 < arr[row].size()) {
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
