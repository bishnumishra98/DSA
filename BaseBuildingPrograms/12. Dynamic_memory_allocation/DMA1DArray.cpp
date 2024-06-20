#include <iostream>
using namespace std;

void populateData(int *p, int size) {
    for(int i=0; i<size; i++) {
        p[i] = i*2;
    }
}

void print(int *p, int size) {
    for(int i=0; i<size; i++) {
        cout << p[i] << " ";
    }
}

int main() {
    // i)   Allocating a 1D array using the keyword 'new':
            int *ptr = new int[10];   // allocating an int type array of size 10,
                                     // whose base address is pointed by 'ptr'

            populateData(ptr, 10);   // populating values {0, 2, 4, 6, ..., 18} inside the array

            print(ptr, 10);   // printing values inside the array
            cout << endl << endl;

            delete[] ptr;   // deallocating memory

    
    // ii)  Allocating a 1D array using the function 'malloc()':
            int *ptr2 = (int*) malloc(10 * sizeof(int));   // allocating 10*4, i.e. 40 bytes
            // of memory and casting it to an int pointer. The base address of this memory block
            // is pointed to by 'ptr2'.

            populateData(ptr2, 10);

            print(ptr2, 10);

            free(ptr2);   // deallocating memory


    return 0;
}