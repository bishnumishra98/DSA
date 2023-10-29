#include <iostream>
#include <vector>
using namespace std;

// T.C: O(size)
// S.C: O(size)
void insertEvenNumbersInVector(int *arr, int size, int index, vector<int> &v) {
    // base case
    if(index >= size) {
        return;
    }

    // processing
    if((arr[index]&1) == 0) {
        v.push_back(arr[index]);
    }

    //recursive relation
    insertEvenNumbersInVector(arr, size, index+1, v);
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int size = 10;
    int index = 0;

    vector <int> v;

    insertEvenNumbersInVector(arr, size, index, v);

    for(auto element: v) {
        cout << element << " ";
    }

    return 0;
}