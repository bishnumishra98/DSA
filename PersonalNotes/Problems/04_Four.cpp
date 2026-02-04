// file: solution.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        const int LT = 0, GT = 1;

        vector<array<int,2>> dp0(n, {1,1});
        vector<array<int,2>> dp1(n, {1,1});

        int ans = 1;

        for (int i = 1; i < n; i++) {
            // ---- dp0 (no removal) ----
            if (nums[i] > nums[i-1]) {
                dp0[i][GT] = dp0[i-1][LT] + 1;
            } else if (nums[i] < nums[i-1]) {
                dp0[i][LT] = dp0[i-1][GT] + 1;
            }

            // ---- dp1: removal already used ----
            if (nums[i] > nums[i-1]) {
                dp1[i][GT] = dp1[i-1][LT] + 1;
            } else if (nums[i] < nums[i-1]) {
                dp1[i][LT] = dp1[i-1][GT] + 1;
            }

            // ---- dp1: remove nums[i-1] now ----
            if (i >= 2) {
                if (nums[i] > nums[i-2]) {
                    dp1[i][GT] = max(dp1[i][GT], dp0[i-2][LT] + 1);
                } else if (nums[i] < nums[i-2]) {
                    dp1[i][LT] = max(dp1[i][LT], dp0[i-2][GT] + 1);
                }
            }

            ans = max({
                ans,
                dp0[i][LT], dp0[i][GT],
                dp1[i][LT], dp1[i][GT]
            });
        }

        return ans;
    }
};


int main() {
    vector<int> nums1 = {2, 1, 3, 2};
    cout << Solution().longestAlternating(nums1) << endl;   // 4

    vector<int> nums2 = {3, 2, 1, 2, 3, 2, 1};
    cout << Solution().longestAlternating(nums2) << endl;   // 4

    vector<int> nums3 = {100000, 100000};
    cout << Solution().longestAlternating(nums3) << endl;   // 1

    vector<int> nums4 = {1, 2, 3};
    cout << Solution().longestAlternating(nums4) << endl;   // 2

    vector<int> nums5 = {1, 2, 2, 2, 1};
    cout << Solution().longestAlternating(nums5) << endl;   // 2


    return 0;
}
