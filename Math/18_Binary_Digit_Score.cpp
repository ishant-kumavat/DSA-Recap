// LeetCode 4092 => ** Binary Digit Score **

// Approach 1 => Built-in Function
// Time Complexity : O(1) for fixed-width integers
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = __builtin_popcount(a);
        int s2 = __builtin_popcount(b);

        return (s1 >= s2) ? (s1 * s2) : (s2 / s1);
    }
};

// Approach 2 => Repeated Division
// Time Complexity : O(log x) per number, for x > 0
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Count_set_bits(int x){
        int cnt = 0;

        while(x != 0){
            if(x % 2 == 1) cnt ++;
            x /= 2;
        }
        return cnt;
    }

    int calculateScore(int a, int b) {
        int s1 = Count_set_bits(a);
        int s2 = Count_set_bits(b);

        return (s1 >= s2) ? (s1 * s2) : (s2 / s1);
    }
};

// Divide the number by 2 repeatedly to check its binary digits.
//
// If x % 2 == 1, the last binary digit is 1,
// so increment the count.
//
// Divide x by 2 to process the next binary digit.
//
// Repeat until x becomes 0, then return the count.