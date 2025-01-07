// GFG: Common in 3 Sorted Arrays   --->   You are given three arrays sorted in increasing order. Find the elements
// that are common in all three arrays.
// If there are no such elements return an empty array. In this case, the output will be -1.
// Note: can you handle the duplicates without using any additional Data Structure?

// Example 1:
// Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
// Output: [20, 80]
// Explanation: 20 and 80 are the only common elements in arr1, arr2 and arr3.

// Example 2:
// Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
// Output: [-1]
// Explanation: There are no common elements in arr, arr2 and arr3.

// Example 3:
// Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
// Output: [1, 2]
// Explanation: We do not need to consider duplicates

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n1^n2^n3);   where n1, n2 and n3 are size of arr1, arr2 and arr3 respectively.
    // S.C: O(2n)
    vector<int> commonElements_bruteforce(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        set<int> st;   // set data structure is used to ensure we don't store any duplicate common elements

        for(int i = 0; i < arr1.size(); i++) {
            for(int j = 0; j < arr2.size(); j++) {
                for(int k = 0; k < arr3.size(); k++) {
                    if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) st.insert(arr1[i]);
                }
            }
        }

        // vector<int> commonElements;
        // for(int it: st) commonElements.push_back(it);
        vector<int> commonElements(st.begin(), st.end());
        return commonElements;
    }

// ---------------------------------------------------------------------------------------------------------------

    // Optimal algorithm: We shall use 3 pointer approach in this problem and take advantage of the fact that all arrays are sorted.
    // Algorithm is extremely easy, just point 3 pointers i, j, k on 0th index of all arrays. The goal of this approach is to
    // efficiently align the three pointers (i, j, k) to identify common elements while skipping elements that cannot be common.
    // There can be 4 cases:
    // Case 1: If all pointers point to elements having same value, then store the common element, then move ahead all pointers.
    // Case 2: If arr1[i] < arr2[j], there’s no point in keeping arr1[i] in consideration as it is not going to be common in
    //         all the 3 arrays. Hence, check a larger element in arr1 to find any common. Thus, move i ahead.
    // Case 3: If arr2[j] < arr3[k], there’s no point in keeping arr2[j] in consideration as it is not going to be common in
    //         all the 3 arrays. Hence, check a larger element in arr2 to find any common. Thus, move j ahead.
    // Case 4: If arr1[i], arr2[j] and arr3[k] are not equal, nor arr1[i] is less than arr2[j], nor arr2[j] is less than arr3[k],
    //         the only case it indicates is that arr3[k] is smallest amongst the 3. Hence, move ahead k.
    

    // T.C: O(n1+n2+n3);   where n1, n2 and n3 are size of arr1, arr2 and arr3 respectively.
    // S.C: O(2n)
    vector<int> commonElements_timeOptimised(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        set<int> st;   // set data structure is used to ensure we don't store any duplicate common elements
        int i = 0, j = 0, k = 0;

        while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                st.insert(arr1[i]);   // store this element in set, then move all pointers
                i++;
                j++;
                k++;
            } 
            else if(arr1[i] < arr2[j]) i++;   // if element pointed by i is smaller, then move i
            else if(arr2[j] < arr3[k]) j++;   // if element pointed by j is smaller, then move j
            else k++;   // if element pointed by k is smaller, then move k
        }

        vector<int> commonElements(st.begin(), st.end());
        return commonElements;
    }

// -----------------------------------------------------------------------------------------------------------------

    // We can further space optimise it by discarding set. This is the best possible solution.
    // T.C: O(n1+n2+n3);   where n1, n2 and n3 are size of arr1, arr2 and arr3 respectively.
    // S.C: O(n)
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> commonElements;
        int i = 0, j = 0, k = 0;

        while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                // To avoid duplicates, only add if 'commonElements' is empty or the common element is not already in 'commonElements'
                if(commonElements.empty() || commonElements.back() != arr1[i]) commonElements.push_back(arr1[i]);
                i++;
                j++;
                k++;
            } 
            else if(arr1[i] < arr2[j]) i++;   // if element pointed by i is smaller, then move i
            else if(arr2[j] < arr3[k]) j++;   // if element pointed by j is smaller, then move j
            else k++;   // if element pointed by k is smaller, then move k
        }

        return commonElements;
    }
};


int main() {
    vector<int> arr1 = {1, 1, 1, 2, 2, 2} , arr2 = {1, 1, 2, 2, 2}, arr3 = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> ans1 = Solution().commonElements_bruteforce(arr1, arr2, arr3);
    for(auto it: ans1) cout << it << " ";
    cout << endl;
    vector<int> ans2 = Solution().commonElements_timeOptimised(arr1, arr2, arr3);
    for(auto it: ans2) cout << it << " ";
    cout << endl;
    vector<int> ans3 = Solution().commonElements(arr1, arr2, arr3);
    for(auto it: ans3) cout << it << " ";

    return 0;
}
