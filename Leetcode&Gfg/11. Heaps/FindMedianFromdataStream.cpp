// Leetcode 295. Find Median from Data Stream   --->   The median is the middle value in an ordered integer list.
// If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// -> For example, for arr = [2,3,4], the median is 3.
// -> For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

// Implement the MedianFinder class:
// -> MedianFinder() initializes the MedianFinder object.
// -> void addNum(int num) adds the integer num from the data stream to the data structure.
// -> double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// Algorithm:
// 1. Create two heaps: maxHeap(to store left elements of median) and minHeap(to store right elements of median).
// 2. Add numbers always to maxHeap. Then handle 3 cases in order:
//    i.   If top element of maxHeap is greater than top element of minHeap, it means right place for that element is in minHeap.
//    ii.  If maxHeap contains more than 1 extra element in it compared to minHeap, shift the top element from maxHeap to minHeap
//         to make both their sizes equal.
//    iii. If minHeap contains more than 1 extra element in it compared to maxHeap, shift the top element from minHeap to maxHeap
//         to make both their sizes equal.
// 3. If size of maxHeap is greater than minHeap, the median lies on top element of maxHeap. If size of minHeap is greater than
//    maxHeap, the median lies on top element of minHeap. If they both are equal, the median lies on average of both top elements.

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<double> maxHeap;   // to store the smaller half of the numbers.
    priority_queue<double, vector<double>, greater<double>> minHeap;   // to store the larger half of the numbers.

    MedianFinder() {}
    
    // T.C: O(logn)
    // S.C: O(n)
    void addNum(int num) {
        maxHeap.push(num);   // Push the element in maxHeap first, then process both heaps accordingly

        // If top element of maxHeap is greater than top element of minHeap, it means right place for that element is in minHeap
        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            double temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }

        // If maxHeap contains more than 1 extra element in it compared to minHeap,
        // shift the top element from maxHeap to minHeap to make both their sizes equal.
        if(maxHeap.size() > minHeap.size() + 1) {
            double temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }

        // If minHeap contains more than 1 extra element in it compared to maxHeap,
        // shift the top element from minHeap to maxHeap to make both their sizes equal.
        if(minHeap.size() > maxHeap.size() + 1) {
            double temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
    }
    
    // T.C: O(1)
    // S.C: O(1)
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        if(minHeap.size() > maxHeap.size()) return minHeap.top();
        return (maxHeap.top() + minHeap.top())/2;   // if(minHeap.size() == maxHeap.size())
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder* mf = new MedianFinder();
    vector<int> numbers = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    for(int num : numbers) {
        mf->addNum(num);
        cout << "Added " << num << ", current median is: " << mf->findMedian() << endl;
    }

    delete mf;

    return 0;
}
