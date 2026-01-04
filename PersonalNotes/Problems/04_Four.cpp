#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRoutes(vector<string>& grid, int d) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<long long> up(m, 0), same(m, 0);

        for (int j = 0; j < m; j++)
            if (grid[n - 1][j] == '.') up[j] = 1;

        int dxSame = d;
        int dxUp = (d * d >= 1) ? (int)sqrt(1LL * d * d - 1) : -1;

        for (int r = n - 1; r > 0; r--) {
            vector<long long> nup(m, 0), nsame(m, 0);
            vector<long long> pUp(m + 1, 0), pAll(m + 1, 0);

            for (int j = 0; j < m; j++) {
                pUp[j + 1] = (pUp[j] + up[j]) % MOD;
                pAll[j + 1] = (pAll[j] + up[j] + same[j]) % MOD;
            }

            // same row (only from up)
            for (int j = 0; j < m; j++) {
                if (grid[r][j] == '#') continue;
                int L = max(0, j - dxSame);
                int R = min(m - 1, j + dxSame);
                nsame[j] = (pUp[R + 1] - pUp[L] + MOD) % MOD;
            }

            // move up (from both)
            if (dxUp >= 0) {
                for (int j = 0; j < m; j++) {
                    if (grid[r - 1][j] == '#') continue;
                    int L = max(0, j - dxUp);
                    int R = min(m - 1, j + dxUp);
                    nup[j] = (pAll[R + 1] - pAll[L] + MOD) % MOD;
                }
            }

            up.swap(nup);
            same.swap(nsame);
        }

        long long ans = 0;
        for (int j = 0; j < m; j++)
            ans = (ans + up[j] + same[j]) % MOD;

        return ans;
    }
};



int main() {
    
    
    
    return 0;
}
