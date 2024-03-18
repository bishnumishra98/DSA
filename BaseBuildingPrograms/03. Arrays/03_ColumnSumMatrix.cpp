// love babbar practice problem

#include<iostream>
using namespace std;

int main() {
    int col = 4;

    int arr[][col] = {   
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int row = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<col; i++) {
        int sum = 0;
        for(int j=0; j<row; j++) {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
    return 0;
}
