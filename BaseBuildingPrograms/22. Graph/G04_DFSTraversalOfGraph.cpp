// DFS Traversal of Graph means to traverse depth wise, i.e., depth order traversal.
// Consider first element of graph be 0, second be 1, and so on. Thus, if number of nodes(n)
// in the graph is 5, the graph elements will be 0, 1, 2, 3 and 4.

// Example 1:
// Input: n = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
//      0
//     /|\
//    2 3 1
//    |
//    4
// Output: 0 2 4 3 1
// Explanation: 
// 0 is connected to 2, 3, 1.
// 1 is connected to 0.
// 2 is connected to 0 and 4.
// 3 is connected to 0.
// 4 is connected to 2.
// So starting from 0, it will go to 2 then 4, and then 3 and 1.
// Thus dfs will be 0 2 4 3 1.

// Example 2:
// Input: n = 4, adj = [[1,3], [2,0], [1], [0]]
//      0
//     / \
//    1   3
//     \
//      2
// Output: 0 1 2 3
// Explanation:
// 0 is connected to 1 , 3.
// 1 is connected to 0, 2. 
// 2 is connected to 1.
// 3 is connected to 0. 
// So starting from 0, it will go to 1 then 2 then back to 0 then 0 to 3.
// Thus dfs will be 0 1 2 3.

#include <iostream>
#include <vector>
using namespace std;

// T.C: 
// S.C: 
vector<int> dfsOfGraph(int V, vector<int> adj[]) {

}

int main() {

    return 0;
}
