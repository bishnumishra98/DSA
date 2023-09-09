#include <iostream>
using namespace std;

// Find the unique element
int findUniqueElement(int arr[], int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Shift elements of an array by K
void shiftElementsByK(int arr[], int n, int K) {
    int temp_arr[K];
    int i = 0, j = n-1;
    int k = K;
    // storing K right elements from arr[] in temp_arr[]
    while(K--) {
        temp_arr[i] = arr[j];
        i++;
        j--;
    }
    // shifting arr[] by k
    for(int i=n-1; i>=k; i--) {
        arr[i] = arr[i-k];
    }
    // inserting tem_arr[] elements in starting indexes of arr[]
    for(int i=0; i<k; i++) {
        arr[i] = temp_arr[i];
    }
    // printing arr[]
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

// Left shift elements of an array by K
void leftShiftElementsByK(int arr[], int n, int K) {
    int temp_arr[K];
    int k = K;
    int i = 0, j = 0;
    // storing K left elements from arr[] in temp_arr[]
    while(K--) {
        temp_arr[i] = arr[j];
        i++;
        j++;
    }
    // shifting arr[] by k
    for(int i=0; i<n-k; i++) {
        arr[i] = arr[i+k];
    }
    // inserting tem_arr[] elements in last indexes of arr[]
    j = 0;
    for(int i=n-k; i<n; i++) {
        arr[i] = temp_arr[j];
        j++;
    }
    // printing arr[]
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}


int main() {
    // // Find the unique element
    // int arr[] = {2, 10, 11, 11, 13, 10, 2, 15, 13, 15};
    // int size = 10;
    // cout << "Unique element: " << findUniqueElement(arr, size);


    // // Print all pairs
    // int arr[] = {10, 20, 30};
    // int size = 3;
    // for(int i=0; i<size; i++) {
    //     for(int j=0; j<size; j++) {
    //         cout << arr[i] << " " << arr[j] << endl;
    //     }
    // }


    // // Print all triplets
    // int arr[] = {10, 20, 30};
    // int size = 3;
    // for(int i=0; i<size; i++) {
    //     for(int j=0; j<size; j++) {
    //         for(int k=0; k<size; k++) {
    //             cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
    //         }
    //     }
    // }


    // // Sort 0s and 1s in an array
    // int arr[] = {0, 0, 1, 0, 1, 0, 0, 1};
    // int size = 8;
    // // counting 0s and 1s
    // int zeroCount = 0, oneCount = 0;
    // for(int i=0; i<size; i++) {
    //     if(arr[i] == 0) {
    //         zeroCount++;
    //     } else {
    //         oneCount++;
    //     }
    // }
    // // inserting 0s and 1s on indexes
    // int index = 0;
    // while(zeroCount--) {
    //     arr[index] =  0;
    //     index++;
    // }
    // while(oneCount--) {
    //     arr[index] =  1;
    //     index++;
    // }
    // // printing array
    // for(int i=0; i<size; i++) {
    //     cout << arr[i] << " ";
    // }


    // // Shift elements of an array by 1
    // int arr[] = {10, 20, 30, 40, 50, 60};
    // int size = 6;
    // int temp = arr[size-1];
    // for(int i=size-1; i>=1; i--) {
    //     arr[i] = arr[i-1];
    // }
    // arr[0] = temp;
    // // printing array
    // for(int i=0; i<size; i++) {
    //     cout << arr[i] << " ";
    // }


    // // Shift elements of an array by k
    // int arr[] = {10, 20, 30, 40, 50, 60};
    // int size = 6, K;
    // cin >> K;
    // shiftElementsByK(arr, size, K);


    // // Left shift elements of an array by 1
    // int arr[] = {10, 20, 30, 40, 50, 60};
    // int size = 6;
    // int temp = arr[0];
    // // shifting array by 1
    // for(int i=0; i<size-1; i++) {
    //     arr[i] = arr[i+1];
    // }
    // arr[size-1] = temp;
    // // printing array
    // for(int i=0; i<size; i++) {
    //     cout << arr[i] << " ";
    // }


    // Left shift elements of an array by K
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6, K;
    cin >> K;
    leftShiftElementsByK(arr, size, K);



    return 0;
}