// Leetcode: 1547. Minimum Cost to Cut a Stick   -->   Given a wooden stick of length n units. The stick is labelled
// from 0 to n. For example, a stick of length 6 is labelled as follows:
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you
// cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick
// before the cut). Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.

// Example 1:
// Input: n = 7, cuts = [1,3,4,5]
// Output: 16
// Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
// The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the
// second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The
// total cost is 7 + 6 + 4 + 3 = 20.
// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the
// example photo 7 + 4 + 3 + 2 = 16).

// Example 2:
// Input: n = 9, cuts = [5,6,1,4,2]
// Output: 22
// Explanation: If you try the given cuts ordering the cost will be 25.
// There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the
// minimum possible.
 
// Constraints:
// ● 2 <= n <= 10^6
// ● 1 <= cuts.length <= min(n - 1, 100)
// ● 1 <= cuts[i] <= n - 1
// ● All the integers in cuts array are distinct.

// Problem link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

// Problem statement: A cakewalk problem if you can visualize. We are asked to cut the rod of length 'n' from multiple
//                    sections mentioned in 'cuts' array. Now the cost to cut the section of rod is the length of that
//                    section. We have to find out the minimum cost in which we can cut the rod into the sections given
//                    in 'cuts' array. Total cost varies if we change the arrangement of elements in 'cuts' array, i.e.,
//                    there will be an arrangement of 'cuts' array for which you will get the least cost. Return that
//                    cost. For example, if you follow the cut order of [3, 5, 1, 4] for the rod of length 7, you will
//                    get the least cost which is 16.

