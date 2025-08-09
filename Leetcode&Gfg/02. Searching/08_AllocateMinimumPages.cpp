// GFG: You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book.
// You also have an integer k representing the number of students. The task is to allocate books to each student such that:
// • Each student receives atleast one book.
// • Each student is assigned a contiguous sequence of books.
// • No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible
// allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation
// for better understanding).

// Example 1:
// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113, which is selected as the output.

// Example 2:
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Allocation can not be done.

// Example 3:
// Input: arr[] = [22, 23, 67], k = 1
// Output: 112

#include <bits/stdc++.h>
using namespace std;

// Algorithm: Although its a hard problem, the algorithm is easy if you deeply concentrate in the problem.
// --- LINEAR SEARCH ---
// 1. The minimum no.of maximum pages assigned to any student can range from the no.of pages the thickest book has, i.e.,
//    maximum element in the given array, to the sum of pages of all books, i.e., sum of all elements of given array. The
//    range starts from no.of pages in the thickest book because:
//    Consider the array: [12, 34, 67, 90], k = 2.
//    If lets say the minimum no.of maximum pages a student can hold is 67, then how can anyone hold the last book with
//    90 pages ? Thus, a potienial answer shall be atleast the maximum element of given array, i.e., 90 in this case.
//    Extra fact: The answer would be really 90, if the value of k had been 4.
//    Edge case: If 'k > arr.size()', it's not possible to distribute books among all the 'k' students. Thus, return -1.
// 2. Now create another function 'isPossible()' to check if its possible to allocate all books among 'k' students
//    given that a student can hold atmost 'maxPagesAllowed' no.of pages. The value of 'maxPagesAllowed' will range
//    from the above search space as discussed in step 1, i.e., no.of pages in the thickest book to sum of pages of
//    all books. Thus, iterate all values of 'maxPagesAllowed' and the smallest value for which the function
//    'isPossible()' returns a true is the minimum no.of maximum pages assigned to any student. Thus, return this answer.

// --- BINARY SEARCH ---
// 1. The 'ifPossible() function the remains the same; only the driver function changes. We already know that the search space
//    lies in the range no.of pages the thickest book has, i.e., maximum element in the given array, to the sum of pages
//    of all books, i.e., sum of all elements of given array. Thus, we will apply binary search on this search space.
//    Initialize 'start' and 'end' as usual with the lower and upper limit of the above mentioned search space.
// 2. Find 'mid' by computing 'start + (end - start) / 2' as usual. Here 'mid' denotes the limit of no.of pages that
//    a student is allowed to hold, i.e., 'maxPagesAllowed' of linear serach. Send the value of 'mid' to the
//    'isPossible()' function and check if it's possible to allocate all books among 'k' students for given value
//    of 'mid'. If it's possible to form a valid allocation, store this potential answer in any variable say 'ans'
//    and continue the binary search as a smaller value of of 'mid' could also be found in further iterations.
//    Continue this process until 'start' crosses 'end'.
// 3. At the end of the loop while(start <= end), the 'ans' will contain the smallest value of 'mid' for which a
//    valid allocation is possible among 'k' students. Thus, return the vale of 'ans'.

// 'isPossible()' function algorithm:
//  i.  Initialize two variables 'students' and 'pagesStudent' to keep track of no.of students required to
//      distribute all books; and pages allocated to the current student, respectively.
//      Initially try to allocate as many books as possible to only 1 student. Start the book allocation from the 1st
//      book, i.e., from arr[0]. The moment when it's not possible to allocate any further book to the current student
//      due to the constraint of no. of pages allocated to that student is exceeding the 'maxPagesAllowed' limit;
//      add a new student(student++) and allocate the next book to the new student(pagesStudent = arr[i]).
//  ii. After the iteration of all books, we will be having the count of no.of students required to distribute
//      all books among 'k' students in the 'students' variable. Note that lesser the limit of 'maxPagesAllowed',
//      higher is the 'students' value.
//      Hence, if value of 'students' is more than 'k', the books cannot be allocated in just 'k' students, i.e., more
//      students are required to distribute all books among them. Thus, return false. Else return true stating that
//      it's possible to allocate all books among 'k' students for the given limit of 'maxPagesAllowed'.

