// Leetcode: 300. Longest Increasing Subsequence   --->   Given an integer array nums, return the length of the
// longest strictly increasing subsequence.

// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Brute force: The brute force approach is to generate all the subsequences of the given array and then check
//              which of them is strictly increasing and return the length of the longest one.
//              This approach has exponential time complexity and is not efficient for large inputs.

// Better approach: Follow 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_FindLongestIncreasingSubsequence.cpp'.

// Best approach: The problem can be solved using a greedy approach with binary search.

// Algorithm:
// 1. Create a temporary array lets say named 'temp'.
// 2. Push the first element of 'nums' in the 'temp' array.
// 3. Now iterate the 'nums' from second element to last element.
//    i.  If nums[i] is greater than the last element inserted in 'temp', then insert nums[i] in 'temp'. This will
//        create a set of numbers in increasing fashion.
//    ii. If nums[i] is not greater than the last element inserted in 'temp', then we need to find the index of the
//        smallest number in 'temp' which is greater than or equal to nums[i]. This is because we want to replace
//        the smallest number in 'temp' which is greater than or equal to nums[i] with nums[i] to maintain the
//        increasing order in 'temp'.
//        We can use the lower_bound() function from the STL to find this index. The lower_bound() function returns
//        an iterator to the first element in 'temp' which is not less than nums[i]. We can then subtract the
//        beginning of the 'temp' array from this iterator to get the index.
// 4. At the end, the size of 'temp' will give us the length of the longest increasing subsequence.
// Note: The 'temp' array may not contain the actual LIS. It is accurate in just telling the length of LIS.

// Dry run:
// Let's consider the array 'nums' = [0, 1, 0, 3, 2, 3]
// Now start traversal from 0th index of 'nums' till the last index and try to form multiple vectors that contains
// subsequences of 'nums'. And the longest of them is the required LIS of 'nums'.

// ● When we are at index 0, i.e., element = 0:
//   Push nums[0] in a vector v1, i.e., v1 = {0}.
//
// ● When we are at index 1, i.e., element = 1:
//   As nums[1] > last element of v1, we can push nums[1] in v1, i.e., v1 = {0, 1}.
//
// ● When we are at index 2, i.e., element = 0:
//   As nums[2] is not greater than last element of v1, we cannot push it in v1. In this case, we need to find
//   the smallest number in v1 which is greater than or equal to nums[2]. In this case, it is 0.
//   So, we replace the 0 of v1 with nums[2], i.e., v1 remains {0, 1}.
//
// ● When we are at index 3, i.e., element = 3:
//   As nums[3] > last element of v1, we can push nums[3] in v1, i.e., v1 = {0, 1, 3}.
//
// ● When we are at index 4, i.e., element = 2:
//   As nums[4] is not greater than last element of v1, we cannot push it in v1. In this case, we need to find
//   the smallest number in v1 which is greater than or equal to nums[4]. In this case, it is 3.
//   So, we replace the 3 of v1 with nums[4], i.e., v1 becomes {0, 1, 2}.
//
// ● When we are at index 5, i.e., element = 3:
//   As nums[5] > last element of v1, we can push nums[5] in v1, i.e., v1 becomes {0, 1, 2, 3}.
//
// At the end, the size of v1 is 4, which is the length of the longest increasing subsequence of 'nums'.

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    // T.C: O(n * log(n))
    // S.C: O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                // Find the index of the smallest number in 'temp' which is greater than or equal to 'nums[i]'.
                // lower_bound() returns an iterator to the first element that is not less than 'nums[i]'.
                // temp.begin() is subtracted from the iterator returned by lower_bound() to get the index.
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 2, 3};

    cout << Solution().lengthOfLIS(nums);

    return 0;
}


