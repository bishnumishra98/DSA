// Part I:
// Find the length of the Longest Increasing Subsequence (LIS).

// Example 1:
// Input: nums = [10, 9, 2, 5, 3, 7, 1, 18]
// Output: 4
// Explanation: The longest increasing subsequence is [2, 3, 7, 18], therefore the length is 4.

// Example 2:
// Input: nums = [0, 1, 0, 3, 2, 3]
// Output: 4

// Example 3:
// Input: nums = [7, 7, 7, 7, 7, 7, 7]
// Output: 1

// ----------------------------------------------------------------------------------------------------

// Part II:
// Find any one of the Longest Increasing Subsequence (LIS).

// Example 1:
// Input: nums = [10, 9, 2, 5, 3, 7, 1, 18]
// Output: [2, 3, 7, 18]

// Example 2:
// Input: nums = [0, 1, 0, 3, 2, 3]
// Output: [0,  1,  2,  3]

// Example 3:
// Input: nums = [7, 7, 7, 7, 7, 7, 7]
// Output: [7]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: It is a simple algorithm. Create a dp array of size 'n', where n = nums.size(). Now each cell of dp[i]
//            will store the length of the longest increasing subsequence that ends at 'i'th index. It can be found
//            out very easily by adding 1 (for the element itself, i.e., for nums[i]) to the maximum of all the dp[j]
//            values where j < i and nums[j] < nums[i].
//            For example:- Consider the 'nums' array = [10, 9, 2, 5, 3, 7, 1, 18]
//            dp array for the above 'nums' array =     [1,  1, 1, 2, 2, 3, 1, 4]
//            Hence, the length of the longest increasing subsequence will be the maximum value in the dp array, i.e., 4.

// ● How to compute dp array ?
//   Computing dp array is very simple.
//   1. Initialize all elements of dp array with 1, stating that all elements are treated as equal elements in the
//      beginning, i.e., LIS of 'nums' is 1 till all indexes initially.
//   2. Now start the traversal from 0th index to (n - 1)th index. As no element are on left of nums[0], dp[0] will
//      remain 1 as it was, meaning length of LIS of 'nums' till index 0 is 1.
//   3. Now come to second element. If nums[1] > nums[0], then LIS till index 1 will be: 1 + LIS till index 0, i.e.,
//      dp[1] = 1 + dp[0] = 1 + 1 = 2. If nums[1] <= nums[0], then an increasing subsequence cannot be formed by taking
//      nums[0] and nums[1], hence keep dp[1] as 1 as it was initially.
//   4. Now come to third element. If nums[2] > nums[0], then dp[2] = 1 + dp[0], else 1 as it was initially.
//      Now check if nums[2] > nums[1]. If it is, then dp[2] is supposed to be 1 + dp[1]. But we will only consider
//      updating dp[2] only if '1 + dp[1]' is greater than the existing dp[2] value already obtained from 1 + dp[0].
//      In short make sure dp[i] gets its value from the largest dp[j] where j < i, and nums[j] < nums[i].
//      Follow the same pattern till the index 'n - 1'.

// T.C: O(n^2)
// S.C: O(n)
int findLISLength(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    int maxi = 1;

    for(int i = 1; i < n; i++) {   // 'i' represents the current element
        for(int j = 0; j < i; j++) {   // 'j' represents all elements towards left of 'i'
            if(nums[i] > nums[j]) {
                // Update dp[i] only if a larger value is supposed to be computed from '1 + dp[j]'
                if(1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
        }
        // Store the largest dp element found so far
        if(dp[i] > maxi) {
            maxi = dp[i];
        }
    }

    return maxi;
}

// ----------------------------------------------------------------------------------------------------

// Algorithm: It's very simple. To find out the elements of LIS, we need to create one more array lets say named 'hash',
//            of length 'n', where n = nums.size(). The purpose of this 'hash' array is to store the index of its parent,
//            where parent is the element of the dp array using whose value it computed itself, i.e., parent is nothing
//            but the index of the largest dp[j] element where j < i, and nums[j] < nums[i].
//            Once you have this 'hash' array, start backtracking from the largest dp element (as LIS ends at the
//            largest dp element) with taking reference from the 'hash' array, and store the result in an array lets
//            say 'ans'. The 'ans' will contain all elements of LIS in the reverse order, thus reverse it and return.
//            Example:- nums = [10, 9, 2, 5, 3, 7, 1, 18]
//                      dp =   [1,  1, 1, 2, 2, 3, 1, 4]
//                      hash = [0,  1, 2, 2, 2, 3, 6, 5]   // those who did not came from anywhere are parent of themselves
//            The maximum value in dp array is 4, i.e., LIS of 'nums' is 4. It means LIS will end at index 7. Thus, start
//            backtracking from index 7. index 7 came from index 5, index 5 came from 3, index 3 came from 2, index 2 came
//            from itself only, so stop here.
//            index 7 <--- index 5 <--- index 3 <--- index 2
//            18      <--- 7       <--- 5       <--- 2
//            If you reverse the order, elements of the LIS are: {2, 5, 7, 18}

// T.C: O(n^2)
// S.C: O(n)
vector<int> findLIS(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    vector<int> hash(n);   // to store the parents of each element
    for(int i = 0; i < n; i++) hash[i] = i;   // initially all elements are parents of themselves

    int maxi = 1;
    int lastIndex = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                if(1 + dp[j] > dp[i]) {
                    hash[i] = j;   // update i's parent as j
                    dp[i] = 1 + dp[j];
                }
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;   // update lastIndex to the index of the largest dp element found so far
        }
    }

    vector<int> ans;   // to store the elements of LIS

    // As we are going to build the LIS in reverse order, first push the element at index of the largest dp element
    ans.push_back(nums[lastIndex]);

    // Now backtrack using the hash array to find other elements of LIS, until we reach the index of the element
    // which is parent of itself, i.e., hash[lastIndex] == lastIndex
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];   // update lastIndex with its parent, i.e., move back to the index from lastIndex came
        ans.push_back(nums[lastIndex]);   // push the element at the new lastIndex to the ans array
    }

    reverse(ans.begin(), ans.end());   // reverse the ans array to get the LIS in correct order
    return ans;
}


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 1, 18};

    cout << findLISLength(nums) << endl;

    vector<int> lis = findLIS(nums);
    for(auto it: lis) cout << it << " ";

    return 0;
}
