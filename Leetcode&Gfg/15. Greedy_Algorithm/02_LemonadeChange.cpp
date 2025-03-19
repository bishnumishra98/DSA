// GFG: Lemonade Change   --->   You are an owner of lemonade island, each lemonade costs $5. Customers are standing in a
// queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only
// buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so
// that the net transaction is that the customer pays $5.
// NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from
//  the previous customers.
// Given an integer array bills of size N where bills [ i ] is the bill the ith customer pays, return true if you can
// provide every customer with the correct change, or false otherwise.

// Example 1:
// Input:
// N = 5
// bills [ ] = {5, 5, 5, 10, 20}
// Output: True
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change we return true.
 
// Example 2:
// Input:
// N = 5
// bills [ ] = {5, 5, 10, 10, 20}
// Output: False
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function lemonadeChange() which takes the
// interger N and integer array bills [ ] as parameters and returns true if it is possible to provide change to every customer otherwise false.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Problem link: https://www.geeksforgeeks.org/problems/lemonade-change/0

// Algorithm: Very simple and easy greedy approach.
// 1. Initialize two variables five and ten to 0, because we can return only either fives or ten.
// 2. Traverse the bills array.
//    Case 1:  If the bill is 5:
//             We can give a lemon and take one $5 note, so increment five.
//    Case 2:  If the bill is 10:
//             If we have a $5 note, then we can give a lemon, take the $10 note and give a $5 note, so decrement five and increment ten.
//             Otherwise, return false.
//    Case 3:  If the bill is 20:
//             If we have a $5 note and a $10 note, then we can give a lemon, take the $20 note and give a $5 note and a $10 note,
//             so decrement five and ten.
//             Otherwise, if we have three $5 notes, then we can give a lemon, take the $20 note and give three $5 notes, so decrement
//             five by 3.
//             Otherwise, return false.
// 3. If the whole array is traversed, it means we could sell lemons to all customers, so return true.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(N)
    // S.C: O(1)
    bool lemonadeChange(int N, vector<int> &bills) {
        int five = 0, ten = 0;   // because we can return only either fives or ten

        for(int i = 0; i < N; i++) {
            if(bills[i] == 5) {
                five++;
            } else if(bills[i] == 10) {
                if(five) {
                    five--;
                    ten++;
                } else return false;
            } else {   // bills[i] == 20
                if(five && ten) {
                    five--;
                    ten--;
                } else if(five >= 3) {
                    five -= 3;
                } else return false;
            }
        }

        return true;
    }
};

int main() {
    int N = 5;
    vector<int> bills = {5, 5, 5, 10, 20};

    Solution obj;
    cout << obj.lemonadeChange(N, bills);

    return 0;
}
