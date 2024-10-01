// GFG: Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
// A bipartite graph is a graph where no two adjacent nodes have same color.
// Problem link: https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

// Observations(Observations have no link with algorithm. Its just for general knowledge) :
// 1) A graph that has no cycles is always bipartite.
// 2) A graph having even no.of nodes in a cycle is always bipartite.
// 3) A graph having odd no.of nodes in a cycle is always non-bipartite.

// Algorithm: We can use any approach BFS or DFS. This algorithm illustrates BFS technique.
// 1. a) Create a color array of size as many nodes in the graph, initialized all elements with -1 representing the node is uncolored.
//       We will be using the color conventions 0 and 1 to mark colors in the nodes.
//    b) Create a blank queue.
// 2. Starting with a node, mark it with a color(say 0) and push it inside the queue.
// 3. Dequeue the front element of queue and push its neighbours in the queue if they are yet uncolored. Before pushing the neighbour
//    in the queue, make sure to color the neighbour with opposite color as that of the current node.
//    Else, if the neighbour of the current element is found to be colored, it means this node was traversed previously via some
//    other path, stating a cycle is present in this graph. Thus, check if the neighbour node's color is same as that of the
//    current node, simply return false stating that this graph is non-bipartite.
// 4. Repeat step 3 until the queue is empty. If the queue becomes empty, it means no two adjacent nodes had the same color.
//    Thus, return true stating that this graph is bipartite.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
	bool isBipartite(int V, vector<int>adj[]){
	    
	}
};

int main() {

    return 0;
}