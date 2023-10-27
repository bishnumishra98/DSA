#include <iostream>
using namespace std;

int linearSearch(int *arr, int size, int index, int target) {
    //base case
    if (index >= size) {
        return -1;
    }

    //processing
    if(arr[index] == target) {
        return index;
    }

    // recursive relation
    linearSearch(arr, size, index+1, target);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int target = 40;
    int index = 0;

    if(linearSearch(arr, size, index, target) == -1) {
        cout << "Element not found";
    } else {
        cout << "Element found at index " << linearSearch(arr, size, index, target); 
    }

    return 0;
}