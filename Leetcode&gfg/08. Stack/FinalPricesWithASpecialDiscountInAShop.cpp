// Leetcode: 1475. Final Prices With a Special Discount in a Shop   --->   You are given an
// integer array prices where prices[i] is the price of the ith item in a shop.
// There is a special discount for items in the shop. If you buy the ith item, then you will
// receive a discount equivalent to prices[j] where j is the minimum index such that j > i and
// prices[j] <= prices[i]. Otherwise, you will not receive any discount at all. Return an
// integer array answer where answer[i] is the final price you will pay for the ith item of
// the shop, considering the special discount.

// Example 1:
// Input: prices = [8,4,6,2,3]
// Output: [4,2,4,2,3]
// Explanation: 
// For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4,
// therefore, the final price you will pay is 8 - 4 = 4.
// For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2,
// therefore, the final price you will pay is 4 - 2 = 2.
// For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2,
// therefore, the final price you will pay is 6 - 2 = 4.
// For items 3 and 4 you will not receive any discount at all.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: [1,2,3,4,5]
// Explanation: In this case, for all items, you will not receive any discount at all.

// Example 3:
// Input: prices = [10,1,1,6]
// Output: [9,0,1,6]

// This problem is story version of 'BaseBuildingPrograms\14. Stack\S8_NextSmallerElement.cpp'.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public: 
    // T.C: O(n)
    // S.C: O(n)
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector <int> ans(n);
        stack <int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--) {
            int currElement = prices[i];

            while(currElement < st.top()) {   // CHANGE 1: Instead of '<=', use '<' because the
            // problem expects next smaller or equal element to be taken as discount
                st.pop();
            }

            ans[i] = st.top();

            st.push(currElement);

            // ADDITION 1 (final price = price of item - discount(next smaller or equal element))
            if(ans[i] == -1) {
                ans[i] = prices[i];
            } else {
                ans[i] = prices[i] - ans[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector <int> prices{10, 1, 1, 6};

    vector <int> ans = obj.finalPrices(prices);

    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
