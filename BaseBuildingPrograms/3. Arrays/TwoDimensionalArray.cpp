// love babbar practice problem


#include<iostream>
using namespace std;

int main() {
    int arr[][4] = {   // mentioning at least column while initializing 2D array is important.
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 2D arrays are stored in memory like a 1D array only, elements are mapped using formula: c*(i+j), where c=no.of columns in array, i & j are row & column indexes respectively.

    int row = 3;
    int col = 4;

    // print row wise
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    // Transpose of matrix
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}