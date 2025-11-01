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

void allPermut(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, vector<bool>& freq) {
    // Base case: When size of 'ds' is equal to size of 'candidates', the permutation is built. Push it in 'ans' and return.
    if(ds.size() == candidates.size()) {
        ans.push_back(ds);
        return;
    }

    // Iterate over each element of 'candidate' to build all possible permutation from ith element
    for(int i = 0; i < candidates.size(); i++) {
        // If this ith element is not picked up yet
        if(freq[i] == false) {
            ds.push_back(candidates[i]);   // Push the ith element into 'ds'
            freq[i] = true;   // Mark freq[i] as true, stating that ith element has been picked
            allPermut(candidates, ans, ds, freq);   // Call the allPermut() function to find the other elements that
                                                   // can be paired with ith element to build a unique permutation
            // Backtrack: After coming from the recursive call, unmark freq[i], and remove the last element from 'ds'
            freq[i] = false;
            ds.pop_back();
        }
    }
}

// T.C: O(n! * n);   where n = candidates.size()
// S.C: O(n + n) = O(2n)
vector<vector<int>> findPermutations_bruteForce(vector<int>& candidates) {
    vector<vector<int>> ans;
    vector<int> ds;   // helper data structure to store elements of candidates temporarily

    // Initializing a 'freq' array of size 'candidates.size()', with initial values 0
    vector<bool> freq(candidates.size(), false);

    allPermut(candidates, ans, ds, freq);
    return ans;
}

// --------------------------------------------------------------------------------------------------------------------

void allPermut(int index, vector<int>& candidates, vector<vector<int>>& ans) {
    // Base case: When we reach beyond last element of 'candidates', push the 'candidates' vector in 'ans' and return.
    if(index == candidates.size()) {   // or, if(index == candidates.size() - 1) as when 'index' reaches 'candidates.size() - 1',
                                        // no change in position of elements occur on next recursive call (last recursive call).
        ans.push_back(candidates);
        return;
    }

    // Swapping current element with itself and elements on its right.
    for(int i = index; i < candidates.size(); i++) {
        swap(candidates[index], candidates[i]);
        allPermut(index + 1, candidates, ans);
        swap(candidates[index], candidates[i]);   // backtrack to unswap 'candidates' after coming from the above recursion call
    }
}

// T.C: O(n! * n);   where n = candidates.size()
//      There are n! permutations and each permutation takes O(n) time to copy and push into ans
// S.C: O(n)
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
