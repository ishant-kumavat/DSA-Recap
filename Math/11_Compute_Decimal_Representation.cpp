// LeetCode 3697 => ** Compute Decimal Representation **

// Optimal Solution => Digit Extraction + Place Value
// Time Complexity : O(log n)
// Space Complexity : O(log n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        if(n <= 10) return {n};
        vector<int> ans;
        long long place  = 0;
        while(n != 0){
            int ld = n % 10;
            if(place  == 0) place  = 10;
            else {ld *= place ; place  *= 10;}
            if(ld != 0) ans.push_back(ld);
            n /= 10; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Extract digits from the number
// starting from the least significant digit.
//
// Convert each digit into its
// corresponding place value:
//
// digit × place value
//
// For example:
// 3527 -> 3000, 500, 20, 7
//
// Ignore zero-valued place values.
//
// Since digits are extracted from right
// to left, reverse the answer at the end.
//
// Return the decimal representation.