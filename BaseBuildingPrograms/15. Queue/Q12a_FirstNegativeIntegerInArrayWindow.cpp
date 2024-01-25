// There is a sliding window for an array. You are given an array and its size, and you have to
// return the first negative integer found in each window. If no negative integer found in any
// particular window, return 0 for that window.

// Example 1:
// Input: {2, -5, 4, -1, -2, 0, 5}
// Output: {-5, -5, -1, -1, -2}

// Example 2:
// Input: {2, -5, -4, 1, 2, 3, -3, -9}
// Output: {-5, -5, -4, 0, -3, -3}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// T.C: O(n)
// S.C: O(k)
vector<int> printFirstNegative(vector<int> arr, int k) {
    int n = arr.size();
    vector <int> v;
    deque <int> dq;   // note that we can even initialize a queue. Doesn't matters. Still we prefer
    // to initialize a dequeue, as we have full access to pop and push from any side in dequeue.

    // Step 1: Process first k elements for 1st window
    for(int i=0; i<k; i++) {
        int element = arr[i];
        if(element < 0) {
            dq.push_back(i);
        }
    }

    // Step 2: Process rest 'n-k' elements, i.e., 2nd window onwards:
    for(int i=k; i<n; i++) {
        // i) Pushing answer of previous window into 'v' before proceeding further
        if(dq.empty()) {
            v.push_back(0);
        } else {
            v.push_back(arr[dq.front()]);
        }
        
        // ii) If the front index present in dequeue doesn't corresponds to one of the k elements
        //    that should be present in this window, remove that index from dequeue.
        if(!dq.empty() && (i - dq.front() >= k)) {
            // if 'i-dq.front() >= k', it means dq.front() is not in window
            dq.pop_front();
        }

        // iii) Addition of a new index in 'dq' which corresponds to an element that comes
        //     within this window
        if(arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // iv) Pushing answer of the last window of array into 'v'
    if(dq.empty()) {
        v.push_back(0);
    } else {
        v.push_back(arr[dq.front()]);
    }

    return v;
}

int main() {
    vector <int> arr{2, -5, -4, 1, 2, 3, -3, -9};
    int k = 3;

    vector <int> ans = printFirstNegative(arr, k);

    for(auto i: ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
