// Rules for all pattern printing programs:
// 1. Identify the number of rows or the value of 'n', it is the number of iterations in the outer loop.
// 2. Identify what is happening in each row, then try to find a relation between between row and elements of that row.
//    Once you have a generalized formula for row and its corresponding elements, run the inner loop that many times
//    for each row.

// ● Illustration 1:
//   Suppose we are asked to print a half pyramid:
//   For input n = 4
//   *
//   **
//   ***
//   ****
//   In the above pattern, observe each row:
//   r0 has 1 star
//   r1 has 2 stars
//   r2 has 3 stars
//   r3 has 4 stars
//   Now try to make a generalized formula, and we find that the formula will be: row = row + 1 stars.
//   Thus is the formula for the inner loop: for(int col = 0; col < row + 1; col++) cout << "*";

// ● Illustration 2:
//   Suppose we are asked to print a inverted half pyramid:
//   For input n = 4
//   ****
//   ***
//   **
//   *
//   In the above pattern, observe each row:
//   r0 has 4 star
//   r1 has 3 stars
//   r2 has 2 stars
//   r3 has 1 stars
//   Now try to make a generalized formula, and we find that the formula will be: row = n - row stars.
//   Thus is the formula for the inner loop: for(int col = 0; col < n - row; col++) cout << "*";


#include <iostream>
using namespace std;

