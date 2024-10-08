// GFG: Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
// Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1
// if the order of string returned by the function is correct else 0 denoting incorrect string returned.

// Examples 1:
// Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
// Output: 1
// Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa"
//              comes before "abcd", therefore 'b' is before 'a' in output. Similarly we can find other orders.

// Example 2:
// Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
// Output: 1
// Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes
//              before "aaa", therefore 'c' is before 'a' in output. Similarly we can find other orders.

// Algorithm: Algorithm is very simple.
// 1. Create a directed graph consisting of alphabet equivalent integers as nodes, from the given string array input.
//    Using kahn's algorithm, build a topological sorted array/string from the nodes. This topological sorted
//    array/string represents the the order of characters in the alien language.

// -> How to create nodes from the given input string ?
// -> Consider the string array:
//    s1: baa
//    s2: abcd
//    s3: abca
//    s4: cab
//    s5: cad
//    Here we have have to compare two strings at a time.
//    ◆ Consider s1 and s2, in "baa" and "abcd", we can clealy observe that alphabet 'b' comes before alphabet 'a'.
//       Thus, there will be an edge between the two alphabets where b points to a, i.e., b -> a.
//    ◆ Consider s2 ans s3, in "abcd" and "abca", the differntiating factor is 'd' and 'a'; which means 'd' comes before 'a'.
//       Thus, there will be an edge between the two alphabets where 'd' points to 'a', i.e., d -> a.
//    ◆ Consider s3 ans s4, in "abca" and "cab", we can clealy observe that alphabet 'a' comes before alphabet 'c'.
//       Thus, there will be an edge between the two alphabets where a points to c, i.e., a -> c.
//    ◆ Consider s4 ans s5, in "cab" and "cad", the differntiating factor is 'b' and 'd'; which means 'b' comes before 'd'.
//       Thus, there will be an edge between the two alphabets where 'b' points to 'd', i.e., b -> d.
//    Thus, our final graph would look like this:
//    b --> a --> c
//    |     /\
//    \/    |
//    d ----
// NOTE: Instead of a, b, c, d, etc; store nodes as 0, 1, 2, 3, 4, etc.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int inDegree[V] = {0};

        // Count the indegree of all nodes
        for(int i = 0; i < V; i++) {
            for(int neighbour: adj[i]) inDegree[neighbour]++;
        }

        queue<int> q;
        // Push the nodes with inDegree initially as 0, in the queue
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            // Once this node is popped out from queue, store it in an array, and also reduce the inDegree of all its adjacent node by 1.
            ans.push_back(front);

            for(int neighbour: adj[front]) {
                inDegree[neighbour]--;
                // After reducing inDegree of its adjacent nodes, if any node's inDegree becomes 0, push that node inside the queue.
                if(inDegree[neighbour] == 0) q.push(neighbour); 
            }
        }

        return ans;
    }

public:
    // T.C: O(n*L + k + E);   where n = no.of strings in 'dict', L = avg. length of strings, k = no.of alphabets or no.of nodes in graph,
    //                        E = no.of edges in the graph
    //                        Since there are n strings, and we compare consecutive pairs, the total time spent in this step is O(n*L).
    // S.C: O(k+E)
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];   // create an adjacency list(integer equivalent, ex: 'a' will be considered 0, 'b' as 1, etc)

        // Compare two strings at a time, and build the adjacency list from the given array of strings 'dict'
        for(int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());

            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');   // if any character at an index of 's1'
                    // and 's2' are not equal, it means that character of 's1' is supposed to be kept before that
                    // character of 's2' in the alien dictionary. Hence, s1[j] should point to s2[j].
                    break;   // once a differentiating alphabet is found, break the loop and proceed to compare the next string pair
                } 
            }
        }

        // Apply the usual Kahn's algorithm to find topological sort of the formed graph. Store the answer in a string and return.
        vector<int> topo = topoSort(k, adj);
        string ans = "";
        for(int it: topo) {
            ans = ans + char(it + 'a');
        }

        return ans;
    }
};


int main() {
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;
    int k = 4;

    cout << Solution().findOrder(dict, n, k);

    return 0;
}
