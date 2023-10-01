// Insertion Sort: 

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v) {
    for(auto i: v) {
        cout << i << " ";
    }
}

// T.C: O(n2)
// S.C: O(1)
void insertionSort(vector<int>& v) {
    
}


int main() {
    vector <int> v = {45, 35, 55, 25, 15};

    insertionSort(v);

    print(v);

    return 0;
}