int main() {
    // // Butterfly pattern
    // int n, row, col, num;
    // cin >> num;
    // n = num/2;

    // // upper part of butterfly
    // for(row=0; row<n; row++) {
    //     // left half
    //     for(col=0; col<(row+1); col++) {
    //         cout << "* ";
    //     }
    //     // mid part
    //     for(col=0; col<(2*n-2*row-2); col++) {
    //         cout << "  ";
    //     }
    //     // right half
    //     for(col=0; col<(row+1); col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // // lower part of butterfly
    // for(row=0; row<n; row++) {
    //     // left part
    //     for(col=0; col<(n-row); col++) {
    //         cout << "* ";
    //     }
    //     // mid part
    //     for(col=0; col<(2*row); col++) {
    //         cout << "  ";
    //     }
    //     // right part
    //     for(col=0; col<(n-row); col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    // // Solid half diamond
    // int n, row, col, num;
    // cin >> num;
    // n = num/2 + 1;
    
    // //upper half pyramid
    // for(row=0; row<n; row++) {
    //     for(col=0; col<(row+1); col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // //lower half inverted pyramid
    // n = num/2;
    // for(int row=0; row<n; row++) {
    //     for(col=0; col<(n-row); col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    // // Fancy pattern
    // int n, row, col;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     //printing spaces
    //     for(col=0; col<(2*n-row-2); col++) {
    //         cout << "*";
    //     }

    //     //printing pattern
    //     for(col=0; col<(2*row+1); col++) {
    //         if(col%2==0) {
    //             cout << row+1;
    //         } else {
    //             cout << "*";
    //         }
            
    //     }

    //     //printing spaces
    //     for(col=0; col<(2*n-row-2); col++) {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }


    // // Floyd's traingle
    // int row, col, n, count=1;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<(row+1); col++) {
    //         cout << count << " ";
    //         count++;
    //     }
    //     cout << endl;
    // }


    // // Numeric palindrome equilateral pyramid
    // int n, row, col, largest_digit;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     // printing spaces
    //     for(col=0; col<(n-row); col++) {
    //         cout << "  ";
    //     }

    //     // printing numbers for half pyramid
    //     for(col=0; col<row+1; col++) {
    //         largest_digit = col + 1;
    //         cout << largest_digit << " ";
    //     }

    //     // printing desecending numbers
    //     for(int num=largest_digit; num>1;) {
    //         num--;
    //         cout << num << " ";
    //     }
        
    //     cout << endl;
    // }


    // // Numeric hollow inverted half pyramid (right side)
    // int n, row, col, count=1;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<(n-row); col++) {
    //         if(row==0) {
    //             cout << count << " ";
    //             count++;
    //         } else if(col==0) {
    //             cout << row+1 << " ";
    //         } else if(col==(n-row-1)) {
    //             cout << n << " ";
    //         } else {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }


    // // Half pyramid(right side) with alphabets in column sequence and decrement sequence
    // int n, row, col;
    // char largest_char;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     // first part (half pyramid of column alphabets)
    //     for(col=0; col<row+1; col++) {
    //         cout << char('A'+col) << " ";
    //         largest_char = char('A'+col);
    //     }

    //     // second part (decrementing alphabet sequence)
    //     for(char alphabet = largest_char; alphabet>'A'; ) {
    //         alphabet--;
    //         cout << alphabet << " ";
    //     }

    //     cout << endl;
    // }


    // // Half pyramid(right side) with alphabets in column sequence
    // int n, row, col;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<row+1; col++) {
    //         cout << char('A'+col) << " ";
    //     }
    //     cout << endl;
    // }


    // // Half pyramid(right side) with alphabets in continuous sequence
    // int n, row, col;
    // char count = 'A';
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<row+1; col++) {
    //         cout << count << " ";
    //         count++;
    //     }
    //     cout << endl;
    // }


    // // Hollow pyramid(right side) with numbers
    // int n, row, col;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<row+1; col++) {
    //         if(row==0 || row==(n-1)) {
    //             cout << col+1;
    //         } else {
    //             if(col==0 || col==(row+1-1)) {
    //                 cout << col+1;
    //             } else {
    //                 cout << " ";
    //             }
    //         } 
    //     }
    //     cout << endl;
    // }


    // // Hollow inverted pyramid(right side)
    // int n, row, col;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<n-row; col++) {
    //         if(row==0 || row==(n-1)) {
    //             cout << "*";
    //         } else {
    //             if(col==0 || col==(n-row-1)) {
    //                 cout << "*";
    //             } else {
    //                 cout << " ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }


    // // Half pyramid(right side) + inverted half pyramid(right side) with star and number mixed
    // int n, row, col, num;
    // cin >> num;
    // n = num/2 + 1;
    // for(row=0; row<n; row++) {
    //     // Half pyramid(right side), logic will change a bit
    //     for(col=0; col<(2*row+1); col++) {
    //         if(col%2 == 0) {
    //             cout << row+1;
    //         } else {
    //             cout << " * ";
    //         }
    //     }
    //     cout << endl;
    // }

    // // Inverted half pyramid(right side). It will come below.
    // n = num/2;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<(2*n-2*row-1); col++) {
    //         if(col%2 == 0) {
    //             cout << n-row;
    //         } else {
    //             cout << " * ";
    //         }
    //     }
    //     cout << endl;
    // }
        

    // // Half pyramid(right side) with star and number mixed
    // int n, row, col;
    // cin >> n;
    // for(row=0; row<n; row++) {
    //     for(col=0; col<(2*row+1); col++) {
    //         if(col%2 == 0) {
    //             cout << row+1;
    //         } else {
    //             cout << " * ";
    //         }
    //     }
    //     cout << endl;
    // }


    // // Flipped solid diamond. It contains two mega parts, the first part and second part.
    // int n, row, col, num;
    // cin >> num;
    // n = num/2;
    // // first part -->
    // for(row=0; row<n; row++) {
    //     // Inverted half pyramid of stars (right side)
    //     for(col=0; col<n-row; col++) {
    //         cout << "* ";
    //     }
    //     // Full pyramid of spaces
    //     for(col=0; col<row*2; col++) {
    //         cout << "  ";
    //     }
    //     // Inverted half pyramid of stars (left side)
    //     for(col=0; col<n-row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // // second part -->
    // for(row=0; row<n; row++) {
    //     // Half pyramid of stars (right side)
    //     for(col=0; col<row+1; col++) {
    //         cout << "* ";
    //     }
    //     // Inverted full pyramid of spaces
    //     for(col=0; col<(2*n-2*row-2); col++) {
    //         cout << "  ";
    //     }
    //     // Half pyramid of stars (left side)
    //     for(col=0; col<row+1; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    
    // // Hollow full pyramid
    // int n, col, row, num;
    // cin >> num;
    // n = num/2;

    // // Hollow baseless pyramid
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<n-row-1; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<row+1; col++) {
    //         if(col==0 || col==(row+1-1)) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         }
            
    //     }
    //     cout << endl;
    // }

    // // Hollow inverted baseless pyramid
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<row; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<n-row; col++) {
    //         if(col==0 || col==(n-row-1)) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         } 
    //     }
    //     cout << endl;
    // }


    // // X shape
    // int n, col, row, num;
    // cin >> num;
    // n = num/2;

    // // Hollow inverted baseless pyramid
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<row; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<n-row; col++) {
    //         if(col==0 || col==(n-row-1)) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         } 
    //     }
    //     cout << endl;
    // }

    // // Hollow baseless pyramid
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<n-row-1; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<row+1; col++) {
    //         if(col==0 || col==(row+1-1)) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         }
            
    //     }
    //     cout << endl;
    // }

    
    // // Hollow inverted baseless pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<row; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<n-row; col++) {
    //         if(col==0 || col==(n-row-1)) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         } 
    //     }
    //     cout << endl;
    // }


    // // Hollow baseless pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<n-row-1; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<row+1; col++) {
    //         if(col==0 || col==(row+1-1)) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         }
            
    //     }
    //     cout << endl;
    // }


    // // Full diamond = Full pyramid + Inverted full pyramid

    // // Full pyramid
    // int n, col, row, num;
    // cin >> num;
    // n = num/2;
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<n-row-1; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<row+1; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // // Inverted full pyramid
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<row; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<n-row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    // // Inverted full pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<row; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<n-row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    // // Full pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<n-row-1; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<row+1; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    // // Mirror half pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     // for spaces
    //     for(col=0; col<n-row-1; col++) {
    //         cout << " ";
    //     }
    //     // for stars
    //     for(col=0; col<row+1; col++) {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }


    // // Inverted numeric half pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     for(int col=0; col<n-row; col++) {
    //         cout << col+1 << " ";            
    //     }
    //     cout << endl;
    // }


    // // Numeric half pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     for(int col=0; col<row+1; col++) {
    //         cout << col+1 << " ";            
    //     }
    //     cout << endl;
    // }


    // // Inverted half pyramid
    // int n, col, row;
    // cin >> n;
    // for(int row=0; row<n; row++) {
    //     for(int col=0; col<n-row; col++) {
    //         cout << "* ";            
    //     }
    //     cout << endl;
    // }


    // Half pyramid
    int n, col, row;
    cin >> n;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < row + 1; col++) {
            cout << "* ";            
        }
        cout << endl;
    }


    // // Hollow square
    // int n, col, row;
    // cin >> n;
    // for(int row = 0; row < n; row++) {
    //     for(int col = 0; col < n; col++) {
    //         if(row == 0 || row == n - 1 || col == 0 || col == n - 1) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }


    // // Simple square
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    return 0;
}