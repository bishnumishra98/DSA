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

// Algorithm: 

class Solution {
private:
    int countStudents(vector<int>& arr, int pages) {
        int students = 1;   // no.of students (start with one student initially)
        long long pagesStudent = 0;   // pages allocated to the current student

        // Calculate the max no.of pages a student can hold by holding him/her one book at a time, and if it exceeds the max
        // no.of pages student is allowed to hold (pages), give that book to another student, i.e., increment students by 1,
        // and allocate that many pages in that book to that student.
        for(int i = 0; i < arr.size(); i++) {
            if(pagesStudent + arr[i] <= pages) pagesStudent += arr[i];
            else {
                students++;   // allocate a new student
                pagesStudent = arr[i];   // allocate the current book to the new student
            }
        }

        return students;
    }

public:
    // T.C: O((sum-maxi+1) * n);   where sum = sum of all elements of 'arr', maxi = maximum element of 'arr', and n = arr.size()
    // S.C: O(1)
    int findPages_linearSearch(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;

        int maxi = 0, sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }

        // Perform a linear search for the smallest valid page allocation
        for(int pages = maxi; pages <= sum; pages++) {
            int students = countStudents(arr, pages);   // 'pages' is the maximum no.of pages a student is allowed to hold
            if(students == k) return pages;   // return the first valid allocation
        }

        return -1;   // If no valid allocation is found

        // // Perform a linear search for the smallest valid page allocation
        // int ans = -1;   // To store the minimum possible allocation
        // for(int pages = maxi; pages <= sum; pages++) {
        //     int students = countStudents(arr, pages);
        //     if(students <= k) {
        //         ans = pages;   // Update ans for smaller allocations
        //         break;   // Since we're performing a linear search, stop early
        //     }
        // }

        // return ans;
    }
};


int main() {
    vector<int> arr = {15, 10, 19, 10, 5, 18, 7};
    int k = 5;

    cout << Solution().findPages_linearSearch(arr, k);

    return 0;
}
