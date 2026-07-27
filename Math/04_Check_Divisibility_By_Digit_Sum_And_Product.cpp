// 3622 => ** Check Divisibility by Digit Sum and Product **

// Optimal Solution => Digit Extraction
// Time Complexity : O(log n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        long long sum = 0, product = 1;
        while(ori != 0){
            int ld = ori % 10;
            sum += ld;
            product *= ld;
            ori /= 10;
        }
        long long add = sum + product;
        if(n % add == 0) return true;
        return false;
    }
};
// Extract each digit of the number.
// Compute the sum
// and product of its digits.
// Add both values.
// If the original number
// is divisible by the result,
// return true;
// otherwise, return false.