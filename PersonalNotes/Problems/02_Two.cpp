#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(nums.front(), nums.back());
    }
};


int main() {
    vector<int> nums1 = {11, 4, 5};
    cout << Solution().finalElement(nums1) << endl;   // 11

    vector<int> nums2 = {1, 5, 2};
    cout << Solution().finalElement(nums2) << endl;   // 2

    vector<int> nums3 = {3, 7};
    cout << Solution().finalElement(nums3) << endl;   // 7
    

    return 0;
}
