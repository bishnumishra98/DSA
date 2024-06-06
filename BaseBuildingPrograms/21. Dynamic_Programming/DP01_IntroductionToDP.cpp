// ✦ Dynamic programming(DP) is a method for solving complex problems by breaking them down into simpler subproblems.
// It is particularly useful for optimization problems where the solution can be built up from solutions to smaller
// instances of the same problem. Here are the key concepts and steps involved in dynamic programming:

// -> Optimal Substructure: The problem can be broken down into smaller, simpler subproblems, which can be solved independently.
//                          DP method of solving problems makes the solution easier to understand and implement by clearly
//                          defining subproblems and their interrelationships.

// -> Overlapping Subproblems: The problem has overlapping subproblems, meaning the same subproblems are solved multiple times.
//                             DP method of solving problem can help avoid these overlapping sub-problems, by storing
//                             intermediate results and avoiding redundant calculations.


// ✦ DP problems can be solved in either of the two ways:

// 1. Memoization (Top-Down Approach): Store the results of subproblems in a table to avoid redundant computations.
//                                     This involves solving the problem recursively and storing the results.
//                                     Steps involved in this process:
//                                     i.   Create a dp array.
//                                     ii.  Store/return answer in the dp array.
//                                     iii. If answer already exist in dp array, utilize the answer by returning it.

// 2. Tabulation (Bottom-Up Approach): Solve subproblems in a systematic way, typically using iteration, and store
//                                     their results in a table.
//                                     Steps involved in this process:
//                                     i.   Create a dp array.
//                                     ii.  Fill initial data in dp according to base case.
//                                     iii. Fill rest of the dp array using iteration.

// Although both approaches have same time complexity, the Tabulation (Bottom-Up Approach) is better
// as it uses iterative solution which saves overhead of recursive function calls.

// Example:
// Below is a fibonacci program to print nth number of the fibonacci series. f(0) = 0, f(1) = 1, f(n) = f(n-1) + f(n-2).
// nth number of fibonacci series can found out in both recursive and dynamic programming way:
// i)  Simple recursion (uses more space due to calling of same subproblems multiple times)
// ii) Dynamic programming (uses optimal space)
// Further all DP problems can be solved in both ways: Memoization (Top-Down Approach) and the Tabulation (Bottom-Up Approach).

#include <iostream>
#include <vector>
using namespace std;

// Simple recursion
// T.C: O(2^n)
// S.C: O(n);   due to recursive call stack
int fibo_recursion(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int ans = fibo_recursion(n-1) + fibo_recursion(n-2);
    return ans;
}

// Memoization (Top-Down Approach)
// T.C: O(n)
// S.C: O(n)
int fibo_memoization(int n, vector<int>& dp) {
    // Base case
    dp[0] = 0;
    if(n > 0) dp[1] = 1;   // initiliaze dp[1] only if 'n > 0', or else we will get 'heap-buffer-overflow'

    // Step 1: Create a dp array(already created in driver code, and passed here as an argument).

    // Step 3: If answer already exist in dp array, utilize the answer by returning it. This helps in saving
    // the time of solving same subproblems multiple times which recursion was doing.
    if(dp[n] != -1) return dp[n];

    // Step 2: Store/return answer in the dp array.
    dp[n] = fibo_memoization(n-1, dp) + fibo_memoization(n-2, dp);
    return dp[n];
}

// Tabulation (Bottom-Up Approach)
// T.C: O(n)
// S.C: O(n)
int fibo_tabulation(int n) {
    // Step 1: Create a 'dp' array of size 'n+1' with default values -1
    vector<int> dp(n+1, -1);

    // Step 2: Fill initial data in dp according to base case.
    dp[0] = 0;
    if(n > 0) dp[1] = 1;   // initiliaze dp[1] only if 'n > 0', or else we will get 'heap-buffer-overflow'

    // Step 3: Fill rest of the dp array using iteration.
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// The best approach for finding nth term of fibonacci series
// T.C: O(n)
// S.C: O(1)
int fibo_ite(int n) {
    if(n == 0 || n == 1) return n;
    int n1 = 0, n2 = 1, n3;
    for(int i=2; i<=n; i++) {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}


int main() {
    // Fibo series elements: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
    int n = 6;
    cout << "Recursive ans: " << fibo_recursion(n) << endl;

    // Creating a 'dp' array of size 'n+1' with default values -1
    vector<int> dp(n+1, -1);
    cout << "fibo_memoization ans: " << fibo_memoization(n, dp) << endl;

    cout << "fibo_tabulation ans: " << fibo_tabulation(n) << endl;

    // However, remember that the best program for fibonacci series is the simple iterative approach
    cout << "fibo_ite: " << fibo_ite(n);

    return 0;
}
