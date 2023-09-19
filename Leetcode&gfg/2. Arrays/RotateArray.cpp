// leetcode: 189. Rotate Array

#include <iostream>
#include <vector>
using namespace std;

// T.C: O(n)
// S.C: O(n)
void rotate(vector<int>& nums, int k) {
    int n= nums.size();
    vector<int>t(n);

    for(int i=0; i<n; i++){
        t[(i+k)%n]= nums[i];
    }

    nums = t;
}

int main() {
    vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    rotate(v, k);

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}