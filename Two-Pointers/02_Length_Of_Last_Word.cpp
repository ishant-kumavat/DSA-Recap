// LeetCode 58 => ** Length of Last Word **

// Optimal Solution => Two Pointer
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' ')  i--;
        if(i < 0) return 0;
        int ans = 0;
        while(i >= 0 && s[i] != ' ') {
            ans ++; 
            i--;
        }
        return ans;
    }
};

// Start from the last character of the string.
//
// Skip trailing spaces.
//
// Count characters until a space or the beginning
// of the string is reached.
//
// Return the count, which is the length
// of the last word.