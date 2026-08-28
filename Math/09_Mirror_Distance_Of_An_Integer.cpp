// LeetCode 3783 => ** Mirror Distance of an Integer **

// Optimal Solution => Number Reversal + Absolute Difference
// Time Complexity : O(log10(n))
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse_number(int n){
        int rev = 0;
        while(n != 0){
            int ld = n % 10;
            rev = (rev * 10) + ld;
            n /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev = reverse_number(n);
        return abs(rev - n);
    }
};

// Reverse the given number
// using the digit extraction method.
//
// Extract the last digit using:
// n % 10
//
// Add the extracted digit to the
// reversed number:
//
// rev = (rev * 10) + ld
//
// Remove the last digit using:
// n /= 10
//
// After reversing the number,
// calculate the absolute difference
// between the original number and
// its reversed number.
//
// Return the mirror distance.