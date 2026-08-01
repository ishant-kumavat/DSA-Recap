// LeetCode 3536 => ** Maximum Product of Two Digits **

// Optimal Solution => Track Two Largest Digits
// Time Complexity : O(m), where m  is number of digits in n.  
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(int n) {
        int org = n;
        int d1 = 0, d2 = 0;
        while(org != 0){
            int ld = org % 10;
            if(d1 <= ld){
                d2 = d1;
                d1 = ld;
            }
            else if(d1 != d2 && d2 < ld) d2 = ld;
            org /= 10; 
        }
        return (d1 *d2);
    }
};
// Extract each digit
// of the number.
// Keep track of
// the largest and
// second largest digits.
// Return the product
// of these two digits.