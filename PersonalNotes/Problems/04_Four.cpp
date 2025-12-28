#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int OFFSET = 150;

    // dp[pos][diff][st][par][has2]
    long long dp[20][300][2][2][2];
    bool seen[20][300][2][2][2];
    string s;

    long long dfs(
        int pos,
        int diff,
        bool tight,
        bool st,
        int par,   // 0 = odd position, 1 = even position
        bool has2     // length >= 2
    ) {
        if (pos == s.size()) {
            return (st && has2 && diff == OFFSET) ? 1 : 0;
        }

        if (!tight && seen[pos][diff][st][par][has2]) {
            return dp[pos][diff][st][par][has2];
        }

        long long res = 0;
        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; ++d) {
            bool nst = st || d != 0;
            int ndiff = diff;
            int npar = par;
            bool nhas2 = has2;

            if (nst) {
                if (par == 0) ndiff += d;
                else ndiff -= d;

                npar ^= 1;
                if (st) nhas2 = true;
            }

            res += dfs(pos + 1, ndiff, tight && d == lim, nst, npar, nhas2);
        }

        if (!tight) {
            seen[pos][diff][st][par][has2] = true;
            dp[pos][diff][st][par][has2] = res;
        }

        return res;
    }

    long long cntUpTo(long long x) {
        if (x < 10) return 0;
        s = to_string(x);
        memset(seen, 0, sizeof(seen));
        return dfs(0, OFFSET, true, false, 0, false);
    }

public:
    long long countBalanced(long long low, long long high) {
        if (low > high) return 0;
        return cntUpTo(high) - cntUpTo(low - 1);
    }
};


int main() {
    int l1 = 1, h1 = 100;
    cout << Solution().countBalanced(l1, h1) << endl;  // 9

    int l2 = 120, h2 = 129;
    cout << Solution().countBalanced(l2, h2) << endl;  // 1

    int l3 = 1234, h3 = 1234;
    cout << Solution().countBalanced(l3, h3) << endl;  // 0

    int l4 = 50948, h4 = 62036;
    cout << Solution().countBalanced(l4, h4) << endl;   // 490
    
    return 0;
}
