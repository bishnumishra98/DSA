// Exponential search also known as galloping search, doubling search is popular search algorithm
// to search an element in unbounded or infinite sorted array. It is particularly useful in scenarios
// involving large sorted datasets or streams where you can't determine the total size beforehand.

#include <iostream>
#include <vector>
using namespace std;

int exponentialSearch(vector<int>& arr, int target) {

}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int target = 60;

    cout << target << " is present at index: " << exponentialSearch(arr, target);

    return 0;
}
