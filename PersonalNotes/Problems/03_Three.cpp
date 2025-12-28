#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAllOneMultiple(int k) {
        // Impossible if k has factor 2 or 5
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int rem = 0;

        // At most k steps needed
        for (int len = 1; len <= k; ++len) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) {
                return len;
            }
        }

        return -1;
    }
};


int main() {
    int k1 = 2;
    cout << Solution().minAllOneMultiple(k1) << endl;
    
    return 0;
}
