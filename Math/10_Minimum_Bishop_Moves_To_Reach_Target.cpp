// LeetCode 4034 => ** Minimum Bishop Moves to Reach Target **

// Optimal Solution =>
// Time Complexity : O(1)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(source[0] == target[0] && source[1] == target[1]) return 0;
        if((source[0] + source[1]) % 2 != (target[0] + target[1]) % 2) return -1;
        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;
        return 2;
    }
};

// Bishop moves diagonally and always stays
// on the same color of the chessboard.
//
// Same position -> 0 moves.
//
// Different color -> impossible -> -1.
//
// Same diagonal -> 1 move.
//
// Same color but different diagonal -> 2 moves.