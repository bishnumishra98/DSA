// For example, let there be an odd size stack of size 5:  10  20  30  40  50
// Here, the mid element position is (size / 2 + 1)th, i.e., 3rd element from top i.e., 30.
// For example, let there be an even size stack of size 4:  10  20  30  40
// Here also, the mid element position is (size / 2 + 1)th element, i.e., 3rd element from top i.e., 20.
// If we want the another element of the two mids, then position shall be (size / 2)th element,
// i.e., 2nd element from top, i.e., 30.

// To find middle element of the stack, we can follow this algorithm:
// 1) Find mid element position of stack.
// 2) Pop out stack elements and store them in a temporary variable, and simultaneously
//    decrement count of position. Do this recursively until position reaches 1.
// 3) At this point, the top element of stack will be the mid element. Accesss it.
// 4) In the end, backtrack the stack elements to reconstruct the original stack.

#include <iostream>
#include <stack>
using namespace std;


// T.C: O(n)
// S.C: O(n)
int getMiddleElementOfStack(stack<int>& st) {
    // If stack is empty, return -1
    if(st.empty()) return -1;

    int size = st.size();
    int pos;

    if(size & 1) {
        // If size is odd, mid position is (size / 2 + 1)th element
        pos = size / 2 + 1;
    } else {
        // If size is even, let's consider (size / 2)th element
        pos = size / 2;
    }
    // For the other mid, no if else condition is required. Directly, pos = size / 2 + 1

    stack<int> tempSt = st;  // copy original stack to temporary stack so that we don't modify original stack

    // If pos is 'x', run loop 'x - 1' times
    while(--pos) {
        tempSt.pop();
    }

    return tempSt.top();
}

int main() {
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Middle element: " << getMiddleElementOfStack(st);   // o/p: 30

    return 0;
}
