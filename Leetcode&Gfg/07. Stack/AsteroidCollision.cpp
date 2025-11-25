// Leetcode: 735. Asteroid Collision   --->   We are given an array asteroids of integers representing asteroids in a row.
// The indices of the asteroid in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right,
// negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both
// are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:
// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

// Example 2:
// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Example 3:
// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

// Example 4:
// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the
//              asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.


// Algorithm: 
// 1. Initialize an empty stack to keep track of the asteroids.
// 2. Iterate through each asteroid in the input array:
//    a. If the current asteroid is moving to the right (positive value), push it onto the stack.
//    b. If the current asteroid is moving to the left (negative value):
//       i.  While the stack is not empty and the top asteroid in the stack is moving to the right (positive value) and
//           the size of the top asteroid is less than the absolute size of the current left-moving asteroid, pop the
//           top asteroid from the stack (it explodes).
//       ii. After popping out all smaller right-moving asteroids, check the following conditions:
//           - If the stack is not empty and the top asteroid is equal in size to the current left-moving asteroid,
//             pop out the top asteroid (both asteroids explode).
//           - If the stack is empty or the top asteroid is moving to the left, push the current left-moving asteroid
//             onto the stack.
// 3. After processing all asteroids, the stack will contain the remaining asteroids after all collisions.
// 4. Return the stack as the result.

// Note: The stack is used here to efficiently manage the collisions between asteroids, allowing us to easily
//       keep track of the surviving asteroids. But if we use stack, then at the end we will have to pop all elements
//       from stack and insert them in another vector, reverse the vector and then return the final result.
//       To avoid this extra step, we can use a vector as a stack substitute as vector also follows LIFO principle.
//       We can directly push and pop elements from the back of the vector. This way, we can return the vector directly
//       as the result without needing to reverse it.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(2n) ~ O(n)
    // S.C: O(n)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int i = 0; i < asteroids.size(); i++) {
            int currAsteroid = asteroids[i];

            // If the current asteroid is moving to the right, push it onto the stack.
            if(currAsteroid > 0) {
                st.push_back(currAsteroid);
            }
            else {   // if current asteroid is moving to the left
                // If the current left-moving asteroid collides with right-moving asteroids in the stack, plus the
                // left-moving one is bigger than the right-moving one, then pop out those smaller right-moving asteroids.
                while(!st.empty() && st.back() > 0 && st.back() < abs(currAsteroid)) {
                    st.pop_back();
                }

                // After popping out all smaller right-moving asteroids, check the following conditions:
                // 1. If the stack is not empty and the top asteroid is equal in size to the current left-moving asteroid,
                //    pop out the top asteroid (both asteroids explode).
                // 2. If the stack is empty or the top asteroid is moving to the left, push the current left-moving asteroid
                //    onto the stack.
                if(!st.empty() && st.back() == abs(currAsteroid)) {
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0) {
                    st.push_back(currAsteroid);
                }
            }
        }

        return st;
    }
};

int main() {
    vector<int> asteroids = {3, 5, -6, 2, -1, 4};

    vector<int> ans = Solution().asteroidCollision(asteroids);
    for(int i: ans) cout << i << " ";

    return 0;
}
