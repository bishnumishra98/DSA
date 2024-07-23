#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>   // template class to represent a generalized data type graph
// Class to represent a graph
class Graph {
private:
    // Adjacency list using an unordered_map where the key is the node and the value is a list of adjacent nodes
    unordered_map<T, vector<T>> adjList;

public:
    // Function to add an edge to the graph
    void addEdge(T u, T v, bool direction) {   // direction true means directed graph, else undirected
        if(direction) adjList[u].push_back(v);   // add v to u’s list
        else {
            adjList[u].push_back(v);   // add v to u’s list
            adjList[v].push_back(u);  // since the graph is undirected, add u to v's list as well
        }
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for(auto pair: adjList) {
            cout << pair.first << " -> ";
            for(auto element: pair.second) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    /*
    Graph<int> g;   // create a graph object of type int
    
    bool directed = false;   // directed 'true' means a directed graph; and false means an undirected graph.
    // Add edges
    g.addEdge(0, 1, directed);
    g.addEdge(0, 4, directed);
    g.addEdge(1, 2, directed);
    g.addEdge(1, 3, directed);
    g.addEdge(1, 4, directed);
    g.addEdge(2, 3, directed);
    // The above graph looks like this:
    //     0
    //    / \
    //   1---4
    //  /|
    // 3 |
    //  \|
    //   2
    */

    Graph<char> g;   // create a graph object of type int
    
    bool directed = false;   // directed 'true' means a directed graph; and false means an undirected graph.
    // Add edges
    g.addEdge('a', 'b', directed);
    g.addEdge('a', 'e', directed);
    g.addEdge('b', 'c', directed);
    g.addEdge('b', 'd', directed);
    g.addEdge('b', 'e', directed);
    g.addEdge('c', 'd', directed);
    // The above graph looks like this:
    //     a
    //    / \
    //   b---e
    //  /|
    // d |
    //  \|
    //   c

    g.printGraph();   // print the adjacency list
    
    return 0;
}
