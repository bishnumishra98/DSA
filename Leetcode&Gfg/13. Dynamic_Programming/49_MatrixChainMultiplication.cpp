// GFG: matrix Chain Multiplication   --->   Given an array arr[] which represents the dimensions of a sequence of
// matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to
// multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// Example 1:
// Input: arr[] = [2, 1, 3, 4]
// Output: 20
// Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3.
// There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a
// 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
// ((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
// (M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
// The minimum of these two is 20.

// Example 2:
// Input: arr[] = [1, 2, 3, 4, 3]
// Output: 30
// Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and
// M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3)
// + (1 x 3 x 4) + (1 x 4 x 3) = 30.

// Example 3:
// Input: arr[] = [3, 4]
// Output: 0
// Explanation: As there is only one matrix so, there is no cost of multiplication.


// Basics of matrix:
// 1. Two matrices can only be multiplied if matrix A consists of 'x' rows and 'y' columns, and matrix B consists of
//    'y' rows and 'z' columns, i.e., the number of columns in the first matrix must be equal to the number of rows
//    in the second matrix. And the resulting matrix will have 'x' rows and 'z' columns, i.e., the number of rows in
//    the first matrix and the number of columns in the second matrix. Also, the number of multiplications needed to
//    make the resultant matrix is (x * y * z).

// ● Illustration: Matrix A has 2 rows and 3 columns, while matrix B has 3 rows and 2 columns. Thus, the product of
//                 these two matrices will result in 2 * 3 * 2 = 12 multiplications and the dimension of the
//                 resultant matrix will be size 2 × 2.
//   A = |1, 2, 3|     B = |7, 8  |
//       |4, 5, 6|         |9, 10 |
//                         |11, 12|
//
//   Resultant = |1*7 + 2*9 + 3*11, 1*8 + 2*10 + 3*12|
//               |4*7 + 5*9 + 6*11, 4*8 + 5*10 + 6*12|
//
//             = |58, 64  |
//               |139, 154|

// 2. The order of multiplication matters, i.e., Matrix A * Matrix B is not equal to Matrix B * Matrix A. The number
//    of multiplications required to multiply two matrices and the dimension of the resultant matrix can vary based
//    on the order in which they are multiplied.

// 3. '(matrix1 * matrix2) * matrix3' and 'matrix1 * (matrix2 * matrix3)' give the same resultant matrix, but the
//    no. of multiplications required to compute the resultant matrix will differ based on the order of multiplication.


