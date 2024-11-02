// Leetcode: 15. 3Sum   --->   Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^3)
    // S.C: O(2n)
    vector<vector<int>> threeSum_bruteforce(vector<int>& nums) {
        set<vector<int>> st;   // set in order to store only unique vectors
        
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        // vector<vector<int>> ans;
        // for(auto it: st) ans.push_back(it);

        // The above 2 lines can be done in 1 single line
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }

// ------------------------------------------------------------------------------

    // Better algorithm: Two-pointer approach using hashing or hash set, i.e., unordered_set
    // 1. i)  Initialize 'i' as the fixed element (starting from the first element). Initialize 'j' to start from 'i + 1'.
    //        'nums[i]' represents the first element, and 'nums[j]' represents the second element in the triplet.
    //        Calculate the required third element as the negative sum of 'nums[i]' and 'nums[j]' because the sum of
    //        all three elements should equal zero.
    //    ii) Instead of finding the third element using a nested loop, we use a hashset for quick lookup.
    //        Create an empty hashset for each iteration of 'i'. The purpose of 'hashset' is to store elements between
    //        'nums[i]' and 'nums[j]' as 'j' iterates through 'nums'.
    //        Each time 'i' is updated, a new hashset is initialized to avoid interference between triplet searches.
    // 2. If the third element is found in the hashset, then sort and store the triplet '{nums[i], nums[j], third}'
    //    in a set to ensure unique triplets, and then move j ahead. If the third element is not found in the hashset, then
    //    insert the current 'nums[j]' into the hashset and move 'j' ahead. Continue this process until the end of 'nums'.
    // T.C: O(n^2);   as hash operations like find() and insert() takes constant time in average case.
    // S.C: O(2n)
    vector<vector<int>> threeSum_twopointer(vector<int>& nums) {
        set<vector<int>> st;

        for(int i = 0; i < nums.size() - 1; i++) {
            unordered_set<int> hashset;
            for(int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]);
                // If third element is present in hashset, it means a triplet can be formed using 'nums[i]', 'nums[j]'
                // and third element. Thus, sort and store the triplet in a set to store only unique triplets.
                // If the third element is not found in hashset, then store the current element 'nums[j]' in hashset.
                if(hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

// ---------------------------------------------------------------------------------------

    
    // T.C: O(n^2)
    // S.C: O(2n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    }
};


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // vector<vector<int>> ans = Solution().threeSum_bruteforce(nums);
    vector<vector<int>> ans = Solution().threeSum_twopointer(nums);

    for(auto it1: ans) {
        for(auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
