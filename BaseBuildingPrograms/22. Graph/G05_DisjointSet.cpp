// A Disjoint Set (also called Union-Find or Disjoint Set Union (DSU)) is a data structure that helps efficiently
// manage and merge disjoint (non-overlapping) sets. It is commonly used in graph algorithms to detect cycles,
// find connected components, and implement Minimum Spanning Trees (MST) using Kruskal’s Algorithm.
// It supports two primary operations efficiently:
// 1. FindParent (or Find-Set): Determines which set a particular element belongs to.
// 2. Union: Merges two disjoint sets into a single set. Union can be done by both rank and size.
//    • Union by rank:    This function optimizes the Union operation by always attaching the tree with lower rank (height)
//                        under the tree with higher rank. This prevents unnecessary tree height growth.
//    • Union by size:    This function is similar to Union by Rank but instead of tracking tree height (rank), it tracks
//                        the number of nodes in each set. The smaller tree is always attached under the larger tree to
//                        keep the overall structure balanced. This is more meaningful than Union by Rank.
//    • Path compression: Path Compression is an optimization technique in the FindParent() operation of the
//                        Disjoint Set data structure. It flattens the structure of the tree whenever findParent(node)
//                        is called by making every node in the path directly point to the root (ultimate parent).
//                        This significantly speeds up future operations by reducing the tree height.

// Time Complexity Analysis ---
// Operation	Without Optimizations	With Path Compression & Union by Rank/Size
// FindParent   O(n)	                O(α(n)) ≈ O(1)
// Union	    O(n)	                O(α(n)) ≈ O(1)


#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank, size;

public:
    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);   // considering 1 based indexing in graph. It will work for both 0 based and 1 based indexing graph.
        rank.resize(n + 1, 0);   // rank is initially 0 for all nodes
        size.resize(n + 1, 1);   // size is initially 1 for all nodes
        for(int i = 0; i <= n; i++) {
            parent[i] = i;   // each element is its own parent initially
        }
    }

    // Find function with Path Compression
    int findParent(int node) {
        if(node == parent[node]) return node;   // base case: return the node which is parent of itself, it is the ultimate parent
        return parent[node] = findParent(parent[node]);   // path compression: store ultimate parent of node in the 'parent' array
    }

    // Union by Rank
    void unionByRank(int u, int v) {
        int root_u = findParent(u);   // find ultimate parent of u and store it
        int root_v = findParent(v);   // find ultimate parent of v and store it

        if(root_u == root_v) return;   // just return if both 'u' and 'v' belong to the same component, no need of any union
        else if(rank[root_u] < rank[root_v]) {   // if rank of 'root_u' < rank of 'root_v', attach 'root_u' under 'root_v'
            parent[root_u] = root_v;
        } else if(rank[root_v] < rank[root_u]) {   // if rank of 'root_v' < rank of 'root_u', attach 'root_v' under 'root_u'
            parent[root_v] = root_u;
        } else {   // if rank of 'root_u' and rank of 'root_v' are equal, we can attach any root under any root
            // For instance, attaching 'root_u' under 'root_v'. Thus, rank[root_v] increases by 1.
            parent[root_u] = root_v;
            rank[root_v]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int root_u = findParent(u);   // find ultimate parent of u and store it
        int root_v = findParent(v);   // find ultimate parent of v and store it

        if(root_u == root_v) return;   // just return if both 'u' and 'v' belong to the same component, no need of any union
        
        // If tree of 'root_u' is shorter than that of 'root_v', then attach 'root_u' to 'root_v' and increase the tree size
        // of 'root_v' by 'root_u', else if tree of 'root_u' is equal or greater than that of tree of 'root_v', do the viceversa.
        if(size[root_u] < size[root_v]) {   
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {   // if(size[root_v] <= size[root_u])
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

int main() {
    DisjointSet ds1(7), ds2(7);   // initialize a Disjoint Set with 7 elements (node 1 to node 7)

    ds1.unionByRank(1, 2);
    ds1.unionByRank(2, 3);
    ds1.unionByRank(4, 5);
    ds1.unionByRank(6, 7);
    ds1.unionByRank(5, 6);

    if(ds1.findParent(3) == ds1.findParent(7)) cout << "3 and 7 belong to same component" << endl;
    else cout << "3 and 7 do not belong to same component" << endl;

    ds1.unionByRank(3, 7);

    if(ds1.findParent(3) == ds1.findParent(7)) cout << "3 and 7 belong to same component" << endl;
    else cout << "3 and 7 do not belong to same component" << endl;


    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    ds2.unionBySize(6, 7);
    ds2.unionBySize(5, 6);

    if(ds2.findParent(3) == ds2.findParent(7)) cout << "3 and 7 belong to same component" << endl;
    else cout << "3 and 7 do not belong to same component" << endl;

    ds2.unionBySize(3, 7);

    if(ds2.findParent(3) == ds2.findParent(7)) cout << "3 and 7 belong to same component" << endl;
    else cout << "3 and 7 do not belong to same component" << endl;
    
    return 0;
}
