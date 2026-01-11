#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long cost(long long x, long long target) {
        long long cur = x;
        for (int i = 0; i <= 30; i++) {
            if ((target >> i) & 1) {
                if (((cur >> i) & 1) == 0) {
                    long long step = 1LL << i;
                    cur = ((cur / step) + 1) * step;
                }
            }
        }
        return cur - x;
    }

    int maximumAND(vector<int>& nums, int k, int m) {
        long long ans = 0;

        for (int b = 30; b >= 0; b--) {
            long long candidate = ans | (1LL << b);
            vector<long long> costs;

            for (int x : nums) {
                costs.push_back(cost(x, candidate));
            }

            sort(costs.begin(), costs.end());

            long long used = 0;
            for (int i = 0; i < m; i++) {
                used += costs[i];
            }

            if (used <= k) {
                ans = candidate;
            }
        }
        return (int)ans;
    }
};



int main() {
    
    
    
    return 0;
}
