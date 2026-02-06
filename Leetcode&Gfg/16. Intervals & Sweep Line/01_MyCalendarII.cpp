// Leetcode: 731. My Calendar II   --->   You are implementing a program to use as your calendar. We can add a new event if
// adding the event will not cause a triple booking.
// A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).
// The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open
// interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.
// Implement the MyCalendarTwo class:
// ● MyCalendarTwo() Initializes the calendar object.
// ● boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without
//   causing a triple booking. Otherwise, return false and do not add the event to the calendar.

// Example 1:
// Input
// ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
// [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
// Output
// [null, true, true, true, false, true, true]
// Explanation
// MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
// myCalendarTwo.book(10, 20); // return True, The event can be booked. 
// myCalendarTwo.book(50, 60); // return True, The event can be booked. 
// myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
// myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
// myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
// myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the
// third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.


// Algorithm: It is simple. The idea is to maintain two lists:
// ● bookings: This list will store all the single-booked intervals.
// ● overlapBookings: This list will store all the double-booked intervals (only the overlap region).
// 1. When we try to book a new interval [startTime, endTime), we first check if it overlaps with any of the intervals
//    in overlapBookings. If it does, that means this new booking would cause a triple booking, and we return false.
// 2. If it does not cause a triple booking, we then check for overlaps with all existing bookings in the bookings list.
//    For each existing booking that overlaps with the new interval, we calculate the overlap interval and add it to the
//    overlapBookings list. This way, we keep track of all double-booked intervals.
// 3. Finally, the new booking is added to the bookings list and return true.

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
private:
    // Stores all single-booked intervals
    vector<pair<int,int>> bookings;

    // Stores all double-booked (overlap) intervals
    vector<pair<int,int>> overlapBookings;

public:
    MyCalendarTwo() {}
    
    // T.C: O(n);   where n = no.of existing bookings
    // S.C: O(n)    for storing bookings and overlaps
    bool book(int startTime, int endTime) {
        // STEP 1: Check if new interval causes TRIPLE BOOKING
        for(auto &overlap : overlapBookings) {
            int oStartTime = overlap.first;
            int oEndTime   = overlap.second;

            // If new interval overlaps with any existing DOUBLE BOOKING
            if(max(startTime, oStartTime) < min(endTime, oEndTime)) {
                return false;   // triple booking detected
            }
        }

        // STEP 2: Compute overlaps with existing bookings
        for(auto &b : bookings) {
            int bStart = b.first;
            int bEnd   = b.second;

            // Calculate overlap interval between new booking and existing booking
            int overlapStart = max(startTime, bStart);
            int overlapEnd = min(endTime, bEnd);

            // If overlap really exists, store this interval as a double-booked interval
            if(overlapStart < overlapEnd) {
                overlapBookings.push_back({overlapStart, overlapEnd});
            }
        }

        // STEP 3: Accept the booking
        bookings.push_back({startTime, endTime});
        return true;
    }
};


int main() {
    MyCalendarTwo* myCalendarTwo = new MyCalendarTwo();

    cout << myCalendarTwo->book(10, 20) << endl;   // o/p: true
    cout << myCalendarTwo->book(50, 60) << endl;   // o/p: true
    cout << myCalendarTwo->book(10, 40) << endl;   // o/p: true
    cout << myCalendarTwo->book(5, 15) << endl;   // o/p: false
    cout << myCalendarTwo->book(5, 10) << endl;   // o/p: true
    cout << myCalendarTwo->book(25, 55) << endl;   // o/p: true

    return 0;
}
