// LeetCode 1189 => ** Maximum Number of Balloons **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)

// LeetCode 1189 => Maximum Number of Balloons
// Optimal Approach => Character Frequency Counting
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> hasharr(26, 0);

        for(auto it : text)
            hasharr[it - 'a']++;

        int ans = hasharr[0];          // b
        ans = min(hasharr[0], hasharr[1]); // a
        ans = min(ans, hasharr[11] / 2);   // l
        ans = min(ans, hasharr[13]);       // n
        ans = min(ans, hasharr[14] / 2);   // o

        return ans;
    }
};

// Count the frequency of each character using a hash array.
//
// The word "balloon" requires:
// b = 1, a = 1, l = 2, o = 2, n = 1.
//
// Divide the frequencies of l and o by 2.
// The minimum frequency gives the maximum number
// of times the word "balloon" can be formed.