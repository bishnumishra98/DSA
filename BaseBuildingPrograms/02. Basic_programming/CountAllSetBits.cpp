#include<iostream>
using namespace std;

// Brute force
// T.C: O(32)
// S.C: O(1)
int countSetBits1(int n) {
    int count = 0;
    // Iterate through each bit position from 0 to 31 (32 bits in an integer)
    for(int i = 0; i < 32; i++) {
        // Check if the i-th bit from right-most side(LSB) of n is 1.
        if(n & (1 << i)) {
            count++;
        }
    }
    return count;
}

// Brian Kernighan's algorithm
// T.C: O(logn)
// S.C: O(1)
int countSetBits2(int n) {
    int count = 0;
    while(n) {
	    n = n & (n-1);   // This line clears the least significant set bit of n
	    count++;   // Increment the count for each cleared bit
	}
    return count;
}

// Note: O(logn) is better than O(32)

int main() {
    int n;
	cin >> n;
	cout << "Set bits: " << countSetBits2(n);

    return 0;
}