// Algorithm: Just remember the 3 simple steps for all partition dp problems.
//            1. Start with the entire block / array.
//            2. Try out all partitions(divide block/array into two groups), probably by running a loop.
//            3. Return the best possible partition.
//
//            It is a 100% visualization problem. The better you visualize, the easier the algorithm will be for you.
//            You are given an array = [1, 2, 3, 4, 3], of size 5. It is given that the 'i'th matrix in the given array
//            has the dimensions (arr[i - 1] x arr[i]) for i >= 1.
//            Thus, there can be 5 - 1 = 4 matrices present with the following dimensions: matrix1 = 1 × 2, matrix2 = 2 × 3,
//            matrix3 = 3 × 4, and matrix4 = 4 × 3. And now we are supposed return the minimum number of multiplications
//            required to multiply the four matrices in order, i.e., return the minimum number of multiplications
//            required to find the resultant matrix formed by computing matrix1 * matrix2 * matrix3 * matrix4.
//            Now we can partition the matrices in different ways to find the resultant matrix. If there are 'n'
//            matrices, then there can be (n - 1) partitions possible.
//            For example, as there were 4 matrices, we can partition the matrices in the 3 ways:
//            1. matrix1 * (matrix2 * matrix3 * matrix4)
//            2. (matrix1 * matrix2) * (matrix3 * matrix4)
//            3. (matrix1 * matrix2 * matrix3) * matrix4
//            Thus, to find out which way yields the least number of multiplications, we have to try out all possible
//            ways via recursion. Call a function f(i, j) which returns the least number of multiplications required
//            to build the resultant matrix, where 'i' is the index of array which represents the number of columns
//            in the 'i'th matrix and 'j' is the index of the array which represents the number of columns in the 'j'th
//            matrix. Thus, for the array = [1, 2, 3, 4, 3], of size 5; call the recursive function initially with the
//            arguments f(1, 4), where 1st index, i.e., 2 is no.of columns in first matrix and 4th index, i.e., 3 is
//            number of columns in the fourth matrix. In every recursive call, 'j - 1' new partitions are made, example:
//            f(1, 4) calls f(1, 1) and f(2, 4) for the first partition, f(1, 2) and f(3, 4) for the second partition,
//            and f(1, 3) and f(4, 4) for the third partition, and eventually returns the partition from where it gets the
//            minimum number of multiplications. Similarly, any other function let's say f(2, 4) will call f(2, 2) and
//            f(3, 4) for the first partition, f(2, 3) and f(4, 4) for the second partition, and eventually returns the
//            partition from where it gets the minimum number of multiplications. And so on the recursion continues until
//            the base case is reached.
//            1. Base case: When only one matrix is left, i.e., when 'i' reaches 'j'. Multipyling a matrix with itself
//                          does not makes any sense. Hence return 0 stating that 0 multiplications are required to
//                          form the resultant matrix as the resultant matrix is the matrix itself.
//            2. Recursive relation: At any pair of (i, j), we can have different partitions. For example: for f(1, 4),
//                                   we have to try out all 3 partitions to find the minimum no.of multiplications
//                                   required to find the resultant of the 4 matrices. Those 3 partitions are:
//                                   1. matrix1 * (matrix2 * matrix3 * matrix4)
//                                   2. (matrix1 * matrix2) * (matrix3 * matrix4)
//                                   3. (matrix1 * matrix2 * matrix3) * matrix4
//                                   Run a loop to partition the matrices into two groups. The first group can be
//                                   represented by f(i, k) and the second group can be represented by f(k + 1, j) where
//                                   'k' runs from 'i' to 'j - 1'.
//                                   ● Illustration: For f(1, 4), k runs from 1 to 3.
//                                   When k = 1, first group = f(1, 1) and second group = f(2, 4).
//                                   When k = 2, first group = f(1, 2) and second group = f(3, 4).
//                                   When k = 3, first group = f(1, 3) and second group = f(4, 4).
//                                   Now in the above partitions, let's take the second one when k = 2. Let the resultant
//                                   matrix of (matrix1 * matrix2) be matrix12 and the resultant matrix of
//                                   (matrix3 * matrix4) be matrix34. Then, the expression
//                                   '(matrix1 * matrix2) * (matrix3 * matrix4)' boils down to 'matrix12 * matrix34'.
//                                   And to multiply matrix12 and matrix34, the number of multiplications
//                                   required will be (r12 * c12(=r34) * c34), where 'r12' is the number of rows in
//                                   matrix12, 'c12' is the number of columns in matrix12 which equals to the number of
//                                   rows in matrix34, and 'c34' is the number of columns in matrix34.
//                                   According to matrix multiplication rule, we know that matrix12 has a dimension of
//                                   r1 × c2, where 'r1' is the number of rows in matrix1 and 'c2' is the number of
//                                   columns in matrix2. Thus, number of rows in matrix12, i.e., r12 is number of rows
//                                   in matrix1, i.e., r1. And the number of columns in matrix12, i.e., c12 is the number
//                                   of columns in matrix2, i.e., c2.
//                                   Hence, (r12 * c12 * c34) can also be written as r1 * c2 * c4.
//                                   Hence, no.of multiplications needed to find resultant of matrix12 * matrix34 is
//                                   r1 * c2 * c4. At this point k is 2, i.e., 2nd index of the given array [1, 2, 3, 4, 3]
//                                   in the function call of f(1, 4) where i = 1 and j = 4.
//                                   In the given array, 'r1' is arr[0], 'c2' is arr[2], and 'c4' is arr[4]. Hence, number
//                                   of multiplications needed of find resultant of 'matrix12 * matrix34' is nothing but
//                                   'arr[0] * arr[2] * arr[4]' or 'arr[i - 1] * arr[k] * arr[j]'.
//                                   Now the matrix12 and matrix34 would also have taken some number of multiplications
//                                   to form a resultant. And we need the least number of multiplications to form the
//                                   resultant matrix12 which is given by f(1, 2) or f(1, k); similarly the least number
//                                   of multiplications to form the resultant matrix34 is given by f(3, 4) or f(k + 1, j).
//                                   Hence, f(i, k) + (arr[i - 1] * arr[k] * arr[j]) + f(k + 1, j) gives the number of
//                                   multiplications needed to form the resultant matrix of the partition
//                                   '(matrix(i) * matrix(k)) * (matrix(k+1) * matrix(j))'.
//                                   Now, we have to try out all possible partitions by running k from 1 to (j - 1), and
//                                   the value of k for which we get the least number of multiplications will be our answer.
//                                   Hence, the recursive relation is:
//                                   f(i, j) = min(f(i, k) + (arr[i - 1] * arr[k] * arr[j]) + f(k + 1, j)) for all
//                                   k from i to j - 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int> &arr) {
        if(i == j) return 0;
        int mini = 1e9;

        for(int k = i; k < j; k++) {
            int multiplications = solve(i, k, arr) + (arr[i - 1] * arr[k] * arr[j]) + solve(k + 1, j, arr);
            mini = min(mini, multiplications);
        }

        return mini;
    }

    // T.C: O(2^n) or exponential due to recomputation of overlapping subproblems
    // S.C: O(n)
    int matrixMultiplication_recursion(vector<int> &arr) {
        int n = arr.size();
        return solve(1, n - 1, arr);
    }

