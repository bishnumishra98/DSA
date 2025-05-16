// Strongly Connected Components (SSC) are are possible only in directed graphs. SSC is the portion of a
// directed graph where every vertex is reachable from every other vertex.
// The algorithm used to find SSCs in a graph is Kosaraju's algorithm, which is a two-pass algorithm.
// The first pass is a depth-first search (DFS) on the original graph to determine the finishing order of vertices.
// The second pass is a DFS on the transposed graph (the graph with all edges reversed) to discover the strongly
// connected components.
// The algorithm has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges.

// Example: [{2, 3}, {0}, {1}, {4}, {}]
//          0 __________
//       /\    |        |
//       |     |        |
//       |     \/       \/
//        /___ 2         3
//       1\              |
//                       |
//                       \/
//                       4

// In the above graph, there are three strongly connected components:
// 1. {0, 1, 2}
// 2. {3}
// 3. {4}
