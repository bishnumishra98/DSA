#include <iostream>
using namespace std;

int main() {
    // There are two types of memory allocation in C++ :-

    // 1) Static memory allocation(SMA): Static Memory Allocation in C++ refers to the process
    // of allocating memory for variables at compile time. In other words, the size and type of
    // memory required by variables are determined at compile time, and the memory is allocated
    // before the program is executed. SMA variables are stored in stack.
    // Example:
    int count = 5;
    int students[10];
    int *ptr;

    // 2) Dynamic memory allocation(DMA): It typically refers to the allocation of memory at runtime,
    // rather than at compile time. In C++, we can use operators like 'new' or functions like
    // 'malloc()' to allocate memory dynamically. Note that variables created using the keyword 'new'
    // is freed using the keyword 'delete'. Whereas, variables created using the function 'malloc()'
    // is freed using the function 'free()'. DMA variables are stored in heap.

    // i)   Allocating a single element using the keyword 'new':
            int *x = new int(5);   // 'new' keyword returns a pointer
            // The above line means, allocating a variable in heap that contains '5' and is pointed
            // by the pointer 'x'.
            cout << "*x = " << *x << endl;   // o/p: 5

            delete x;   // deleting the dynamically allocated memory to avoid memory leaks
        
            
    // ii)  Allocating a single variable using the function 'malloc()':
            // malloc() stands for memory allocation.
            // The malloc() function reserves a single block of memory of the specified no.of bytes.
            // It returns a pointer of type void which can be casted into any type.
            // It allocates memory and leaves the memory uninitialized.
            // It returns the value 'NULL' if memory cannot be allocated.
            // Syntax: int *y = (castType*) malloc(size);

            int *y = (int*) malloc(4);
            // The above line allocates 4 bytes of memory. Then, we typecasted this memory block
            // to integer, i.e. we created an int type pointer 'y' that points to an int
            // type memory block.

            *y = 1998;   // assigning value '1998' to the variable pointed by 'y'.

            cout << "*y = " << *y << endl;   // o/p: 1998

            free(y);   // freeing the dynamically allocated memory

    
    // -> Similar to 'malloc()', there is also a function called 'calloc()':
            // calloc() stands for contiguous allocation.
            // The calloc() functions reserves multiple blocks of memory of the specified no.of bytes.
            // It allocates memory and initializes all elements to zero.
            // // It also returns the value 'NULL' if memory cannot be allocated.
            // Syntax: int *z = (castType*) calloc(n, size);

            int *z = (int*) calloc(10, 4);
            // The above line allocates 10 contiguous memory blocks each of size 4 bytes.
            // Then, we typecasted these memory blocks to integer, i.e. we created an integer
            // pointer 'z' that points to base address of the integer type array of size 10.

            *z = 1999;   // assigning value '1999' to the variable pointed by 'z'.

            cout << "*z = " << *z;   // o/p: 1999

            free(z);   // freeing the dynamically allocated memory


        // PRO TIP: Instead of assigning numerical size to malloc() or calloc() function, use
        // sizeof() function to auto calculate data type's size. Example:
        // int *y = (int*) malloc(sizeof(int));
        // int *z = (int*) malloc(10, sizeof(int));


    return 0;
}
