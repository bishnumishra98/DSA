#include <iostream>
using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>

// Comparator function
bool compare(int a, int b) {
    return a < b;   // Ascending order
}

int main() {
    vector<int> vec = {4, 2, 5, 1, 3};
    
    // Using the comparator function with sort
    sort(vec.begin(), vec.end(), compare);
    
    for(int num : vec) {
        cout << num << " ";
    }
    return 0;
}
