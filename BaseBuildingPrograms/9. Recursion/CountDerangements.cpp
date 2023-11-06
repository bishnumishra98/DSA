// A Derangement is a permutation of n elements, such that no element appears in its original
// position. Given a number n, find the total number of Derangements of a set of n elements. 

// Example 1:
// Input: n = 2
// Output: 1
// Explanation: For two elements say {0, 1}, there is only one possible derangement {1, 0}.

// Example 2:
// Input: n = 3
// Output: 2
// Explanation: For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1}
// and {1, 2, 0}.

// Example 3:
// Input: n = 4
// Output: 9
// Explanation: For four elements say {0, 1, 2, 3}, there are 9 possible derangements {1, 0, 3, 2},
// {1, 2, 3, 0}, {1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1}
// and {3, 2, 1, 0}.


#include <iostream>
using namespace std;

// T.C: O(2^n)
// S.C: O(n)
int countDerangements(int n) {
    // base case
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }

    // Let assume an array {0, 1, 2, 3}. If there are 'n' elements in this array, we can keep the
    // first element(0) in 'n-1' ways so that its index is changed. And let's say the element 0 is
    // placed at index 'i'. Now, there can be two possibilities, depending on whether or not
    // element 'i' shall be placed at index of 0 in return.

    // Case 1:-
    // 'i' is placed at 0: This case is equivalent to solving the problem for 'n-2' elements
    // as two elements have just swapped their positions.
    int ans1 = (n-1)*countDerangements(n-2);

    // Case 2:-
    // 'i' is not placed at 0: This case is equivalent to solving the problem for 'n-1' elements
    // as now there are 'n-1' elements and 'n-1' positions left.
    int ans2 = (n-1)*countDerangements(n-1);

    return ans1 + ans2;
}

int main() {
    int n = 4;

    cout << countDerangements(n);

    return 0;
}