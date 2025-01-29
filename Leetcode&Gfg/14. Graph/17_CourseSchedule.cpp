// Gfg: There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks,
// for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1].
// Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick
// to finish all tasks.
// Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks,
// return an empty array. Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order
// will give the output as 1, whereas any invalid order will give the output 0. 

// Example 1:
// Input:
// n = 2, m = 1
// prerequisites = {{1, 0}}
// Output:
// 1
// Explanation:
// The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1
// for all test cases. One possible order is [0, 1].

// Example 2:
// Input:
// n = 4, m = 4
// prerequisites = {{1, 0},
//                 {2, 0},
//                 {3, 1},
//                 {3, 2}}
// Output:
// 1
// Explanation:
// There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2
// should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is
// [0, 2, 1, 3]. Returning any of these order will result in an output of 1.

// Your Task:
// The task is to complete the function findOrder() which takes two integers n, and m and a list of lists of size m*2 denoting
// the prerequisite pairs as input and returns any correct order to finish all the tasks. Return an empty array if it's
// impossible to finish all tasks.

// Algorithm: The problem is extremely simple. Prepare a directed graph using the given prerequisites. If its a DAG, i.e.,
//            no cycles are present in the directed graph, all tasks can be ordered; else ordering of tasks is not possible.

// Illustration 1: For example, consider the prerequisites: 
// {{1, 0},
// {2, 0},
// {3, 1},
// {3, 2}}
// The edges of graph for the above prerequisite will be:
// 0 --> 1
// 0 --> 2
// 1 --> 3
// 2 --> 3
// Thus, the adjacent list for the graph will be: {{1, 2}, {3}, {3}, {}}.
// The graph for this would look like this:
//  ___________
// |           |
// |           \/
// 0 --> 1     2 --> 3
//       |          /\
//       |__________|
// Tasks can be finished in the order: 0, 1, 2, 3.

// Illustration 2: For example, consider the prerequisites: 
// {{1, 0},
// {2, 3},
// {3, 1},
// {3, 2}}
// The edges of graph for the above prerequisite will be:
// 0 --> 1
// 3 --> 2
// 1 --> 3
// 2 --> 3
// Thus, the adjacent list for the graph will be: {{1}, {3}, {3}, {2}}.
// The graph for this would look like this:
//              _____
//             |     |
//             \/    |
// 0 --> 1     2 --> 3
//       |          /\
//       |__________|
// Here we see that tasks 2 and 3 contradict with each each in the sense that who shall be executed first. In such conflicts, a
// cycle is always present in the directed graph. Hence, if a cycle is present in the directed graph, all tasks cannot be ordered.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n+m) or O(V+E)
    // S.C: O(n+m)
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        int V = n;   // no.of nodes in the graph
        vector<int> adj[V];   // create a adjacent list to prepare and store the graph

        // Creating adjacent list for the graph, from the given prerequisites
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Kahn's algorithm --->
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

        // If no cycles present in graph, its a DAG. In a DAG, no.of elements in the topological sorted array is awlays
        // equal to the no.of nodes in the graph. So all tasks can be finished in this case. Hence, return the
        // order of exceution of tasks stored in the 'ans' array; else return a blank array.
        if(ans.size() == V) return ans;
        else return {};
    }
};


int main() {
    int n = 4, m = 4;
    vector<vector<int>> prerequisites = {{1, 0},
                                         {2, 0},
                                         {3, 1},
                                         {3, 2}};
    vector<int> ans = Solution().findOrder(n, m, prerequisites);
    if(ans.size() == 0) cout << "No Ordering Possible";
    for(int i: ans) cout << i << " ";

    return 0;
}
