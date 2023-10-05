// Pointer variable can only store address of a variable.
// Size of a pointer variable is 4 byte for 32-bit system, and 8 byte for 64-bit system.

// arr, &arr, &arr[0] all point to base address of an array named 'arr'

// arr[i] and i[arr] mean the same in C/C++, as they both are internally converted
// like this: *(arr + i) and *(i + arr) respectively, where arr = base address of array