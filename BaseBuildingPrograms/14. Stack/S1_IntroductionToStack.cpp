#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Note: We are using STL implementation of stack
    // creation of int and string type stack
    stack <int> st;
    stack <string> st2;

    // Basic stack operations: push(), pop(), size(), top(), empty()
    cout << "Stack empty status: " << st.empty() << endl;   // 1
    cout << "Pushed 10, 20 in stack" << endl;
    st.push(10);
    st.push(20);
    cout << "Size: " << st.size() << endl;   // 2
    cout << "Top element: " << st.top() << endl;   // 20
    cout << "Stack empty status: " << st.empty() << endl;   // 0
    cout << "Popping 1 element from stack" << endl;
    st.pop();
    cout << "Size: " << st.size() << endl;   // 1
    cout << "Top element: " << st.top() << endl;   // 10
    cout << "Stack empty status: " << st.empty() << endl;   // 0

    cout << "Popping 1 more element from stack" << endl;
    st.pop();
    cout << "Size: " << st.size() << endl;   // 0
    cout << "Stack empty status: " << st.empty() << endl;   // 1

    return 0;
}
