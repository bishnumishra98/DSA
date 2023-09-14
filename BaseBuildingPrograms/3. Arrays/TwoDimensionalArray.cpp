// love babbar practice problem


#include<iostream>
using namespace std;

int main() {
    int arr[][3] = {   // mentioning at least column while initializing 2D array is important.
        {1, 2, 3},
        {4, 5, 6}
    };
    // 2D arrays are stored in memory like a 1D array only, elements are mapped using formula: c*(i+j), where c=no.of columns in array, i & j are row & column indexes respectively.

    int row = 2;
    int col = 3;

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