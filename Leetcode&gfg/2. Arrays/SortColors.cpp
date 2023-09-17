// leetcode: 75. Sort Colors. Also known as Dutch National Flag problem

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
    // Using a range-based for loop with auto
    for (const auto& element : v) {
        cout << element << " ";
    }
}

// Brute force
// T.C: O(n+n) = O(2n)
// S.C: O(1)
void sortColors_bruteForce(vector<int>& nums) {
    int n = nums.size();
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    // T.C: O(n)
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) {
            zeroCount++;
        } else if(nums[i] == 1) {
            oneCount++;
        } else {
            twoCount++;
        }
    }

    int index = 0;
    // T.C: O(n)
    while(zeroCount--) {
        nums[index] = 0;
        index++;
    }
    while(oneCount--) {
        nums[index] = 1;
        index++;
    }
    while(twoCount--) {
        nums[index] = 2;
        index++;
    }
}

// We will apply 3 pointer approach here. This is also called Dutch National Flag Algorithm.
// Watch Striver's video to get in-depth explanation: https://www.youtube.com/watch?v=tp8JIuCXBaU
// T.C: O(n)
// S.C: O(1)
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n -1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        } else if(nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        } else {
            mid++;
        }
    }
}

int main() {
    vector <int> v = {2, 0, 2, 1, 1, 0};
    //sortColors_bruteForce(v);
    sortColors(v);
    printVector(v);
    return 0;
}