// Some useful predefined methods of C++ that you may use in this code:
// 1. *max_element(arr.begin(), arr.end()): Returns the largets element of 'arr'.
// 2. accumulate(arr.begin(), arr.end(), x): Calculates the sum of all elements of 'arr' with starting sum as 'x'.
//                                           If you want, exact sum of all elements, keep the value of 'x' as 0.


class Solution {
private:
    // This function tells if it's possible to allocate all books among 'k' students
    // or not, given that a student can hold atmost 'maxPagesAllowed' no.of pages.
    bool isPossible(vector<int>& arr, int maxPagesAllowed, int k) {
        int students = 1;   // no.of students (start with one student initially)
        long long pagesStudent = 0;   // pages allocated to the current student

        // Allocate as many books possible to a student at a time. The moment when next book cannot be
        // allocated to the current student, add a new student and allocate the next book to the new student.
        for(int i = 0; i < arr.size(); i++) {
            if(pagesStudent + arr[i] <= maxPagesAllowed) pagesStudent += arr[i];
            else {
                students++;   // allocate a new student
                pagesStudent = arr[i];   // allocate the current book to the new student
            }
        }

        // Given the condition, a student can hold atmost 'maxPagesAllowed' no.of pages, if the number of students required
        // to distribute all books is more than 'k', then it's not possible to allocate all books among 'k' students.
        return students > k ? false : true;
    }

    // ● Why not return true only if students == k, why we return true when students <= k ?
    //   Try out example: arr = [15, 10, 19, 10, 5, 18, 7], k = 5
    //   If we return true only on students == k, then the function will always return false for every value of
    //   'maxPagesAllowed' for the given example. Technically for this example, number of students we get according
    //   to the code we have written is never bound to yield count of students as 5, it will always yield a count
    //   greater than 5 or less than 5.
    //   Illustration:
    //   Let's say we allocated maximum pages for a student as 24. In this case, the minimum number of students
    //   required to distribute all books will come out to be 6 (15, 10, 19, {10 + 5}, 18, 7), which is greater
    //   than k = 5. Hence, books cannot be allocated among 5 students.
    //   But when we allocate maximum pages for a student as 25,  the minimum number of students required to
    //   distribute all books is 4, which is not equal to k = 5, but less than k.
    //   But 25 is only the answer because if we can distribute all books among 4 students ({15 + 10}, 19, 15, {18 + 7}),
    //   we can also distribute all books among 5 students({15 + 10}, 19, 15, 18, 7) or (15, 10, 19, 15, {18 + 7}).
    //   Hence, return true if students <= k, not only when students == k.

public:
    // Linear search
    // T.C: O((sum - maxi + 1) * n);   where sum = sum of all elements of 'arr', maxi = maximum element of 'arr', and n = arr.size()
    // S.C: O(1)
    int findPages_bruteforce(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;

        int maxi = 0, sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }

        // 'maxPagesAllowed' is limit of maximum no.of pages that can be allowed to allocate to a student.
        // Return the smallest value of 'maxPagesAllowed' for which the 'isPossible()' function returns true.
        for(int maxPagesAllowed = maxi; maxPagesAllowed <= sum; maxPagesAllowed++) {
            if(isPossible(arr, maxPagesAllowed, k)) {
                return maxPagesAllowed;
            }
        }
    }

// --------------------------------------------------------------------------------------------------------

    // Binary search
    // T.C: O(log(end - start + 1) * n);   where end = sum of all elements of 'arr', start = maximum element of 'arr', and n = arr.size()
    // S.C: O(1)
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;

        int start = 0, end = 0;
        for(int i = 0; i < arr.size(); i++) {
            start = max(start, arr[i]);
            end += arr[i];
        }

        int ans;
        // Store the smallest value of 'maxPagesAllowed' for which the 'isPossible()' function returns true.
        // Here 'maxPagesAllowed' is denoted by 'mid'.
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isPossible(arr, mid, k)) {
                ans = mid;   // 'mid' can be potential answer. Thus, store it.
                end = mid - 1;   // try for smaller maximum
            } else start = mid + 1;   // increase the limit of max no.of pages that is allowed to be allocated to a student
        }

        return ans;
    }
};


int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 4;

    cout << Solution().findPages_bruteforce(arr, k) << endl;
    cout << Solution().findPages(arr, k);

    return 0;
}
