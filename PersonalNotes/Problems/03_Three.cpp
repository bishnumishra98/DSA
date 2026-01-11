#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> mp;

        for (auto it : words) {
            string pattern;
            for (int i = 1; i < it.size(); i++) {
                int d = it[i] - it[i - 1];
                if (d < 0) d += 26;
                pattern.push_back(char('a' + d)); 
            }
            mp[pattern]++;
        }

        long long res = 0;
        for (auto it : mp) {
            long long c = it.second;
            if (c > 1) {
                res += c * (c - 1) / 2;
            }
        }
        return res;
    }
};


int main() {
    
    
    return 0;
}
