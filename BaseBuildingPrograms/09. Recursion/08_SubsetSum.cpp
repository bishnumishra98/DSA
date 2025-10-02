// Given a list of number, return a list of sum of each subset in ascending order. 

// Example 1:
// Input:
// {1, 2, 3}
// Output:
// {0, 1, 2, 3, 3, 4, 5, 6}
// Explanation:
// The subsets of {1, 2, 3} are:
// {} = 0
// {1} = 1
// {1, 2} = 3
// {1, 2, 3} = 6
// {1, 3} = 4
// {2} = 2
// {2, 3} = 5
// {3} = 3

// Example 2:
// Input:
// {}
// Output:
// 0

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Brute force: Build each subset of candidates in 'ds', and keep pushing the sum of elements inside 'ds' into 'ans'
// Optimal approach: No need of extra data structure 'ds'. You can directly find sum of subsets using recursion. Here's the code:

void subsetSum(int index, vector<int>& candidates, vector<int>& ans, int sum) {
    // Base case: When we reach beyond the last element of candidates, push the sum of the current subset into ans
    if(index == candidates.size()) {
        ans.push_back(sum);
        return;
    }

    // PICK: Pick the current element and add it to the sum
    subsetSum(index + 1, candidates, ans, sum + candidates[index]);

    // NOT PICK: Do not pick the current element, keep the sum unchanged
    subsetSum(index + 1, candidates, ans, sum);
}

// T.C: O(2^n)
// S.C: O(n)   recursion stack space
vector<int> findSubsetSum(vector<int>& candidates) {
    vector<int> ans;
    int sum = 0;   // a helper data structure to keep a track of sum of subsets
    subsetSum(0, candidates, ans, sum);
    sort(ans.begin(), ans.end());
    return ans;
}


int main() {
    vector<int> candidates = {1, 2, 3};
    vector<int> ans = findSubsetSum(candidates);

    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
