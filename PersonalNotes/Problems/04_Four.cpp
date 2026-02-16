#include <bits/stdc++.h>
using namespace std;

// class TrieNode {
// public:
//     TrieNode* children[2];
//     int count; // To track how many prefixXORs are in this branch
//     TrieNode() {
//         children[0] = children[1] = nullptr;
//         count = 0;
//     }
// };

// class Trie {
//     TrieNode* root;
// public:
//     Trie() { root = new TrieNode(); }

//     void insert(int val) {
//         TrieNode* curr = root;
//         for (int i = 15; i >= 0; --i) {
//             int bit = (val >> i) & 1;
//             if (!curr->children[bit]) curr->children[bit] = new TrieNode();
//             curr = curr->children[bit];
//             curr->count++;
//         }
//     }

//     void remove(int val) {
//         TrieNode* curr = root;
//         for (int i = 15; i >= 0; --i) {
//             int bit = (val >> i) & 1;
//             curr = curr->children[bit];
//             curr->count--;
//         }
//     }

//     int query(int val) {
//         TrieNode* curr = root;
//         int max_xor = 0;
//         for (int i = 15; i >= 0; --i) {
//             int bit = (val >> i) & 1;
//             // Try to go the opposite path to maximize XOR
//             if (curr->children[1 - bit] && curr->children[1 - bit]->count > 0) {
//                 max_xor |= (1 << i);
//                 curr = curr->children[1 - bit];
//             } else if (curr->children[bit] && curr->children[bit]->count > 0) {
//                 curr = curr->children[bit];
//             } else {
//                 return 0; // Should not happen with prefixXOR logic
//             }
//         }
//         return max_xor;
//     }
// };

// class Solution {
// public:
//     int maxXor(vector<int>& nums, int k) {
//         int n = nums.size();
//         int left = 0, maxResult = 0;
//         int currentXor = 0;
        
//         Trie trie;
//         multiset<int> window;
//         vector<int> prefixXors(n + 1, 0);

//         // Standard trick: include 0 in Trie to handle subarrays starting at index 0
//         trie.insert(0); 

//         for (int right = 0; right < n; ++right) {
//             currentXor ^= nums[right];
//             prefixXors[right + 1] = currentXor;
//             window.insert(nums[right]);

//             // Maintain the bounded range condition
//             while (*window.rbegin() - *window.begin() > k) {
//                 // Remove the prefixXOR corresponding to the element we are dropping
//                 trie.remove(prefixXors[left]);
//                 window.erase(window.find(nums[left]));
//                 left++;
//             }

//             // Query Trie for the best partner to currentXor in the valid window
//             maxResult = max(maxResult, trie.query(currentXor));
            
//             // Add the current prefixXor for future queries
//             trie.insert(currentXor);
//         }

//         return maxResult;
//     }
// };


struct Node {
    Node* child[2] = {nullptr, nullptr};
    int count = 0;
};

class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }

    void update(int val, int delta) {
        Node* curr = root;
        for (int i = 15; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (!curr->child[bit]) curr->child[bit] = new Node();
            curr = curr->child[bit];
            curr->count += delta;
        }
    }

    int query(int val) {
        Node* curr = root;
        int res = 0;
        for (int i = 15; i >= 0; --i) {
            int bit = (val >> i) & 1;
            // Greedily pick the opposite bit to maximize XOR
            if (curr->child[1 - bit] && curr->child[1 - bit]->count > 0) {
                res |= (1 << i);
                curr = curr->child[1 - bit];
            } else if (curr->child[bit] && curr->child[bit]->count > 0) {
                curr = curr->child[bit];
            } else {
                return 0; 
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size();
        Trie trie;
        deque<int> minQ, maxQ;
        
        int left = 0;
        int currentXor = 0;
        int ans = 0;
        
        vector<int> pref(n + 1, 0);
        trie.update(0, 1); // Base case for subarrays starting at index 0

        for (int right = 0; right < n; ++right) {
            currentXor ^= nums[right];
            pref[right + 1] = currentXor;

            // Maintain max/min deques
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[right]) maxQ.pop_back();
            while (!minQ.empty() && nums[minQ.back()] >= nums[right]) minQ.pop_back();
            maxQ.push_back(right);
            minQ.push_back(right);

            // Shrink window if max - min > k
            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                trie.update(pref[left], -1); // Remove starting prefix from Trie
                left++;
                if (maxQ.front() < left) maxQ.pop_front();
                if (minQ.front() < left) minQ.pop_front();
            }

            // Get max possible XOR for current prefix
            ans = max(ans, trie.query(currentXor));
            
            // Add current prefix to Trie for future subarrays
            trie.update(currentXor, 1);
        }

        return ans;
    }
};


int main() {
    vector<int> nums1 = {5, 4, 5, 6};
    int k1 = 2;
    cout << Solution().maxXor(nums1, k1) << endl;   // 7

    vector<int> nums2 = {5, 4, 5, 6};
    int k2 = 1;
    cout << Solution().maxXor(nums2, k2) << endl;   // 6

    return 0;
}
