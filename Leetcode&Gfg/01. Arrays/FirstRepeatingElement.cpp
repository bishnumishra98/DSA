// GFG: First Repeating Element   --->   Given an array arr[], find the first repeating element. The element should
// occur more than once and the index of its first occurrence should be the smallest.
// Note:- The position you return should be according to 1-based indexing. 

// Example 1:
// Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
// Output: 2
// Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.

// Example 2:
// Input: arr[] = [1, 2, 3, 4]
// Output: -1
// Explanation: All elements appear only once so answer is -1.

// Brute force algorithm: Very easy, its just inspired by 'FindTheDuplicateNumber.cpp'.
// Optimal algorithm: Just store the frequencies of all elements in a map. Then return 
//                    the index of element of map having frequency more than 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(n)
    int firstRepeated_bruteforce(vector<int> &arr) {
        unordered_map<int, int> map;
        vector<int> duplicates;
        
        // Collect all duplicate elements in 'duplicates' vector.
        for(int i = 0; i < arr.size(); i++) {
            if(map.find(arr[i]) == map.end()) map[arr[i]] = i;
            else duplicates.push_back(arr[i]);
        }
        
        // Iterate the whole array, and check if any of the elements from the array matches any element from 'duplicates' or not.
        // If any match found, first occurrence of that duplicate element is found, hence return its index(index starts from 1).
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < duplicates.size(); j++) {
                if(arr[i] == duplicates[j]) return i+1;   // considering 1 based indexing
            }
        }
        
        return -1;   // if no duplicates found
    }

// -----------------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int firstRepeated(vector<int> &arr) {
        unordered_map<int, int> map;

        // Store the frequency of each element in the map(key: {element}, value: {frequency})
        for(int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }

        // Return the first element that repeats, i.e., element whose frequency is more than 1.
        for(int i = 0; i < arr.size(); i++) {
            if(map[arr[i]] > 1) return i+1;   // considering 1 based indexing
        }

        return -1;   // if no duplicates found
    }

};

int main() {
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
    cout << Solution().firstRepeated_bruteforce(arr) << endl;
    cout << Solution().firstRepeated(arr) << endl;

    return 0;
}
