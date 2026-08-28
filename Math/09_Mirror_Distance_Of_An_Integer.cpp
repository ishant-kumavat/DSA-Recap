// LeetCode 3783 => ** Mirror Distance of an Integer **

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