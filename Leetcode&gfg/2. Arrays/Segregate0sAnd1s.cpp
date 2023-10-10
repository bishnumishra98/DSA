// gfg: Segregate 0s and 1s

#include <iostream>
using namespace std;

// Brute force
// T.C: O(n)
// S.C: O(1)
void segregate0and1_bruteForce(int arr[], int n) {
    int zeroCount = 0, oneCount = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            zeroCount++;
        } else {
            oneCount++;
        }
    }
    // inserting 0s and 1s on indexes
    int index = 0;
    while(zeroCount--) {
        arr[index] =  0;
        index++;
    }
    while(oneCount--) {
        arr[index] =  1;
        index++;
    }
}

// Two pointer approach
// T.C: O(n)
// S.C: O(1)
void segregate0and1(int arr[], int n) {
    int low = 0, high = n-1;

    while(low<high) {
        if(arr[low] == 0) {
            low++;
        }
        else if(arr[high] == 1) {
            high--;
        } else {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    // dynamic memory allocation to create the array
    int* arr = new int[n];

    // taking user inputs
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //segregate0and1_bruteForce(arr, n);
    
    segregate0and1(arr, n);

    // printing sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // releasing the dynamically allocated memory
    delete[] arr;

    return 0;
}