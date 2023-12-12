#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix;

    int row;

    cout << "Enter the number of rows in matrix: ";
    cin >> row;
    cout << endl;

    // Inserting values into the 2D vector
    for (int i = 0; i < row; i++) {

        cout << "Enter the number of elements in " << i << "th row: ";
        int col;
        cin >> col;
        vector<int> v;

        cout << "Enter the elements one by one:\n";
        for (int j = 0; j<col; j++) {
            int element;
            cin >> element;
            v.push_back(element);
        }

        matrix.push_back(v);
        cout << endl;
    }

    // Printing the vector
    for (int i = 0; i<matrix.size(); i++) {
        for (int j = 0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
