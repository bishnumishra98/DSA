// Given a number n, print sum of 1 to n
// -> Parametarized recursion: Parameterized recursion involves adding extra parameters to the recursive function to
//                             maintain state or carry information through the recursive calls. These parameters help
//                             in keeping track of computations or intermediate results.
// -> Functional recursion: Also known as pure recursion, involves defining the recursive function in such a way that
//                          each call returns a result that is used in the next call. There are no extra parameters to
//                          maintain state; instead, each function call produces a value that contributes to the final result.

#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
void sum_p(int i, int sum) {
    if(i < 1) {
        cout << sum;
        return;
    }
    sum_p(i-1, sum+i);
}
// Recursive tree
// sum_p(4, 0) -> sum_p(3, 0+4) -> sum_p(2, 0+4+3) -> sum_p(1, 0+4+3+2) -> sum_p(0, 0+4+3+2+1). When sum_p(0, 10) was called, the
// base case if(i < 1) became true, and the sum got printed. Then all functions returned one by one to empty the recursive stack.

// T.C: O(n)
// S.C: O(n)
int sum_f(int i) {
    if(i == 1) return 1;
    return i + sum_f(i-1);
}

int main() {
    int i = 1;   // first sum of sum of series
    int n = 4;   // last number of sum of series
    int sum = 0;

    cout << "sum_parametarizedRecursion: ";
    sum_p(n, sum);
    cout << endl;
    cout << "sum_functionalRecursion: " << sum_f(n) << endl;

    return 0;
}
