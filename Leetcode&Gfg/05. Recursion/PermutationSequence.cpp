// Leetcode: 60. Permutation Sequence   --->   The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

// Example 3:
// Input: n = 3, k = 1
// Output: "123"

// Optimal solution: Go through the video solution: https://www.youtube.com/watch?v=wT7gcXLYoao&t=497s

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateAllPermutations_helper(int index, vector<int>& candidates, vector<vector<int>>& ans) {
        if(index == candidates.size()) {
            ans.push_back(candidates);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {
            swap(candidates[index], candidates[i]);
            generateAllPermutations_helper(index + 1, candidates, ans);
            swap(candidates[i], candidates[index]);
        }
    }

    vector<vector<int>> generateAllPermutations(vector<int>& candidates) {
        vector<vector<int>> ans;
        int index = 0;
        generateAllPermutations_helper(index, candidates, ans);
        return ans;
    }

    // T.C: O(n! * n) as there are n! permutations and each permutation takes O(n) time to copy and push into ans
    //      + O(n! * log(n!)) for sorting
    //      = O(n! * n)
    // S.C: O(n! * n)
    string getPermutation_bruteforce(int n, int k) {
        vector<int> candidates;
        for(int i = 1; i <= n; i++) candidates.push_back(i);
        vector<vector<int>> allPremutations = generateAllPermutations(candidates);

        // Sort 'allPremutations'
        sort(allPremutations.begin(), allPremutations.end());

        // Store the Kth permutation
        vector<int> kthPermutation = allPremutations[k - 1];

        // Convert all integers in kthPermutation to a character and store it in a string
        string ans = "";
        for(int i: kthPermutation) ans += to_string(i);
        return ans;
    }

// -----------------------------------------------------------------------------------------------------------------------

    // T.C: O(n^2)
    // S.C: O(n)
    string getPermutation(int n, int k) {
        // Create a 'candidates' array having elements from 1 to n. And also calculate (n - 1)! and store it in 'fact'.
        // We calculate (n - 1)! because n! permutations are divided into n groups. So each group has (n - 1)! permutations.
        int fact = 1;
        vector<int> candidates;
        for(int i = 1; i < n; i++) {
            fact = fact * i;
            candidates.push_back(i);
        }
        candidates.push_back(n);   // candidates = {1, 2, 3, ..., n}

        string ans = "";
        k = k - 1;   // as we will be using a 0 based indexing

        while(true) {
            ans = ans + to_string(candidates[k / fact]);
            candidates.erase(candidates.begin() + k / fact);   // erase the (k / fact)th element from candidates
            if(candidates.size() == 0) break;
            k = k % fact;
            fact = fact / candidates.size();
        }

        return ans;
    }
};

int main() {
    int n = 4, k = 9;
    Solution sol;

    cout << sol.getPermutation_bruteforce(n, k) << endl;
    cout << sol.getPermutation(n, k);

    return 0;
}
