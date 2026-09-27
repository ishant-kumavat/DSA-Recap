// LeetCode 4061 => ** Minimum Queen Moves to Reach Target **

// Optimal Solution => Chess Movement Properties
// Time Complexity : O(1)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];
        int tr = target[0];
        int tc = target[1];
        if(sr == tr && tc == sc) return 0;
        if(abs(sr - tr) == abs(tc - sc) || (sr == tr) || (sc == tc)) return 1;
        return 2;
    }
};

// A queen can move any number of squares
// horizontally, vertically, or diagonally.
//
// 0 moves:
// Source and target are the same.
//
// 1 move:
// The target is reachable in one queen move if:
// - Both positions are in the same row, OR
// - Both positions are in the same column, OR
// - Both positions lie on the same diagonal.
//
// Same diagonal condition:
// abs(sr - tr) == abs(sc - tc)
//
// Otherwise, the target can be reached in 2 moves.