// --------------------------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<int> &arr, vector<vector<int>>& dp) {
        if(i == j) return 0;
        int mini = 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        for(int k = i; k < j; k++) {
            int multiplications = solve(i, k, arr, dp) + (arr[i - 1] * arr[k] * arr[j]) + solve(k + 1, j, arr, dp);
            mini = min(mini, multiplications);
        }

        return dp[i][j] = mini;
    }

    // T.C: O(n^2) for dp * O(n) for the for loop = O(n^3)
    // S.C: O(n^2) for dp table + O(n) recursion stack space = O(n^2)
    int matrixMultiplication_memoization(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n - 1, arr, dp);
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n^2) for dp * O(n) for the for loop = O(n^3)
    // S.C: O(n^2)
    int matrixMultiplication_tabulation(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Writing the base case is not needed, as all cells are already initialized to 0.

        for(int i = n - 1; i >= 1; i--) {   // reverse the order from memoization
            for(int j = i + 1; j <= n - 1; j++) {
                int mini = 1e9;
                for(int k = i; k < j; k++) {
                    int multiplications = dp[i][k] + (arr[i - 1] * arr[k] * arr[j]) + dp[k + 1][j];
                    mini = min(mini, multiplications);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }

    // ● Why inner loop runs from 'i + 1' to 'n - 1' ?
    //   Because we want to compute the minimum number of multiplications required to multiply matrices from 'i'th matrix
    //   to 'j'th matrix, for which we need at least two matrices for a valid multiplication. When 'i == j', it means there
    //   is only one matrix, and the result of multiplying a single matrix is zero. Hence, 'j' must be at least 'i + 1' to
    //   ensure we're working with a valid subproblem (a chain of two or more matrices). Inshort 'j' must be on right of
    //   'i' to ensure we're working with a valid subproblem. The loop goes up to 'n - 1' because the last valid index in
    //   the array 'arr' is 'n - 1'.
};


int main() {
    vector<int> arr = {2, 1, 3, 4};

    cout << Solution().matrixMultiplication_recursion(arr) << endl;
    cout << Solution().matrixMultiplication_memoization(arr) << endl;
    cout << Solution().matrixMultiplication_tabulation(arr);

    return 0;
}
