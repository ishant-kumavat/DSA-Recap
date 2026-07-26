// LeetCode 1342 => ** Number of Steps to Reduce a Number to Zero **

// Optimal Solution => Iterative Simulation
// Time Complexity : O(log n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while(num != 0){
            if(num % 2 == 0) num /= 2;
            else num -= 1;
            cnt++;
        }
        return cnt;
    }
};
// Repeat until the number becomes zero.
// If the number is even,
// divide it by 2.
// Otherwise,
// subtract 1.
// Count every operation
// and return the total steps.