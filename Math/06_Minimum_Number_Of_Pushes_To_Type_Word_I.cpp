// LeetCode 3014 => ** Minimum Number of Pushes to Type Word I **

// Optimal Solution => Greedy Assignment
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (i / 8) + 1;
        }
        return ans;
    }
};
// Assign the letters
// in the order
// of increasing push cost.
//
// The first 8 letters
// require 1 push,
// the next 8 require 2 pushes,
// and so on.
//
// Compute the push cost
// for each character
// based on its position
// and return
// the total number of pushes.