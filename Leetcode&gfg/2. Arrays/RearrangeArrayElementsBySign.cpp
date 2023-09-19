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
vector<int> rearrangeArray_bruteForce(vector<int>& nums) {
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

// Two pointer approach
// T.C: O(n)
// S.C: O(n)
vector<int> rearrangeArray_twoPointer(vector<int>& nums) {
    vector <int> ans(nums.size(), -1);

    int even = 0, odd = 1;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > 0) {
            ans[even] = nums[i];
            even += 2;
        } else {   // if(nums[i] < 0)
            ans[odd] = nums[i];
            odd += 2;
        }
    }

    return ans;
}


int main() {
    vector <int> v = {3, 1, -2, -5, 2, -4};

    // v = rearrangeArray_bruteForce(v);

    v = rearrangeArray_twoPointer(v);   // This approach is better in terms of space efficiency
                                       // and is equally efficient in terms of time complexity,
                                      // from the above function 'rearrangeArray_bruteForce()'.

    printVector(v);

    return 0;
}