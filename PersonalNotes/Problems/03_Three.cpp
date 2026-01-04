#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        long long inf = 1e18;
        vector<long long> a(n, inf);

        a[0] = 0;

        for (int i = 0; i < restrictions.size(); i++) {
            int x = restrictions[i][0];
            int y = restrictions[i][1];
            if (a[x] > y) a[x] = y;
        }

        for (int i = 0; i + 1 < n; i++) {
            if (a[i + 1] > a[i] + diff[i]) a[i + 1] = a[i] + diff[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1] + diff[i]) a[i] = a[i + 1] + diff[i];
        }

        long long mx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) mx = a[i];
        }

        return (int)mx;
    }
};



int main() {
    
    
    return 0;
}
