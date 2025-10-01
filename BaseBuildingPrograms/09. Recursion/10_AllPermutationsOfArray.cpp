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

// --------------------------------------------------------------------------------------------------------------------

    void allPermut(int index, vector<int>& candidates, vector<vector<int>>& ans) {
        // Base case: When we reach beyond last element of 'candidates', push the 'candidates' vector in 'ans' and return.
        if(index == candidates.size()) {   // Base case can also be if(index == candidates.size() - 1) {...} as when 'index'
                                          // reaches 'candidates.size() - 1', no change in position of elements occur on further
                                         // recursive call. Thus, the 2nd last level of recursion can also be treated as the base case.
            ans.push_back(candidates);
            return;
        }

        // Swapping current element with itself and elements on its right.
        for(int i=index; i<candidates.size(); i++) {
            swap(candidates[index], candidates[i]);
            allPermut(index+1, candidates, ans);
            swap(candidates[index], candidates[i]);   // backtrack to unswap 'candidates' after coming from the above recursion call
        }
    }

    // T.C: O(n! * n);   where n = candidates.size()
    // S.C: O(1);   excluding 'ans' space
    vector<vector<int>> findPermutations(vector<int>& candidates) {
        vector<vector<int>> ans;
        allPermut(0, candidates, ans);
        return ans;
    }

int main() {
    vector<int> candidates = {1, 2, 3};

    vector<vector<int>> ans1 = findPermutations_bruteForce(candidates);
    for(int i=0; i<ans1.size(); i++) {
        for(int j=0; j<ans1[i].size(); j++) {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> ans2 = findPermutations(candidates);
    for(int i=0; i<ans2.size(); i++) {
        for(int j=0; j<ans2[i].size(); j++) {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
