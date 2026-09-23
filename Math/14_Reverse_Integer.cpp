// LeetCode 7 => ** Reverse Integer **

// Optimal Solution => Digit Extraction + Overflow Check
// Time Complexity : O(log |x|)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x != 0){
            int ld = x % 10;
            ans = (ans * 10) + ld;
            if(ans > INT_MAX || ans < INT_MIN) return 0;
            x /= 10; 
        }
        return ans;
    }
};

// Extract the last digit using `x % 10`.
//
// In C++, `%` and `/` operators also work with negative numbers.
//
// For a negative number:
// `x % 10` gives the last digit with its sign.
// `x /= 10` removes the last digit while preserving the sign.
//
// Build the reversed number by:
// ans = ans * 10 + last_digit
//
// Check for INT_MIN and INT_MAX overflow
// while constructing the reversed number.