// for n = 4, print this pattern:
// 10
// 9 4
// 8 5 3
// 7 6 2 1

#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int count = 0;
    
    // for knowing value of count
    for(int i=0; i<n; i++) {
        for(int j=0; j<(i+1); j++) {
            count++;
        }
    }

    // making the half pyramid
    int even_count = count;
    int odd_count = count - n - n/2;
    for(int row=0; row<n; row++) {
        // printing count
        for(int col=0; col<(row+1); col++) {
            if(col%2 == 0) {
                cout << even_count << " ";
                even_count--;
            } else {   // if(col%2 != 0)
                cout << odd_count << " ";
                odd_count++;
            }
        }

        cout << endl;
    }

    return 0;
}