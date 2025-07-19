// GFG: Add two numbers represented by two arrays   --->   Given two arrays arr1 and arr2, representing two numbers
// such that every element of arrays represents a digit. The task is to find the sum of both the numbers.

// Example 1:
// Input : arr1[] = [1, 2], arr2[] = [2, 1]
// Output : 33
// Explanation: arr1[]=[1,2] number represented by first array is 12. arr2[] = [2, 1] number represented by second array is 21.
// Sum = 12 + 21 = 33.

// Example 2:
// Input : arr1[] = [9, 5, 4, 9], arr2[] = [2, 1, 4] 
// Output : 9763 
// Explanation : sum of 9549 and 214 is 9763.

// Problem link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1

// Algortihm: Algorithm is very practical.
// 1. Initialize a 'carry' variable with 0, and mark 2 pointers i and j, on the last element of arr1 and arr2 respectively,
//    as addition always starts from unit's digit. Also create a blank string variable 'ans' to build and store the answer.
// 2. Add arr1[i], arr2[j] and carry, and store its result (sum % 10) in the 'ans' and update the carry with sum / 10.
// 3. Keep doing the same, until i and j reaches first elements of arr1 or arr2, respectively.
// 4. If some elements are left in arr1 or arr2, process them individually in the similar way.
// 5. If something is left in carry, process that too. Note that carry can be only 1 or 0.
// 6. Finally, the number gets stored in the 'ans' in reverse order, so reverse the string and return.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // T.C: O(max(n, m));   where n = arr1.size() and m = arr2.size() respectively
    // S.C: O(max(n, m))
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;
        string ans;

        // Add both arrays till same length
        while(i >= 0 && j >= 0) {
            int sum = arr1[i] + arr2[j] + carry;
            ans.push_back((sum % 10) + '0');   // added + '0' to represent integer in string equivalent
            carry = sum / 10;
            i--;
            j--;
        }

        // Add arr1 elements in 'ans' if its elements were still left to be processed
        while(i >= 0) {
            int sum = arr1[i] + carry;
            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
            i--;
        }

        // Add arr2 elements in 'ans' if its elements were still left to be processed
        while(j >= 0) {
            int sum = arr2[j] + carry;
            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
            j--;
        }

        // Add carry, if its left
        if(carry) ans.push_back(1 + '0');   // carry can be either 0 or 1 only. So if a carry is present, it is for sure 1.

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {2, 1};
    cout << Solution().calc_Sum(arr1, arr2);

    return 0;
}
