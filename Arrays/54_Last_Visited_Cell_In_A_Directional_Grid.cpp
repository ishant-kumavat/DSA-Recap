// LeetCode 4084 => ** Last Visited Cell in a Directional Grid **

// Optimal Solution => Visited Matrix
// Time Complexity : O(n * m)
// Space Complexity : O(n * m)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int i = 0, j = 0;
        int p = 0, q = 0;

        while(i >= 0 && i < n && j >= 0 && j < m) {
            if(visited[i][j]) return {p, q};

            visited[i][j] = true;
            p = i;
            q = j;
             
            if(grid[i][j] == 'L') j--;
            else if(grid[i][j] == 'R') j++;
            else if(grid[i][j] == 'U') i--;
            else if(grid[i][j] == 'D') i++;
        }
        return {p, q};
    }
};

// Use a visited matrix to track cells
// that have already been visited.
//
// Start from cell (0, 0).
//
// Before processing a cell, check whether it
// has already been visited.
//
// If the cell is visited again, return the
// coordinates of the last visited cell.
//
// Otherwise, mark the current cell as visited
// and update `p` and `q` with its coordinates.
//
// Move in the direction specified by the cell:
// L -> Left, R -> Right,
// U -> Up, D -> Down.
//
// Stop when the current position goes outside
// the grid boundaries.
//
// Return the coordinates of the last visited cell.