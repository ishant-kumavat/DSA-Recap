// LeetCode 202 => ** Happy Number **

// Optimal Approach => Hash Set + Cycle Detection
// Time Complexity : O(log n)
// Space Complexity : O(log n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_digit_sqr_sum(int n){
        int res = 0;
        while(n != 0){
            int ld = n % 10;
            res += (ld * ld);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        st.insert(n);
        while(true){
            n = find_digit_sqr_sum(n);
            if(n == 1) return true;
            if(st.find(n) != st.end()) return false;
            st.insert(n);
        }
        return false;
    }
};
// Repeatedly replace the number
// with the sum of the squares
// of its digits.
// Store every generated number
// in a hash set.
// If 1 is reached,
// the number is happy.
// If a number repeats,
// a cycle exists,
// so the number is not happy.