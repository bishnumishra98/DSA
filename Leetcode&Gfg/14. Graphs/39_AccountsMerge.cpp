// Leetcode: 721. Accounts Merge   --->   Given a list of accounts where each element accounts{i] is a list of strings,
// where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of
// the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common
// email to both accounts. Note that even if two accounts have the same name, they may belong to different people as
// people could have the same name. A person can have any number of accounts initially, but all of their accounts
// definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the
// name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

// Example 1:
// Input:
// accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],
//             ["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output:
// [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],
//  ["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'],
// ['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
// would still be accepted.

// Example 2:
// Input:
// accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
//             ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
//             ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
// Output:
// [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
//  ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
//  ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

// Intuition and Approach:
// Consider the vector<vector<string>> accounts as a graph where each account is a node. Thus the graph consists of nodes
// from 0 to n - 1, where n is the number of accounts, i.e., accounts.size().
// Now if two accounts share a common email, then they should be connected to each other under a single parent node. Thus, we can
// use a disjoint set to group all the connected components of the graph. The disjoint set will help us find the parent of each
// account and merge the accounts that share a common email.

// Algorithm:
// 1. Create a disjoint set for all accounts in the graph.
// 2. Create a map with {string, int} as key value pair, to store the first occurrence of each email in the accounts vector.
//    The key will be the email and the value will be the index of the account in which the email first occurs. Now, if the
//    same email occurs in multiple accounts, we can group all such accounts under the same parent node(the node where the
//    email first occurred), with the help of unionByRank/unionBySize function of the disjoint set.
// 3. Now, group all the emails under their respective ultimate parent nodes in a vector<vector<string>> mergedMail.
//    Each index of the mergedMail will contain the list of grouped emails that should come under their respective parent node.
//    The index of the mergedMail where the list is empty, means that account is attached to a different parent node.
//    For example, for the Example 1,
//    accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],
//                ["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
//    the mergedMail will look like this:
//    {john_newyork@mail.com, johnsmith@mail.com, john00@mail.com} 
//    {}
//    {mary@mail.com} 
//    {johnnybravo@mail.com}
// 4. Finally, format the output in the required format and return it. The required format is that the first element of each
//    account is the name of the account holder and the rest of the elements are the emails of that account holder in sorted order.
//    i.   Thus, we can create a vector<vector<string>> ans to store the final output.
//    ii.  Traverse the mergedMail vector and for each index, if the list is empty, skip the iteration and move to next iteration.
//    iii. Sort the emails in the list in lexicographical order and create a temporary vector<string> temp to store the name of the
//         account holder and the emails of that account holder.
//    iv.  Push this temporary vector into the 'ans' and finally return the 'ans'.


#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if(root_u == root_v) return;
        else if(rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if(rank[root_v] < rank[root_u]) {
            parent[root_v] = root_u;
        } else {
            parent[root_u] = root_v;
            rank[root_v]++;
        }
    }
};

class Solution {
public:
    // T.C: O(n * m * log(m));   where n is the number of accounts and m is the maximum number of emails in an account
    // S.C: O(n + m)   for the disjoint set and the mapMailNode
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();   // number of accounts
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;   // maps mail to its first occurrence's account index

        // Step 1: Connect accounts that share the same email
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) {   // if email is seen for the first time,
                    mapMailNode[mail] = i;                         // map it to this account index
                } else {
                    ds.unionByRank(i, mapMailNode[mail]);   // if email already exists, union the two account indices
                }
            }
        }

        // Step 2: Group emails under their respective ultimate parent nodes
        vector<vector<string>> mergedMail(n);   // stores grouped emails
        for(auto it: mapMailNode) {
            string mail = it.first;
            int parentNode = ds.findParent(it.second);   // find the ultimate parent of this email
            mergedMail[parentNode].push_back(mail);   // add mail to its ultimate parent's list
        }

        // Step 3: Format the final output and return
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;   // skip empty lists
            sort(mergedMail[i].begin(), mergedMail[i].end());   // sort the emails in lexicographical order
            vector<string> temp;
            temp.push_back(accounts[i][0]);   // add the name of the account
            for(auto it: mergedMail[i]) {   // add the emails of the account
                temp.push_back(it);
            }
            ans.push_back(temp);   // add the account to the final answer
        }

        return ans;
    }
};

int main() {
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
                                       {"John","johnsmith@mail.com","john00@mail.com"},
                                       {"Mary","mary@mail.com"},
                                       {"John","johnnybravo@mail.com"}};

    vector<vector<string>> ans = Solution().accountsMerge(accounts);
    for(auto it1: ans) {
        for(auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
