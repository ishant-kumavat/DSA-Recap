// LeetCode 2486 => ** Append Characters to String to Make Subsequence **

// Optimal Solution => Two Pointers
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int n = s.length(), m = t.length();

        while(i < n){
            if(s[i] == t[j]) j++;
            i++;
        }

        return (m - j);
    }
};

// Use two pointers to traverse both strings.
//
// If characters match, move the pointer of t forward.
// Always move the pointer of s forward.
//
// After traversing s, calculate how many characters
// of t are still unmatched.
//
// These remaining characters need to be appended.