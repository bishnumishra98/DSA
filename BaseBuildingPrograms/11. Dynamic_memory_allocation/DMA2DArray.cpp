#include <iostream>
using namespace std;

void populateData(int **p, int rows, int cols) {
    int even = 2;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            p[i][j] = even;
            even += 2;
        }
    }
}

void print(int **p, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Allocating a 2D array is a simple 2 step process:
    // Step 1: Initialize an array of pointers. Size of this array should be no.of rows in 2D array.
    //         Base address of this array will be pointed by a variable of type 'pointer of pointers'.
    // Step 2: Initialize a 1D array for each of the rows present in the above array.
    //      Illustration:
            int rows = 4, cols = 5;

    // i)   Allocating a 2D array using the keyword 'new':
            int **ptr = new int*[rows];   // creating an array of type 'int*' and size 'rows'.
            // Then, the pointer 'ptr' stores the base address of this array.

            // Initializing a 1D array for each row
            for(int i=0; i<rows; i++) {
                ptr[i] = new int[cols];  // it signifies each row will contain 'cols' no.of elements
            }

            // inserting elements in 2D array:
            populateData(ptr, rows, cols);

            // printing values inside the array
            cout << "Elements of ptr:" << endl;
            print(ptr, rows, cols);
            cout << endl << endl;

            // Deallocating memory is also a 2 step process:
            // Step 1: Deallocate the array present in each row
            for(int i=0; i<rows; i++) {
                delete[] ptr[i];
            }
            // Step 2: Deallocate the array
            delete[] ptr;

    

    // ii)  Allocating a 2D array using the function 'malloc()':
            int **ptr2 = (int**) malloc(rows * sizeof(int));  // creating an array of type 'int*'
            // and size 'rows'. Then, the pointer 'ptr2' stores the base address of this array.

            // Initializing a 1D array for each row
            for(int i=0; i<rows; i++) {
                ptr2[i] = (int*) malloc(cols * sizeof(int));   // it signifies each row gets
                                                              // 'cols*4' bytes of memory.
            }

            // inserting elements in 2D array:
            populateData(ptr2, rows, cols);

            // printing values inside the array
            cout << "Elements of ptr2:" << endl;
            print(ptr2, rows, cols);
            cout << endl << endl;

            // Deallocating memory is also a 2 step process:
            // Step 1: Deallocate the array present in each row
            for(int i=0; i<rows; i++) {
                free(ptr2[i]);
            }
            // Step 2: Deallocate the array
            free(ptr2);


    return 0;
}