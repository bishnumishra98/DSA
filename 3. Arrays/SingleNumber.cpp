// Leetcode: 136. Single Number

#include<iostream>
#include<vector>
using namespace std;

// T.C: O(n)
// S.C: O(1)
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++) {
        ans = ans ^ nums[i];
    }
    return ans;
}

int main() {
    vector <int> v;
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        int elements;
        cin >> elements;
        v.push_back(elements);
    }
    cout << "Single number is: " << singleNumber(v);
    return 0;
}