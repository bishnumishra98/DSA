// Leetcode: 2149. Rearrange Array Elements by Sign

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
    for (const auto& element : v) {
        cout << element << " ";
    }
}

// Brute force
// T.C: O(n)
// S.C: O(n)
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector <int> positive;
    vector <int> negative;

    for(int i=0; i<n; i++) {
        if(nums[i] > 0) {
            positive.push_back(nums[i]);
        } else {
            negative.push_back(nums[i]);
        }
    }

    vector <int> arr;

    for(int i=0; i<n/2; i++) {
        arr.push_back(positive[i]);
        arr.push_back(negative[i]);
    }

    return arr;
}

int main() {
    vector <int> v = {3, 1, -2, -5, 2, -4};

    v = rearrangeArray(v);

    printVector(v);

    return 0;
}