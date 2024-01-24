// There is a sliding window for an array. You are given an array and its size, and you have to
// return the first negative integer found in each window. If no negative integer found in any
// particular window, return 0 for that window.

// Example 1:
// Input: {2, -5, 4, -1, -2, 0, 5}
// Output: {-5, -5, -1, -1, -2}

// Example 2:
// Input: {2, -5, 4, -1, 2, 0, 5}
// Output: {-5, -5, -1, -1, 0}

#include <iostream>
#include <vector>
using namespace std;

// T.C:
// S.C: 
vector<int> printFirstNegative(int* arr, int n, int k) {

}

int main() {
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = 7;
    int k = 3;

    vector <int> ans = printFirstNegative(arr, size, k);

    for(auto i: ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
