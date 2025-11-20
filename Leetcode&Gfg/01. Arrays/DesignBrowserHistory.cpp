// GFG: Design Browser History   --->   You have a browser of one tab where you start on the homepage and you can visit
// another url, get back in the history number of steps or move forward in the history number of steps.

// Implement the BrowserHistory class:
// ● BrowserHistory (string homepage) Initializes the object with the homepage of the browser.
// ● void visit (string url) Visits url from the current page. It clears up all the forward history.
// ● string back (int steps) Move steps back in history. If you can only return x steps in the history and steps > x,
//   you will return only x steps. Return the current url after moving back in history at most steps.
// ● string forward (int steps) Move steps forward in history. If you can only forward x steps in the history and
//   steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

// Example 1:
// Input:
// homepage = "gfg.org"
// visit("google.com");
// visit("facebook.com");
// visit("youtube.com");
// back(1);
// back(1);
// forward(1);
// visit("linkedin.com");
// forward(2);
// back(2);
// back(7);

// Output:
// facebook.com
// google.com
// facebook.com
// linkedin.com
// google.com
// gfg.org

// Explanation: 
// query1: you are now at "google.com"
// query2: you are now at "facebook.com"
// query3: you are now at "youtube.com"
// query4: move one step back, you will be at
//         "facebook.com" again.
// query5: move one more step back, you will be
//         at "google.com"
// query6: move one step forward, you will be 
//         at "facebook.com"
// query7: jump to "linkedin.com"
// query8: No forward steps available, be at 
//         "linkedin.com"
// query9: move two steps back, you will go to 
//         "facebook.com" and then "google.com"
// query10: required 7 steps backward but only 
//          1 step available, so move 1 step  
//          back, you will be at "gfg.org"

// Example 2:
// Input:
// homepage = "google.com"
// visit("youtube.com");
// back(2);
// Output:
// google.com
// Explanation:
// Required 2 steps backward, but only 1 step
// available. So move 1 step back and you will
// be at "google.com"
 
// Your Task:  
// You don't need to read input or print anything. Your task is to design your data structure inside class
// BrowserHistory and complete the functions visit(), back(), forward() and the constructor.

// Expected Time Complexity: O(1) for back(), forward() and O(n) for visit()
// Expected Space Complexity: O(n)

// Problem link: https://www.geeksforgeeks.org/problems/design-browser-history/1

// Algorithm: This BrowserHistory can be implemented using Doubly Linked List, or using two stacks. But the most optimal
//            way is to use a dynamic array (vector in C++).

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    int curr;   // to keep a track of index of current page
    int last;   // to keep a track of index of last valid page (logical end of history, not necessarily physical end
               // of 'history' vector). Pages beyond this index in the 'history' vector can never be reached.
public:
    // Constructor to initialize object with homepage
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;   // initially current page is homepage, i.e., history[0]
        last = 0;   // initially last valid page is homepage, i.e., history[0]
    }

    // Visit current url: Add url to history and clear forward history
    void visit(string url) {
        curr++;
        // If curr is within bounds, overwrite the history; else append new url.
        if(curr < history.size()) {
            history[curr] = url;
        } else {
            history.push_back(url);
        }
        last = curr;   // truncate forward history logically, so that pages beyond 'last' are unreachable

        // Optional: If you want to physically remove forward history from the vector to save space
        history.resize(last + 1);
        // or, history.erase(history.begin() + last + 1, history.end());
    }

    // 'steps' move backward in history and return current page
    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    // 'steps' move forward and return current page
    string forward(int steps) {
        curr = min(last, curr + steps);
        return history[curr];
    }
};

int main() {
    BrowserHistory browserHistory("gfg.org");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    cout << browserHistory.back(1) << endl;        // o/p: facebook.com
    cout << browserHistory.back(1) << endl;        // o/p: google.com
    cout << browserHistory.forward(1) << endl;     // o/p: facebook.com
    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl;     // o/p: linkedin.com
    cout << browserHistory.back(2) << endl;        // o/p: google.com
    cout << browserHistory.back(7) << endl;        // o/p: gfg.org

    return 0;
}
