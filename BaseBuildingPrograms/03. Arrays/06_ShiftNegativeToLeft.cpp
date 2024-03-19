// love babbar practice problem

#include <iostream>
using namespace std;

void shiftNegativeToLeft(int arr[], int n) {
    // we are following two approach here
    int j = 0;   // This variable will be used to keep track of the position
                // where the next negative number should be placed.
    for(int index=0; index<n; index++) {
        // index variable will be used to traverse the whole array
        if(arr[index] < 0) {
            swap(arr[index], arr[j]);
            j++;
        }
    }
}

int main() {
    int arr[] = {-2, 3, 5, -10, 9, -7, 11, -6};
    int n = 8;

    shiftNegativeToLeft(arr, n);

    // printing array
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}