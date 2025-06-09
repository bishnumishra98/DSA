// GFG: Partitions with Given Difference   --->   Given an array arr[], partition it into two subsets(possibly empty)
// such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1
// and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and
// the difference between sum1 and sum2 is equal to d. 

// Example 1:
// Input: arr[] =  [5, 2, 6, 4], d = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference
// between subset sum is: (6 + 4) - (5 + 2) = 3.

// Example 2:
// Input: arr[] = [1, 1, 1, 1], d = 0 
// Output: 6 
// Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and
// remaning two 1's in sum2. Thus there are total 6 ways for partition the array arr. 

// Example 3:
// Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
// Output: 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    int countPartitions(vector<int>& arr, int d) {
        
    }
};

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    
    cout << Solution().countPartitions(arr, d);

    return 0;
}