/*
// IMPORTANT NOTE: YOU MAY SKIP THE BELOW TAUGHT APPROACHES OF THIS PROBLEM. AN EASIER APPROACH FOR THE SAME PROBLEM
//                 IS TAUGHT IN 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_PrintLongestIncreasingSubsequence.cpp'.

// Brute force: The brute force approach is to generate all the subsequences of the given array and then check
//              which of them is strictly increasing and return the length of the longest one.
//              This approach has exponential time complexity and is not efficient for large inputs.

// Optimal algorithm: It is based on the same pattern as subsequence problems are, pick and not pick pattern.
//                    We have to find all possible ways to find the LIS using recursion.
//                    Call a function f(index, lastIndex) which returns the length of LIS starting from 'index'. The
//                    'lastIndex' is an additional argument passed to the function which is used to keep track of
//                    the index of last element that was included in the LIS. It helps in making sure that the next
//                    element to be inserted in the LIS is strictly greater than the last element inserted in the LIS.
//                    For illustration, f(3, 1) would mean that we are at 3rd index of 'nums', and the last element
//                    inserted in the LIS was element at 1st index of 'nums' array. Thus, if the element at 3rd index
//                    of 'nums' wants to get included in the LIS, it must be greater than the last element of the
//                    LIS which is 1st element of 'nums'.
//                    Start the recursive call with f(0, -1) meaning that we are starting to build the LIS from the
//                    first element of the array and there is no last element currently in the LIS.
// 1. Base case: It is very simple. When 'nums' gets exhausted, i.e., when 'index' reaches nums.size(), return 0 stating
//               that no more length of LIS can be formed.
// 2. Recursive relation: At any index, we just have two choice in hand, either include the element at that index in
//                        your LIS, or exclude it. Thus, there will be two simple recursive relations:
//    I.  Include the 'index'th element in LIS: If you choose to include the 'index'th element in the LIS, either of the
//                                              two conditions must be true. Either the previous index must point to -1
//                                              (case when we are at first element of the 'nums' array), or if 'index'th
//                                              element is greater than the 'lastIndex'th element (case when current
//                                              element is greater than the last element inserted in the LIS). If the
//                                              current element is valid to be included in the LIS, add 1 to the length
//                                              of the LIS as current element was included in LIS; and then call the next
//                                              recursive function for next element of 'nums' and update the 'lastIndex'
//                                              as 'index' because the current element is included in the LIS, hence it
//                                              becomes the last element included in the LIS, i.e., call
//                                              1 + f(index + 1, index) and store the length returned by it in a
//                                              variable say 'takeLen', meaning length of LIS if current element is taken
//                                              in the LIS.
//    II. Exclude the 'index'th element in LIS: If you choose to exclude the 'index'th element in the LIS, add 0 to the
//                                              length of LIS as current element was not included in LIS; and then call
//                                              the next recursive function for next element of 'nums' and keep the
//                                              'lastIndex' same as it was because no element is included in the LIS. Thus,
//                                              call 0 + f(index + 1, lastIndex) and store the length returned by it in a
//                                              variable say 'notTakeLen', meaning length of LIS if current element is not
//                                              taken in the LIS.
//    At the end, return the larger value returned by trying out both the above paths.

// ● How to memoize the above recursive code ?
//   As the index can take a value from 0 to n - 1, and the lastIndex can take values from -1 to n - 1 (where n is
//   the size of 'nums'), a 2D dp table of size (n x n + 1) is required to store the results of the recursive calls.
//   But the problem is that the lastIndex can take -1 as a value, but the dp table cannot have negative indices.
//   Thus, we can shift the lastIndex by 1, i.e., if last index is -1, we can store it as 0 in the dp table,
//   if last index is 0, we can store it as 1 in the dp table, and so on. Thus, the lastIndex will take values from
//   0 to n. Hence, the result of recursive call f(index, lastIndex) will be stored in dp[index][lastIndex + 1],
//   not dp[index][lastIndex].

// Note: One more way is there to find the LIS. And that way is the better way because that will also help in
//       figuring the elements of the LIS using backtracking. The time and space complexity of that algorithm
//       is O(n^2) and O(n) respectively, which is as good as tabulation space optimized code of this algorithm.
//       That algorithm can be found here: BaseBuildingPrograms\21. Dynamic_Programming\DP04_PrintLongestIncreasingSubsequence.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int lastIndex, vector<int>& nums, int n) {
        // Base case: If the 'nums' is exhausted, return 0 stating that no more length of LIS can be found
        if(index == n) return 0;

        int takeLen = 0;   // length of LIS if you include the 'index'th element in LIS
        if(lastIndex == -1 || nums[index] > nums[lastIndex]) {   // writing 'lastIndex == -1' first is mandatory
            takeLen = 1 + solve(index + 1, index, nums, n);
        }

        int notTakeLen = 0 + solve(index + 1, lastIndex, nums, n);   // length of LIS if you exclude the 'index'th element in LIS

        return max(notTakeLen, takeLen);
    }

    // T.C: O(2^n)   because for every element, we have two choices: either take it or not take it
    // S.C: O(n)   recursion stack space
    int lengthOfLIS_recursion(vector<int>& nums) {
        int n = nums.size();
        return solve(0, -1, nums, n);
    }

// -------------------------------------------------------------------------------------------------------------

    int solve(int index, int lastIndex, vector<int>& nums, int n, vector<vector<int>>& dp) {
        // Base case: If the 'nums' is exhausted, return 0 stating that no more length of LIS can be found
        if(index == n) return 0;

        if(dp[index][lastIndex + 1] != -1) return dp[index][lastIndex + 1];

        int takeLen = 0;
        if(lastIndex == -1 || nums[index] > nums[lastIndex]) {   // writing 'lastIndex == -1' first is mandatory
            takeLen = 1 + solve(index + 1, index, nums, n, dp);
        }

        int notTakeLen = 0 + solve(index + 1, lastIndex, nums, n, dp);

        return dp[index][lastIndex + 1] = max(notTakeLen, takeLen);
    }

    // T.C: O(n^n) = O(n^2)
    // S.C: O(n^2) for dp table + O(n) for recursion stack space = O(n^2)
    int lengthOfLIS_memoization(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, n, dp);
    }

// -------------------------------------------------------------------------------------------------------------

    // T.C: O(n^2)
    // S.C: O(n^2)
    int lengthOfLIS_tabulation(vector<int>& nums) {
        int n = nums.size();
        // As 'i' starts from 'n - 1', and we are accessing 'dp[i + 1][...]', i.e., 'i' starts from dp[n][...]
        // and ends at dp[0][...], we will require 'n + 1' rows to store all states of dp.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // No need to write base case as all cells are already initialized to 0.

        // As we did coordinate shift in memoization, add +1 to all column coordinates
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i - 1; j >= -1; j--) {
                int takeLen = 0;
                if(j == -1 || nums[i] > nums[j]) takeLen = 1 + dp[i + 1][i + 1];   // 'i + 1' due to coordinate shift during memoization
                int notTakeLen = 0 + dp[i + 1][j + 1];    // 'j + 1' due to coordinate shift during memoization
                dp[i][j + 1] = max(notTakeLen, takeLen);
            }
        }

        return dp[0][-1 + 1];   // as we did coordinate shift during memoization, we need to add +1 to column coordinates
    }

// -------------------------------------------------------------------------------------------------------------

    // T.C: O(n^2)
    // S.C: O(n)
    int lengthOfLIS_tabulation_SO(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(n + 1, 0), next(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i - 1; j >= -1; j--) {
                int takeLen = 0;
                if(j == -1 || nums[i] > nums[j]) takeLen = 1 + next[i + 1];
                int notTakeLen = 0 + next[j + 1];
                curr[j + 1] = max(notTakeLen, takeLen);
            }
            next = curr;
        }

        return next[-1 + 1];
    }
};


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << Solution().lengthOfLIS_recursion(nums) << endl;
    cout << Solution().lengthOfLIS_memoization(nums) << endl;
    cout << Solution().lengthOfLIS_tabulation(nums) << endl;
    cout << Solution().lengthOfLIS_tabulation_SO(nums);

    return 0;
}
*/
