// love babbar practice problem

// Non-square matrices typically require additional space to transpose, but
// square matrices can be transposed in-place, i,e., in constant space complexity.

#include<iostream>
using namespace std;

// Function to print a Square array
void printSquareArray(int arr[][3], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// T.C: O(n)
// S.C: O(1)
void transposeSquareArray(int arr[][3], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=i; j<col; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main() {
    int col = 3;

    int arr[][3] = {   
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int row = sizeof(arr) / sizeof(arr[0]);

    transposeSquareArray(arr, row, col);
    printSquareArray(arr, row, col);

    return 0;
}
