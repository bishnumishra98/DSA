// If we push anything inside stack, it comes out in LIFO(Last In First Out) fashion.

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "Golu";
    stack <char> st;

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        st.push(ch);
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    cout << endl;

    return 0;
}
