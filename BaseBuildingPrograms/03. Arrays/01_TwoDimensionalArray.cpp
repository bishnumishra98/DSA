// love babbar practice problem


#include<iostream>
using namespace std;

int main() {
    int col = 3;

    int arr[][col] = {   // mentioning at least column while initializing 2D array is important.
        {1, 2, 3},
        {4, 5, 6}
    };
    // 2D arrays are stored in memory like a 1D array only, elements are mapped using formula: c*i + j,
    // where c=no.of columns in array, i & j are row & column indexes respectively. For example,
    // the element '5' of 2D array will be stored at 3*1+1, i.e., 4th index in 1D array.

    // int row = sizeof(arr) / sizeof(int) / col;   // This is the 1st way to find no.of rows in a 2D array.
    int row = sizeof(arr) / sizeof(arr[0]);   // This is the 2nd way to find no.of rows in a 2D array. 
    // sizeof(arr[0]) gives you the size of the first row of the array in bytes.

    // print original matrix
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    // Transpose of matrix
    int brr[col][row];
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            brr[j][i] = arr[i][j];
        }
    }

    // Printing brr(Transpose of A)
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
