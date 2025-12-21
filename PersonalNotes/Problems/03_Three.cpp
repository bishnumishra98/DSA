#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();

        // ---------- Feasibility check ----------
        unordered_map<int,int> cntNums, cntForb;
        for (int i = 0; i < n; i++) {
            cntNums[nums[i]]++;
            cntForb[forbidden[i]]++;
        }
        for (auto &p : cntForb) {
            if (cntNums[p.first] > n - p.second)
                return -1;
        }

        // ---------- Min Cost Max Flow ----------
        struct Edge {
            int to, cap, cost;
            Edge* rev;
        };

        struct MinCostMaxFlow {
            int N;
            vector<vector<Edge*>> G;

            MinCostMaxFlow(int n) : N(n), G(n) {}

            void addEdge(int u, int v, int cap, int cost) {
                Edge* a = new Edge{v, cap, cost, nullptr};
                Edge* b = new Edge{u, 0, -cost, nullptr};
                a->rev = b;
                b->rev = a;
                G[u].push_back(a);
                G[v].push_back(b);
            }

            pair<int,int> run(int s, int t) {
                int flow = 0, cost = 0;
                const int INF = 1e9;

                while (true) {
                    vector<int> dist(N, INF);
                    vector<Edge*> parent(N, nullptr);
                    vector<bool> inq(N, false);
                    queue<int> q;

                    dist[s] = 0;
                    q.push(s);
                    inq[s] = true;

                    while (!q.empty()) {
                        int u = q.front(); q.pop();
                        inq[u] = false;
                        for (auto e : G[u]) {
                            if (e->cap > 0 && dist[e->to] > dist[u] + e->cost) {
                                dist[e->to] = dist[u] + e->cost;
                                parent[e->to] = e;
                                if (!inq[e->to]) {
                                    q.push(e->to);
                                    inq[e->to] = true;
                                }
                            }
                        }
                    }

                    if (!parent[t]) break;

                    int aug = INF;
                    for (int v = t; v != s; v = parent[v]->rev->to)
                        aug = min(aug, parent[v]->cap);

                    for (int v = t; v != s; v = parent[v]->rev->to) {
                        parent[v]->cap -= aug;
                        parent[v]->rev->cap += aug;
                        cost += aug * parent[v]->cost;
                    }

                    flow += aug;
                }
                return {flow, cost};
            }
        };

        // ---------- Build flow graph ----------
        int S = 2 * n;
        int T = 2 * n + 1;
        MinCostMaxFlow mcmf(2 * n + 2);

        // Source → value nodes
        for (int i = 0; i < n; i++) {
            mcmf.addEdge(S, i, 1, 0);
        }

        // Index nodes → sink
        for (int j = 0; j < n; j++) {
            mcmf.addEdge(n + j, T, 1, 0);
        }

        // Value → index edges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] != forbidden[j]) {
                    int moveCost = (i == j ? 0 : 1);
                    mcmf.addEdge(i, n + j, 1, moveCost);
                }
            }
        }

        // ---------- Run flow ----------
        auto result = mcmf.run(S, T);
        int flow = result.first;
        int cost = result.second;

        if (flow < n) return -1;

        // Each swap moves exactly 2 values
        return cost / 2;
    }
};






int main() {
    vector<int> nums1 = {1,2,3};
    vector<int> forbidden1 = {3,2,1};  // o/p: 1

    vector<int> nums2 = {4, 6, 6, 5};
    vector<int> forbidden2 = {4, 6, 5, 5};  // o/p: 2

    vector<int> nums3 = {7, 7};
    vector<int> forbidden3 = {8, 7};  // o/p: -1

    vector<int> nums4 = {41, 18, 19, 38, 38, 19};
    vector<int> forbidden4 = {22, 39, 19, 7, 39, 19};  // o/p: 3

    vector<int> nums5 = {420, 21, 15, 3};
    vector<int> forbidden5 = {20, 21, 15, 3};  // o/p: 2

    cout << Solution().minSwaps(nums1, forbidden1) << endl;
    cout << Solution().minSwaps(nums2, forbidden2) << endl;
    cout << Solution().minSwaps(nums3, forbidden3) << endl;
    cout << Solution().minSwaps(nums4, forbidden4) << endl;
    cout << Solution().minSwaps(nums5, forbidden5) << endl;

    return 0;
}
