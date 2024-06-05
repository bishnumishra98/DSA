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
//                                     iii. Fill rest of the dp array using recursive relation.

// Although both approaches have same time complexity, the Tabulation (Bottom-Up Approach) is better
// as it uses iterative solution which saves overhead of recursive function calls.

#include <iostream>
using namespace std;

int main() {

    return 0;
}
