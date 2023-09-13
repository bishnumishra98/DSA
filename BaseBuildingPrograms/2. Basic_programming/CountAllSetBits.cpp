// love babbar practice problem

#include<iostream>
using namespace std;

// Brute force
// T.C: O(32)
// S.C: O(1)
int countSetBits1(int n) {
    int count = 0;
    for( int i=0; i<32; i++) {
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
	    n = n & (n-1);
	    count++;
	}
    return count;
}

// O(logn) is better than O(32)

int main() {
    int n;
	cin >> n;
	cout << "Set bits: " << countSetBits2(n);

    return 0;
}