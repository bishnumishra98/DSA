// leetcode: 189. Rotate Array

#include <iostream>
#include <vector>
#include <algorithm>   // for reverse()
using namespace std;

void printVector(vector<int>& v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
}

// Modulus method
// T.C: O(n)
// S.C: O(n)
void rotate_modulusMethod(vector<int>& nums, int k) {
    int n= nums.size();
    vector<int>t(n);

    for(int i=0; i<n; i++){
        t[(i+k)%n]= nums[i];
    }

    nums = t;
}

// Reversal method: (0, n-1) -> (0, k-1) -> (k, n-1)
// T.C: O(n)
// S.C: O(1)
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();   // to handle the case when 'k > no.of elements in vector'

    // reverse from (0, n-1)
    reverse(nums.begin(), nums.end());

    // reverse from (0, k-1)
    reverse(nums.begin(), nums.begin() + k);

    // reverse from (k, n-1)
    reverse(nums.begin() + k, nums.end());
}


int main() {
    vector <int> v = {1, 2};
    int k = 3;

    // rotate_modulusMethod(v, k);

    rotate(v, k);

    printVector(v);

    return 0;
}