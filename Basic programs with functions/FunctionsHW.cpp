#include <iostream>
#include <cmath>
using namespace std;

//Find area of a circle
double areaOfCircle(double r) {
    return M_PI*r*r;
}

// Factorial of a number
long fact(int n) {
    if(n<0) {
        return 0;
    }
    long ans = 1;
    for(int i=1; i<=n; i++) {
        ans *= i;
    }
    return ans;
}

// checking Prime or Composite number
bool checkPrime(int n) {
    if(n<=1) {
        return false;
    }

    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;
        }
    }
    
    return true;
}

// Create a number using digits
int buildNumber(int arr[], int size) {
    int ans = 0;

    for(int i=0; i<size; i++) {
        ans = (ans * 10) + arr[i];
    }

    return ans;
}

// Armstrong number
bool checkArmstrong(int n) {
    int num = n;   // keeping a backup of original number

    // counting no.of digits in number
    int count_digits = 0;
    while(n) {
        count_digits++;
        n = n / 10;
    }

    // checking Armstrong number logic
    n = num;   // as n became 0 in last operation, we are setting back n to its original value
    int bit, sum = 0;
    while(n) {
        bit = n % 10;
        sum = sum + round(pow(bit, count_digits));   // The pow() function in C++ returns a floating-point number, even if the inputs are integers. So better round off for precise output.
        n = n / 10;
    }

    // comparing value in sum with original number
    if(sum == num) {
        return true;
    } else {
        return false;
    }   
}

// Binary of a decimal number
int intToBinary(int n) {
    long long ans = 0;
    int bit, i = 0;
    
    while(n) {
        bit = n & 1;   // kicking out last bit of binary number
        ans = ans + (bit * round(pow(10, i)));
        n = n >> 1;
        i++;
    }

    return ans;
}

// Decimal of a binary number
int BinaryToInt(long long n) {
    int bit, i = 0, ans = 0;

    while(n) {
        bit = n % 10;   // kicking out last bit of decimal number
        ans = ans + (bit * round(pow(2, i)));
        n = n / 10;
        i++;
    }

    return ans;
}

// Palindrome number
bool checkPalindromeNumber(int n) {
    int num = n;
    int bit, ans = 0;
    while(n) {
        bit = n % 10;
        ans = (ans * 10) + bit;
        n = n / 10;
    }
    if(ans == num) {
        return true;
    } else {
        return false;
    }
}

// Palindrome string
bool checkPalindromeString(string str) {
    int len = str.length();
    int i = 0, j = len - 1;
    while(i<j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int main() {
    // //Find area of a circle
    // double r;
    // cin >> r;
    // cout << "Area of circle is: " << areaOfCircle(r);


    // // Factorial of a number
    // int n;
    // cin >> n;
    // cout << "Factorial: " << fact(n);


    // // Find all prime numbers from 1 to n
    // int n;
    // cin >> n;
    // for(int i=1; i<=n; i++) {
    //     if(checkPrime(i)) {
    //         cout << i << endl;
    //     }
    // }


    // // Print all digits of a number
    // long n;
    // int rem;
    // cin >> n;
    // while(n) {
    //     rem = n % 10;
    //     cout << rem << endl;
    //     n = n / 10;
    // }


    // // Create a number using digits
    // int n;
    // cout << "Enter the number of digits in the number: ";
    // cin >> n;
    // int num[n];
    // cout << "Enter the digits one by one: ";
    
    // for(int i=0; i<n; i++) {
    //     cin >> num[i];
    // }

    // cout << "The number is: " << buildNumber(num, n);


    // // Armstrong number
    // int n;
    // cin >> n;
    // if(checkArmstrong(n)) {
    //     cout << "Armstrong number";
    // } else {
    //     cout << "Not an Armstrong number";
    // }


    // // Binary of a decimal number
    // int n;
    // cin >> n;
    // cout << "Binary representation: " << intToBinary(n);


    // // Decimal of a binary number
    // long long n;
    // cin >> n;
    // cout << "Binary representation: " << BinaryToInt(n);
        
    
    // // Palindrome number
    // int n;
    // cin >> n;
    // if(checkPalindromeNumber(n)) {
    //     cout << "Palindrome number";
    // } else {
    //     cout << "Not a Palindrome number";
    // }


    // // Palindrome string
    // string str;
    // cin >> str;
    // if(checkPalindromeString(str)) {
    //     cout << "Palindrome";
    // } else {
    //     cout << "Not a palindrome";
    // }



    return 0;
}