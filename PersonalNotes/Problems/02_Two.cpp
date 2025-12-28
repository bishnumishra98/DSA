#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          long long need1, long long need2) {

        long long ans = LLONG_MAX;

        // Case 1: no shared items
        ans = min(ans, 1LL * need1 * cost1 + 1LL * need2 * cost2);

        // Case 2: shared covers all type1
        {
            long long k = need1;
            long long cost = 1LL * k * costBoth
                + 1LL * max(0LL, need2 - k) * cost2;
            ans = min(ans, cost);
        }

        // Case 3: shared covers all type2
        {
            long long k = need2;
            long long cost = 1LL * k * costBoth
                + 1LL * max(0LL, need1 - k) * cost1;
            ans = min(ans, cost);
        }

        return ans;
    }
};



int main() {
    int c1 = 3, c2 = 2, cB = 1, n1 = 3, n2 = 2;
    cout << Solution().minimumCost(c1, c2, cB, n1, n2) << endl;  // 3

    // int c1 = 5, c2 = 4, cB = 15, n1 = 0, n2 = 0;
    // cout << Solution().minimumCost(c1, c2, cB, n1, n2) << endl;  // 0

    // int c1 = 38, c2 = 6, cB = 6, n1 = 10, n2 = 8;
    // cout << Solution().minimumCost(c1, c2, cB, n1, n2) << endl;  // 60
    
    return 0;
}