// Algorithm: Follow the same set of rules of every partition dp problem:
//            1. Start with the entire block / array.
//            2. Try out all partitions(divide block/array into two groups), probably by running a loop.
//            3. Return the best possible partition.
//
//            Always sort the 'cuts' array before applying recursion or dynamic programming. Sorting ensures that each
//            recursive subproblem corresponds to a well-defined segment of the stick and only contains valid cut points
//            within that segment. For example, if cuts = [2, 3, 5, 1, 4] and you don't sort it, making a cut at
//            position 5 would divide the stick into two parts. Now you might end up solving two recursive subproblems
//            like f(2, 3) and f(1, 4). But here’s the problem: the second subproblem (for f(1, 4)) tries to cut at
//            position 1, which actually belongs to the left segment of the stick — handled by f(2, 3).
//            This creates a dependency between subproblems, which breaks the fundamental requirement of recursion or
//            dynamic programming: subproblems must be independent.
//            ✅ By sorting the cuts array, you ensure:
//               ● Every subproblem only deals with the cuts that belong within its segment.
//               ● Recursive calls stay independent and valid.
//               ● You can apply memoization or tabulation efficiently without conflict.
//            Once the array is sorted, add 0 at the beginning and 'n (length of initial rod)' at th end of the 'cuts'
//            array. This will help in computing the length of cut section of rod in each recursive call with the
//            formula of length of cut section of rod = cuts[j + 1] - cuts[i - 1], where 'i' and 'j' are extreme indexes
//            in the 'cut' array which contains the data on which positions we have to cut the rod.
//            Call the function f(i, j) which returns the minimum cost to cut the rod from position 'i' to 'j' of the
//            'cuts' array. As first and last element of 'cuts' array are dummy data, and the actual data lies from index 1
//            to index 'cuts.size() - 2', call the recursive function with initial arguments f(1, cuts.size() - 2).
//            I.  Base case: When 'i' crosses 'j', it means 'cuts' array exhausted, i.e., no more cuts, i.e., no more cost.
//                           Thus, return 0.
//            II. Recursive relation: In the recursive call of f(i, j), we need to try out all cuts from index 'i' to
//                                    index 'j' of 'cuts' array. If the rod is cut from a position 'index', then the rod
//                                    will be divided in two parts: left and right. The left part of rod will be handled
//                                    by the recursive function f(i, index - 1), and the right part of rod will be handled
//                                    by the recursive function f(index + 1, j) obviously. Sum up the length of the current
//                                    section of rod with the two function calls, and this is the cost to cut the rod from
//                                    position 'index' of 'cuts' array.
//                                    Now we have to try out all cuts from index 'i' to index 'j' of 'cuts' array, and
//                                    return the minimum cost of all cuts.
//
//            ● Why length of the current section of rod is 'cuts[j + 1] - cuts[i - 1]' ?
//              Initially, we know that 'j' stands on the second last index, and the last index of the 'cuts' array is
//              nothing but the length of initial rod itself, i.e., 'n'. Similarly, 'i' stands on second index, the first
//              index of 'cuts' array is inserted with the value 0. Hence, when the first cut happens on the rod from any
//              position, the rod length is cuts[j + 1] - cuts[i - 1] = n - 0 = n, which holds true as we had the full rod.
//              Now, let's say cuts = [8, 10, 6, 4, 12, 1], n = 14. After sorting and adding boundaries of 0 and 'n',
//              cuts = [0, 1, 4, 6, 8, 10, 12, 14], n = 14. Note that cuts are to be performed on positions only from
//              index 1 to 6 of the 'cuts' array.
//              Suppose the initial rod is cut from a position say 6, so the rod will be divided into two segments each
//              of length 6 and 8 respectively, which will be handled by f(1, 2) and f(4, 6) respectively. 
//              Now the left rod length will be given by same formula: cuts[j + 1] - cuts[i - 1] = cuts[3] - cuts[0]
//              = 6 - 0 = 6, which holds true. Similarly, the right rod length will be given by the same formula:
//              cuts[j + 1] - cuts[i - 1] = cuts[7] - cuts[3] = 14 - 6 = 8, which holds true again.
//              You can try out this formula for a bigger array, and you will see it holds true for every recursive call.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts) {
        if(i > j) return 0;

        int mini = INT_MAX;
        for(int index = i; index <= j; index++) {
            int length = cuts[j + 1] - cuts[i - 1];   // length of the current section of rod
            int cost =  solve(i, index - 1, cuts) + length + solve(index + 1, j, cuts);
            mini = min(mini, cost);
        }

        return mini;
    }

    // T.C: Exponential
    // S.C: O(c);   where c = cuts.size()
    int minCost_recursion(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        // Add boundaries
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int c = cuts.size();
        return solve(1, c - 2, cuts);
    }

// ----------------------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int index = i; index <= j; index++) {
            int length = cuts[j + 1] - cuts[i - 1];
            int cost =  solve(i, index - 1, cuts, dp) + length + solve(index + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    // T.C: O(c^2) for dp * O(c) for loop = O(c^3);   where c = cuts.size()
    // S.C: O(c^2) for dp + O(c) for recursive stack space = O(c^2)
    int minCost_memoization(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int c = cuts.size();
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return solve(1, c - 2, cuts, dp);
    }

// ----------------------------------------------------------------------------------------------------------

    // T.C: O(c^2) for dp * O(c) for loop = O(c^3);   where c = cuts.size()
    // S.C: O(c^2) for dp
    int minCost_tabulation(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int c = cuts.size();
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for(int i = c; i >= 1; i--) {
            for(int j = 1; j <= c - 2; j++) {
                if(i > j) continue;
                int mini = INT_MAX;
                for(int index = i; index <= j; index++) {
                    int length = cuts[j + 1] - cuts[i - 1];
                    int cost = dp[i][index - 1] + length + dp[index + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c - 2];
    }
};


int main() {
    int n = 7;

    vector<int> cuts = {1, 3, 4, 5};
    cout << Solution().minCost_recursion(n, cuts) << endl;

    cuts = {1, 3, 4, 5};
    cout << Solution().minCost_memoization(n, cuts) << endl;

    cuts = {1, 3, 4, 5};
    cout << Solution().minCost_tabulation(n, cuts);

    return 0;
}
