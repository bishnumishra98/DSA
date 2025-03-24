// GFG: Fractional Knapsack   --->   Given two arrays, val[] and wt[], representing the values and weights of items, and
// an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be
// achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Example 1:
// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120
//              and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value  becomes 
//              60+100+80.0=240.0. Thus, total maximum value of item we can have is 240.00 from the given capacity of sack.

// Example 2:
// Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
// Output: 160.000000
// Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from
//              the given capacity of sack.

// Example 3:
// Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
// Output: 60.000000
// Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30).
//              Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.

// Problem link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Algorithm: Extremely simple.
// 1. Calculate density of each item (value/weight) and store it in a vector of pairs.
// 2. Sort the items by density in descending order.
// 3. Traverse the items and take the whole item if capacity is greater than or equal to weight of the item.
//    Else take the fraction of the item and break the loop.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn) + O(n) = O(nlogn)
    // S.C: O(n)
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<double> density(n);
        
        vector<pair<double, int>> items(n);   // {density, weight}
        for(int i = 0; i < n; i++) {
            items[i] = {(double)val[i] / (double)wt[i], wt[i]};
        }
        
        // Sort items by density in descending order
        sort(items.begin(), items.end(), greater<pair<double, int>>());
        
        double value = 0;
        
        for(auto it: items) {
            double density = it.first;
            int weight = it.second;
            
            // If capacity is greater than or equal to weight, take the whole item
            // Else take the fraction of the item
            if(capacity >= weight) {
                value += density * weight;
                capacity -= weight;
            } else {
                value += density * capacity;
                break;
            }
        }
        
        return value;
    }
};

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution obj;
    cout << obj.fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}
