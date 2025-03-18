// It is a follow-up of the previous problem '20_AlienDictionaryI.cpp'.
// We are asked to return an empty string if ordering of alphabets is not possible.

// Algorithm: There will be only two cases when ordering of alphabets is not possible:
// Case 1: If input provided is not in lexicographical order.
//         Example: {"abc", "ab"}.
//         Here, we can see "abc" stands before "ab" which is lexicographically incorrect.
//         In lexicographical order, shorter words come before longer words if one is a prefix of the other.
// Case 2: If input array of strings have cyclic dependency.
//         Example: {"abc", "bcd", "aef"}.
//         On building the graph of the above array of string, we find that 'a' and 'b' form a cyclic dependency.
//         a --> b
//         /\    |
//         |_____|
//         Thus, their ordering is not possible.

// The modified code would look like this:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int inDegree[V] = {0};

        for(int i = 0; i < V; i++) {
            for(int neighbour: adj[i]) inDegree[neighbour]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(int neighbour: adj[front]) {
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) q.push(neighbour); 
            }
        }

        // If topological sort is not possible, i.e., cycle exists in graph, return an empty vector
        if(ans.size() != V) return {};
        return ans;
    }

public:
    // T.C: O(n*L + k + E)
    // S.C: O(k+E)
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];

        for(int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());

            // Check for lexicographical error: If s1 is longer than s2 and s1 is a prefix of s2
            if(s1.size() > s2.size() && s1.substr(0, len) == s2) return "";

            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                } 
            }
        }

        vector<int> topo = topoSort(k, adj);
        if(topo.size() == 0) return "";   // if topological sort was not possible, return empty string right from here

        string ans = "";
        for(int it: topo) {
            ans = ans + char(it + 'a');
        }

        return ans;
    }
};


int main() {
    // string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    // int n = 5;
    // int k = 4;

    // string dict[] = {"abc", "ab"};
    // int n = 2;
    // int k = 3;

    string dict[] = {"abc", "bcd", "aef"};
    int n = 3;
    int k = 3;

    string ans = Solution().findOrder(dict, n, k);
    if(ans.length() == 0) cout << "Ordering not possible";
    else cout << ans;

    return 0;
}
