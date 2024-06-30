// Given an input array, print all permutations of it
// Example:
// Input:
// {1, 2, 3}
// Output:
// {1, 2, 3}
// {1, 3, 2}
// {2, 1, 3}
// {2, 3, 1}
// {3, 1, 2}
// {3, 2, 1}

#include <iostream>
#include <vector>
using namespace std;

void allPermut(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int freq[]) {
    // Base case: When size of 'ds' is equal to size of 'candidates', the permutation is built. Push it in 'ans' and return.
    if(ds.size() == candidates.size()) {
        ans.push_back(ds);
        return;
    }

    // Iterate over each element of 'candidate' to build all possible permutation from ith element
    for(int i=0; i<candidates.size(); i++) {
        // If this ith element is not piced up yet
        if(freq[i] == 0) {
            ds.push_back(candidates[i]);   // Push the ith element into 'ds'
            freq[i] = 1;   // Mark freq[i] as 1, stating that ith element has been picked
            allPermut(candidates, ans, ds, freq);   // Call the allPermut() function to find the other elements that
                                                   // can be paired with ith element to build a unique permutation
            // Backtrack: After coming from the recursive call, unmark freq[i], and remove the last element from 'ds'
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

// T.C: O(n! * n);   where n = candidates.size()
// S.C: O(n + n) = O(n)
vector<vector<int>> findPermutations_bruteForce(vector<int>& candidates) {
    vector<vector<int>> ans;
    vector<int> ds;   // helper data structure to store elements of candidates temporarily

    // Initializing a 'freq' array of size 'candidates.size()', with initial values 0.
    // int freq[candidates.size()];   // helper data structure to keep a track of elements that have been picked
    // for(int i=0; i<candidates.size(); i++) freq[i] = 0;

    // The above two steps can be done in 1 line:
    int freq[candidates.size()] = {0};

    allPermut(candidates, ans, ds, freq);
    return ans;
}

int main() {
    vector<int> candidates = {1, 2, 3};
    vector<vector<int>> ans = findPermutations_bruteForce(candidates);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
