// love babbar practice problem

#include<iostream>
using namespace std;

int main() {
    int arr[][4] = {   
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int row = 3;
    int col = 4;

    for(int i=0; i<row; i++) {
        int sum = 0;
        for(int j=0; j<col; j++) {
            sum += arr[i][j];
        }
        cout << sum;
        cout << endl;
    }

    return 0;
}

